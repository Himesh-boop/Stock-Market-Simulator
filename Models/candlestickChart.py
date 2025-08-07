import requests
import pandas as pd
from datetime import datetime
import sys
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
                continue

        print(f"Successfully processed {len(records)} records", file=sys.stderr)

        if not records:
            print("No valid records found", file=sys.stderr)
            return None

        df = pd.DataFrame(records)
        df = df.sort_values(by='date')
        df.reset_index(drop=True, inplace=True)
        print(f"DataFrame created with {len(df)} rows", file=sys.stderr)
        
        return df

    except Exception as e:
        print(f"Exception in get_historical_data: {e}", file=sys.stderr)
        return None

def generate_chart(symbol):
    print(f"Generating chart for symbol: {symbol}", file=sys.stderr)
    df = get_historical_data(symbol.upper())

    if df is None:
        print("get_historical_data returned None", file=sys.stderr)
        return None

    if df.empty:
        print("DataFrame is empty", file=sys.stderr)
        return None

    print(f"DataFrame shape: {df.shape}", file=sys.stderr)

    chart_data = []
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
            chart_data.append(point)
            
        except Exception as e:
            print(f"Error processing row {i}: {e}", file=sys.stderr)
            continue

    print(f"Generated {len(chart_data)} data points", file=sys.stderr)
    
    return chart_data

if __name__ == '__main__':
    symbol = sys.argv[1] if len(sys.argv) > 1 else 'NABIL'

    print(f"Starting script with symbol: {symbol}", file=sys.stderr)
    print("Python candlestick chart script is running", file=sys.stderr)

    result = generate_chart(symbol)

    if result:
        print(f"Result has {len(result)} items", file=sys.stderr)
        print(json.dumps(result, indent=2))
        print("Successfully generated candlestick chart data", file=sys.stderr)
    else:
        print("Result is None or empty", file=sys.stderr)
        print("[]")
        print("Failed to generate candlestick chart data", file=sys.stderr)