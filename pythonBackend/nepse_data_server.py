# nepse_data_server.py
from flask import Flask, jsonify
import requests
from bs4 import BeautifulSoup

app = Flask(__name__)

def fetch_stock_price(symbol):
    url = f"https://merolagani.com/CompanyDetail.aspx?symbol={symbol}"
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
    }
    response = requests.get(url, headers=headers)
    if response.status_code != 200:
        print("DEBUG: Request failed with status", response.status_code)
        return None

    soup = BeautifulSoup(response.text, 'html.parser')
    price_tag = soup.find('span', {'id': 'ctl00_ContentPlaceHolder1_CompanyDetail1_lblMarketPrice'})

    # This selector may need adjustment
    print("DEBUG: Fetched HTML -", price_tag)   
    if price_tag:
        price_str = price_tag.text.strip().replace(',', '')
        try:
            price = float(price_str)
            return price
        except:
            return None
    return None

@app.route('/price/<symbol>')
def get_price(symbol):
    price = fetch_stock_price(symbol.upper())
    if price is not None:
        return jsonify({"symbol": symbol.upper(), "price": price})
    else:
        return jsonify({"error": "Stock symbol not found"}), 404

if __name__ == '__main__':
    app.run(port=5000)
