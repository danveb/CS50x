import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helper import apology, login_required, lookup, usd

# initialize Flask app
app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure db COINIST
db = SQL("sqlite:///coinist.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# index route
@app.route("/")
def index():
    """Display an introduction of our app"""
    return render_template("index.html")

# buy route
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of crypto coin"""
    if request.method == "POST":
        # get user input symbol, shares (request.form.get)
        symbol = request.form.get("symbol")
        shares = float(request.form.get("shares"))
        # print(shares)
        coin_symbol = lookup(symbol.upper())

        # check if symbol is invalid (longer than 4 chars) or coin_symbol does not return a valid coin
        if len(symbol) > 4 or coin_symbol == None or symbol == None:
            return apology("Coin symbol is invalid. Please limit to 4 characters max")
        # check if shares < 0 or shares is NOT integer
        if shares < 0 or not shares.is_integer():
            return apology("Please enter a valid number of share(s)")

        # look up current coin_symbol and get its price
        coin_price = float(coin_symbol["data"]["coins"][0]["price"])
        coin_shares = shares
        buy_transaction = coin_price * coin_shares

        # look up coin icon
        coin_icon = coin_symbol["data"]["coins"][0]["iconUrl"]

        # calculate user available cash balance for purchasing coins
        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]
        # print(user_cash)

        if user_cash < buy_transaction:
            return apology("Insufficient funds...")

        # execute buy_transaction and update_cash
        updated_cash = user_cash - buy_transaction
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updated_cash, user_id)

        # add transaction
        date = datetime.datetime.now()
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, icon, date) VALUES (?, ?, ?, ?, ?, ?)", user_id, symbol, shares, coin_price, coin_icon, date)

        # flash success message
        flash("Share(s) bought!")

        # redirect back to portfolio
        return redirect("/portfolio")

    else:
        return render_template("buy.html")

# quote route
@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get crypto coin quote"""
    if request.method == "POST":
        # get user input (request.form.get)
        symbol = request.form.get("symbol")
        coin_lookup = lookup(symbol.upper())
        # convert coin_lookup to object for easy data extraction
        coin_object = coin_lookup["data"]["coins"][0]
        coin_symbol = coin_object["symbol"]
        coin_name = coin_object["name"]
        coin_price = float(coin_object["price"])
        coin_icon = coin_object["iconUrl"]
        coin_marketCap = coin_object["marketCap"]
        coin_rank = coin_object["rank"]
        # check if symbol is invalid (longer than 4 characters)
        if len(symbol) > 4 or coin_symbol == None or symbol == None:
            return apology("Coin symbol is invalid. Please limit to 4 characters max")

        print(coin_lookup)
        return render_template("quoted.html", symbol=coin_symbol, name=coin_name, price=coin_price, icon=coin_icon, marketCap=coin_marketCap, rank=coin_rank)
    else:
        return render_template("quote.html")

# login route
@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # forget any user_id
    session.clear()

    if request.method == "POST":
        # get username/password from input field
        username = request.form.get("username")
        password = request.form.get("password")

        # check if username is submitted
        if not username:
            return apology("Must provide username", 403)
        # check if password is submitted
        elif not password:
            return apology("Must provide password", 403)

        # check db for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], password):
            return apology("Invalid username and/or password")

        # save user_id when logging-in
        session["user_id"] = rows[0]["id"]

        # redirect user to login
        return redirect("/portfolio")
    else:
        return render_template("login.html")

# logout route
@app.route("/logout")
def logout():
    """User log out"""
    # remove user from session
    session.clear()
    # redirect user back to login
    return redirect("/login")

# portfolio route
@app.route("/portfolio")
@login_required
def portfolio():
    """Show cryptocurrency portfolio"""
    # get user_id from session
    user_id = session["user_id"]
    # execute SQL command to get all transactions
    transactions_db = db.execute("SELECT symbol, SUM(shares) AS shares, price, icon FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)
    # execute SQL command to get user cash
    user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    # pass cash as USD
    user_cash = usd(user_cash_db[0]["cash"])
    return render_template("portfolio.html", transactions=transactions_db, cash=user_cash)

# register route
@app.route("/register", methods=["GET", "POST"])
def register():
    """Register new user"""
    if request.method == "POST":
        # get username, password, passwordConfirmation from input fields
        username = request.form.get("username")
        password = request.form.get("password")
        passwordConfirm = request.form.get("passwordConfirm")

        # check if users table is empty
        empty_username_db = db.execute("SELECT username FROM users")
        if len(empty_username_db) > 0:
            # we'll check if username exists on db
            username_db = db.execute("SELECT username FROM users")
            username_db = username_db[0]["username"]
            if username == username_db:
                return apology("Duplicate username; please create a new username")

        # check if password does NOT match passwordConfirm
        if password != passwordConfirm:
            return apology("Sorry, passwords don't match")

        # print(username, password, passwordConfirm)

        # execute SQL command to insert username, hashed password to db
        db.execute("INSERT into users (username, hash) VALUES (?, ?)", username, generate_password_hash(password))
        # query db for user info to add user to session
        user_id_db = db.execute("SELECT * FROM users WHERE username = ?", username)
        # register user_id to session with corresponding id
        session["user_id"] = user_id_db[0]["id"]

        # redirect user back to portfolio
        return redirect("/portfolio")
    else:
        return render_template("register.html")

# sell route
@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell coins"""
    if request.method == "POST":
        # get user input symbol, shares (request.form.get)
        symbol = request.form.get("symbol")
        shares = float(request.form.get("shares"))
        # print(shares, symbol)

        # check if shares < 0 or shares NOT integer or shares is a string
        if shares < 0 or not shares.is_integer() or type(shares) == str:
            return apology("Please enter a valid number of share(s) as an integer")

        # get user available shares
        user_id = session["user_id"]
        user_shares_db = db.execute("SELECT SUM(shares) AS shares FROM transactions WHERE user_id = :id AND symbol = :symbol", id=user_id, symbol=symbol)
        user_shares = user_shares_db[0]["shares"]

        # check if shares > user_shares
        if shares > user_shares:
            return apology("Sorry, you don't own enough shares :(")

        # get user available cash
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]

        # get latest coin price
        coin_lookup = lookup(symbol.upper())
        coin_price = float(coin_lookup["data"]["coins"][0]["price"])

        # get coin_icon
        coin_icon = coin_lookup["data"]["coins"][0]["iconUrl"]

        # calculate transaction to sell shares at specific price
        sell_transaction = shares * coin_price

        # update user cash after sell_transaction
        updated_cash = user_cash + sell_transaction
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updated_cash, user_id)

        # insert sell_transaction with date to db
        date = datetime.datetime.now()
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, icon, date) VALUES (?, ?, ?, ?, ?, ?)", user_id, symbol, shares * (-1), coin_price, coin_icon, date)

        # flash message when shares are sold
        flash("Share(s) sold!")

        # redirect user back portfolio
        return redirect("/portfolio")
    else:
        # get user_id
        user_id = session["user_id"]
        # get available coins from transactions
        coins_db = db.execute("SELECT * FROM transactions WHERE user_id = :id GROUP BY symbol HAVING SUM(shares) > 0", id=user_id)
        # print(coins_db)
        return render_template("sell.html", coins=coins_db)

# transaction_history
@app.route("/history")
@login_required
def transaction_history():
    """Display history of all transactions"""
    # get user_id
    user_id = session["user_id"]
    # execute SQL command to gather transactions
    transactions_db = db.execute("SELECT symbol, SUM(shares) AS shares, price, icon, date FROM transactions WHERE user_id = ? GROUP BY date", user_id)
    return render_template("history.html", transactions=transactions_db)
