import os
import requests

from flask import redirect, render_template, session
from functools import wraps
from dotenv import load_dotenv

# load environment variables from .env
load_dotenv()

# access API KEY with os module
api_key = os.environ.get("API_KEY")

def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    http://flask.pocoo.org/docs/0.12/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function

def lookup(crypto_symbol):
    """Look up quote for crypto coin"""

    # prepare Coinranking API request
    crypto_symbol = crypto_symbol.upper()
    url = "https://coinranking1.p.rapidapi.com/coins"
    querystring = {f"referenceCurrencyUuid":"yhjMzLPhuIDl","timePeriod":"24h","symbols[0]":{crypto_symbol},"tiers[0]":"1","orderBy":"marketCap","orderDirection":"desc","limit":"50","offset":"0"}
    headers = {
        "X-RapidAPI-Key": api_key,
        "X-RapidAPI-Host": "coinranking1.p.rapidapi.com"
    }
    response = requests.get(url, headers=headers, params=querystring)
    return response.json()

    # print(lookup("BTC"))
    # {'status': 'success', 'data': {'stats': {'total': 1, 'totalCoins': 26954, 'totalMarkets': 36550, 'totalExchanges': 161, 'totalMarketCap': '1240830832607', 'total24hVolume': '46062420943'}, 'coins': [{'uuid': 'Qwsogvtv82FCd', 'symbol': 'BTC', 'name': 'Bitcoin', 'color': '#f7931A', 'iconUrl': 'https://cdn.coinranking.com/bOabBYkcX/bitcoin_btc.svg', 'marketCap': '604129816819', 'price': '31110.05437109256', 'listedAt': 1330214400, 'tier': 1, 'change': '1.73', 'rank': 1, 'sparkline': ['30582.87298194887', '30598.22412970363', '30582.155786712534', '30634.91248144843', '30652.934510775238', '30717.012573317694', '30768.75781603549', '30740.223924167723', '30696.16274184391', '30670.552918671998', '30657.165149647393', '30658.47528334048', '30664.056931455674', '30641.881384600565', '30640.365812954624', '30586.534718092178', '30573.058363544045', '30697.286488443104', '30968.960783957806', '31008.15414961739', '31047.600142482377', '31132.804196783905', '31256.399555778637', '31209.784908337515'], 'lowVolume': False, 'coinrankingUrl': 'https://coinranking.com/coin/Qwsogvtv82FCd+bitcoin-btc', '24hVolume': '14119549123', 'btcPrice': '1'}]}}

    # coin_request = lookup("BTC")
    # coin_symbol = coin_request["data"]["coins"][0]["symbol"]
    # coin_name = coin_request["data"]["coins"][0]["name"]
    # coin_price = coin_request["data"]["coins"][0]["price"]


def usd(value):
    """Format value as USD."""
    return f"${value:,.2f}"