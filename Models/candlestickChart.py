import requests
import pandas as pd
from datetime import datetime
import sys
import pandas_ta as ta
import json

def get_historical_data(symbol):
    print(f"Fetching data for symbol: {symbol}", file=sys.stderr)
    url = f"http://merolagani.com/handlers/webrequesthandler.ashx?type=get_company_graph&symbol={symbol}&dateRange=12"
    print(f"URL: {url}", file=sys.stderr)

    try:
        response = requests.get(url)
        print(f"Response status code: {response.status_code}", file=sys.stderr)

        if response.status_code != 200:
            print("Error fetching data", file=sys.stderr)
            return None

        data = response.json()
        print(f"Response keys: {list(data.keys()) if isinstance(data, dict) else 'Not a dict'}", file=sys.stderr)

        if 'quotes' not in data:
            print("No data found in response", file=sys.stderr)
            print(f"Available keys: {list(data.keys()) if isinstance(data, dict) else 'No keys'}", file=sys.stderr)
            return None

        print(f"Number of quotes found: {len(data['quotes'])}", file=sys.stderr)

        records = []
        for i, entry in enumerate(data['quotes']):
            try:
                print(f"Processing entry {i}: {entry}", file=sys.stderr)
                date = datetime.strptime(entry['date'], "%m/%d/%Y")
                open_price = float(entry['open'])
                high = float(entry['high'])
                low = float(entry['low'])
                close = float(entry['close'])
                volume = float(entry['volume'])
                records.append({
                    'date': date,
                    'open': open_price,
                    'high': high,
                    'low': low,
                    'close': close,
                    'volume': volume
                })
            except Exception as e:
                print(f"Skipping entry {i} due to error: {e}", file=sys.stderr)
                print(f"Entry data: {entry}", file=sys.stderr)
                continue

        print(f"Successfully processed {len(records)} records", file=sys.stderr)

        if not records:
            print("No valid records found", file=sys.stderr)
            return None

        df = pd.DataFrame(records)
        df = df.sort_values(by='date')
        df.reset_index(drop=True, inplace=True)
        print(f"DataFrame created with {len(df)} rows", file=sys.stderr)
        
        # Print first few rows to verify data
        print(f"First 5 rows of DataFrame:", file=sys.stderr)
        print(df.head().to_string(), file=sys.stderr)
        
        return df

    except Exception as e:
        print(f"Exception in get_historical_data: {e}", file=sys.stderr)
        return None

def calculate_indicator(df, indicator):
    print(f"Calculating indicator: {indicator}", file=sys.stderr)
    print(f"DataFrame shape before indicator calculation: {df.shape}", file=sys.stderr)
    
    try:
        if indicator == "RSI":
            df["RSI"] = ta.rsi(df["close"], length=14)
            print(f"RSI calculation completed. Non-null values: {df['RSI'].notna().sum()}", file=sys.stderr)
            print(f"RSI sample values: {df['RSI'].dropna().head().tolist()}", file=sys.stderr)
            
        elif indicator == "MACD":
            macd = ta.macd(df["close"])
            if macd is not None:
                df["MACD"] = macd["MACD_12_26_9"]
                df["MACD_signal"] = macd["MACDs_12_26_9"]
                df["MACD_hist"] = macd["MACDh_12_26_9"]
                print(f"MACD calculation completed. Non-null MACD values: {df['MACD'].notna().sum()}", file=sys.stderr)
                print(f"MACD sample values: {df['MACD'].dropna().head().tolist()}", file=sys.stderr)
            else:
                print("MACD calculation returned None", file=sys.stderr)
                
        elif indicator == "Moving Average":
            df["Moving_Average"] = df["close"].rolling(window=14).mean()
            print(f"Moving Average calculation completed. Non-null values: {df['Moving_Average'].notna().sum()}", file=sys.stderr)
            print(f"Moving Average sample values: {df['Moving_Average'].dropna().head().tolist()}", file=sys.stderr)
            
        elif indicator == "Bollinger Bands":
            bb = ta.bbands(df["close"])
            if bb is not None:
                df["BB_upper"] = bb["BBU_20_2.0"]
                df["BB_middle"] = bb["BBM_20_2.0"]
                df["BB_lower"] = bb["BBL_20_2.0"]
                print(f"Bollinger Bands calculation completed. Non-null upper values: {df['BB_upper'].notna().sum()}", file=sys.stderr)
                print(f"BB Upper sample values: {df['BB_upper'].dropna().head().tolist()}", file=sys.stderr)
            else:
                print("Bollinger Bands calculation returned None", file=sys.stderr)
                
        elif indicator == "CCI":
            df["CCI"] = ta.cci(df["high"], df["low"], df["close"])
            print(f"CCI calculation completed. Non-null values: {df['CCI'].notna().sum()}", file=sys.stderr)
            print(f"CCI sample values: {df['CCI'].dropna().head().tolist()}", file=sys.stderr)
            
        elif indicator == "Stochastic":
            stoch = ta.stoch(df["high"], df["low"], df["close"])
            if stoch is not None:
                df["Stochastic_K"] = stoch["STOCHk_14_3_3"]
                df["Stochastic_D"] = stoch["STOCHd_14_3_3"]
                print(f"Stochastic calculation completed. Non-null K values: {df['Stochastic_K'].notna().sum()}", file=sys.stderr)
                print(f"Stochastic K sample values: {df['Stochastic_K'].dropna().head().tolist()}", file=sys.stderr)
            else:
                print("Stochastic calculation returned None", file=sys.stderr)
                
        elif indicator == "Williams %R":
            df["Williams_R"] = ta.willr(df["high"], df["low"], df["close"])
            print(f"Williams %R calculation completed. Non-null values: {df['Williams_R'].notna().sum()}", file=sys.stderr)
            print(f"Williams %R sample values: {df['Williams_R'].dropna().head().tolist()}", file=sys.stderr)
            
        print(f"DataFrame columns after indicator calculation: {df.columns.tolist()}", file=sys.stderr)
        print(f"DataFrame shape after indicator calculation: {df.shape}", file=sys.stderr)
        
        return df
        
    except Exception as e:
        print(f"Error calculating indicator {indicator}: {e}", file=sys.stderr)
        import traceback
        print(f"Traceback: {traceback.format_exc()}", file=sys.stderr)
        return df

def generate_chart(symbol, indicator):
    print(f"Generating chart for symbol: {symbol}, indicator: {indicator}", file=sys.stderr)
    df = get_historical_data(symbol.upper())

    if df is None:
        print("get_historical_data returned None", file=sys.stderr)
        return None

    if df.empty:
        print("DataFrame is empty", file=sys.stderr)
        return None

    print(f"DataFrame shape: {df.shape}", file=sys.stderr)

    if indicator != "None":
        df = calculate_indicator(df, indicator)

    enriched_data = []
    for i, (_, row) in enumerate(df.iterrows()):
        try:
            point = {
                "date": row["date"].strftime("%Y-%m-%dT00:00:00.000"),
                "open": float(row["open"]),
                "high": float(row["high"]),
                "low": float(row["low"]),
                "close": float(row["close"]),
                "volume": float(row["volume"])
            }

            indicator_columns = [
                "RSI", "MACD", "MACD_signal", "MACD_hist",
                "Moving_Average", "BB_upper", "BB_middle", "BB_lower",
                "CCI", "Stochastic_K", "Stochastic_D", "Williams_R"
            ]
            
            for col in indicator_columns:
                if col in row and pd.notna(row[col]):
                    point[col] = float(row[col])

            enriched_data.append(point)
            
        except Exception as e:
            print(f"Error processing row {i}: {e}", file=sys.stderr)
            continue

    print(f"Generated {len(enriched_data)} data points", file=sys.stderr)
    
    # Print sample of enriched data to verify indicators are included
    if enriched_data:
        print(f"Sample enriched data point: {enriched_data[-1]}", file=sys.stderr)
        
    return enriched_data

if __name__ == '__main__':
    symbol = sys.argv[1] if len(sys.argv) > 1 else 'NABIL'
    indicator = sys.argv[2] if len(sys.argv) > 2 else 'None'

    print(f"Starting script with symbol: {symbol}, indicator: {indicator}", file=sys.stderr)
    print("Python file is running", file=sys.stderr)

    result = generate_chart(symbol, indicator)

    if result:
        print(f"Result has {len(result)} items", file=sys.stderr)
        print(json.dumps(result, indent=2))
        print("Successfully generated chart data with indicators", file=sys.stderr)
    else:
        print("Result is None or empty", file=sys.stderr)
        print("[]")
        print("Python file failed to generate result", file=sys.stderr)
