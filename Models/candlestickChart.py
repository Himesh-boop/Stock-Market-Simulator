import requests
import pandas as pd
from datetime import datetime

def get_historical_data(symbol):
    url = f"http://merolagani.com/handlers/webrequesthandler.ashx?type=get_company_graph&symbol={symbol}&dateRange=12"
    response = requests.get(url)
    if response.status_code != 200:
        print("❌ Error fetching data")
        return None

    data = response.json()
    if 'quotes' not in data:
        print("❌ No data found in response")
        return None

    records = []
    for entry in data['quotes']:
        try:
            date = datetime.strptime(entry['date'], "%m/%d/%Y")
            open_price = float(entry['open'])
            high = float(entry['high'])
            low = float(entry['low'])
            close = float(entry['close'])
            volume = float(entry['volume'])
            records.append({
                'Date': date,
                'Open': open_price,
                'High': high,
                'Low': low,
                'Close': close,
                'Volume': volume
            })
        except Exception as e:
            print(f"Skipping entry due to error: {e}")
            continue

    if not records:
        print("❌ No valid records found")
        return None

    df = pd.DataFrame(records)
    df.set_index('Date', inplace=True)
    return df.sort_index()

def generate_chart(symbol):
    df = get_historical_data(symbol.upper())
    if df is None or df.empty:
        print("❌ No data to plot")
        return None
    # Convert DataFrame to JSON string for easy parsing in C++
    return df

if __name__ == '__main__':
    import sys
    symbol = sys.argv[1] if len(sys.argv) > 1 else 'NABIL'  # default symbol if none passed
    df = generate_chart(symbol)
    if df is not None:
        json_str = df.reset_index().to_json(orient='records', date_format='iso')
        print(json_str)
    else:
        # Print nothing or an error JSON (optional)
        print("[]")  # empty list JSON if no data

