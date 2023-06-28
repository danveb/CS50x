import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # get user_id for specific info on portfolio
    user_id = session["user_id"]
    # execute SQL to get symbol, sum of shares, price from "transactions" table
    # make sure to group by symbol, shares and price so we have each line separate even though user can buy multiple stocks at different prices
    transactions_db = db.execute("SELECT symbol, SUM(shares) AS shares, price FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)
    # execute SQL to get cash from "users" table
    user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    # extract cash from db and pass as "USD"
    user_cash = usd(user_cash_db[0]["cash"])
    # print(cash)
    return render_template("index.html", transactions=transactions_db, cash=user_cash)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # grab user input symbol, shares from formData (request.form.get)
        symbol = request.form.get("symbol")
        shares = float(request.form.get("shares"))
        print(shares)
        stock_symbol = lookup(symbol.upper())
        # check: if symbol is invalid (longer or shorter than 4 chars) or symbol does not return a valid sticker? return an apology
        if len(symbol) > 5 or stock_symbol == None or symbol == None:
            return apology("Stock symbol is invalid. Please limit to 4 characters.")
        # check: if shares < 0 or shares is NOT integer? throw error
        if shares < 0 or not shares.is_integer():
            return apology("Please enter a valid number of share(s)")

        # stock_symbol
        # stock_symbol = lookup(symbol.upper())
        stock_price = lookup(symbol.upper())["price"]
        stock_shares = shares
        buy_transaction = stock_price * stock_shares # price * 150 shares

        # calculate user's available cash balance for purchasing stock
        # grab user_id from session object
        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]

        if user_cash < buy_transaction:
            return apology("Insufficient funds...")

        # else we will update user cash on db
        updated_cash = user_cash - buy_transaction
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updated_cash, user_id)

        # insert transaction into transactions table
        date = datetime.datetime.now()
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)", user_id, symbol, shares, stock_price, date)
        # flash message when buying shares
        flash("Share(s) bought!")
        # redirect back to index
        return redirect("/")
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # get user_id
    user_id = session["user_id"]
    # execute SQL command to get symbol, sum of shares, price, date from "transactions" table; group by date (chronological order)
    transactions_db = db.execute("SELECT symbol, SUM(shares) AS shares, price, date FROM transactions WHERE user_id = ? GROUP BY date", user_id)
    # print(transactions_db)
    # [{'symbol': 'NFLX', 'shares': 1, 'price': 417.08, 'date': '2023-06-27 23:52:10'}, {'symbol': 'TSLA', 'shares': 15, 'price': 250.21, 'date': '2023-06-27 23:52:19'}, {'symbol': 'NFLX', 'shares': -1, 'price': 417.08, 'date': '2023-06-27 23:52:38'}, {'symbol': 'TSLA', 'shares': -15, 'price': 250.21, 'date': '2023-06-27 23:53:08'}, {'symbol': 'NVDA', 'shares': 11, 'price': 418.76, 'date': '2023-06-27 23:54:27'}, {'symbol': 'NVDA', 'shares': -11, 'price': 418.76, 'date': '2023-06-27 23:54:39'}, {'symbol': 'TSLA', 'shares': 10, 'price': 250.21, 'date': '2023-06-27 23:55:20'}, {'symbol': 'TSLA', 'shares': -5, 'price': 250.21, 'date': '2023-06-27 23:55:27'}, {'symbol': 'TSLA', 'shares': -4, 'price': 250.21, 'date': '2023-06-27 23:56:51'}]
    return render_template("history.html", transactions=transactions_db)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        # grab symbol from POST formData (request.form.get)
        symbol = request.form.get("symbol")
        # manage symbol to be input as lowercase or uppercase
        result = lookup(symbol.upper())
        # print(result) {'name': 'TSLA', 'price': 256.13, 'symbol': 'TSLA'}
        # check: if symbol is invalid (longer or shorter than 4 chars)? return an apology
        if len(symbol) > 5 or result == None:
            return apology("Stock symbol is invalid. Please limit to 4 characters.")
        # else... we can render quoted.html
        return render_template("quoted.html", result=result)
    else:
        return render_template("quote.html")
    # return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # grab username, password, confirm from POST formData (request.form.get)
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        # check: if username already exists in db? return an apology
        username_db = db.execute("SELECT username FROM users")
        username_db = username_db[0]["username"]
        if username == username_db:
            return apology("You entered a duplicate username; please create a new username")
        # check: if username or password or confirmation inputs are empty? return apology
        if username == "" or password == "" or confirmation == "":
            return apology("Please add all fields before registering")
        # check: if password does NOT match confirmation password? return an apology
        if password != confirmation:
            return apology("Sorry passwords don't match")
        # print(username, password)
        # execute SQL command to insert username, hash to db
        # pass generate_password_hash to password here
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, generate_password_hash(password))
        # query database for user so we can add user to the session
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        session["user_id"] = rows[0]["id"]
        # redirect user back to index
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        # grab symbol and shares from form data (request.form.get)
        symbol = request.form.get("symbol")
        shares = float(request.form.get("shares"))
        # check: if shares < 0 or shares NOT integer or shares is a string?
        if shares < 0 or not shares.is_integer() or type(shares) == str:
            return apology("Please enter a valid number of share(s) as an integer")

        # get user's available shares
        user_id = session["user_id"]
        user_shares_db = db.execute("SELECT SUM(shares) AS shares FROM transactions WHERE user_id = :id AND symbol = :symbol", id=user_id, symbol=symbol)
        user_shares = user_shares_db[0]["shares"]
        # check: if shares > user_shares? throw error
        if shares > user_shares:
            return apology("Sorry, not enough shares :(")

        # get user's cash balance before transaction
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]

        # calculate updated stock price and transaction to sell shares
        stock_price = lookup(symbol)["price"]
        sell_transaction = shares * stock_price

        # update user's cash after transaction
        # update SQL
        updated_cash = user_cash + sell_transaction
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updated_cash, user_id)

        # insert sell_transaction with date
        date = datetime.datetime.now()
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)", user_id, symbol, shares * (-1), stock_price, date)
        # flash message when shares are sold
        flash("Share(s) sold!")
        # redirect user back to homepage
        return redirect("/")
    else:
        # get user_id from session
        user_id = session["user_id"]
        # get available_stocks from db
        available_stocks = db.execute("SELECT * FROM transactions WHERE user_id = :id GROUP BY symbol HAVING SUM(shares) > 0", id=user_id)
        print(available_stocks)
        # [{'id': 3, 'user_id': 4, 'symbol': 'NFLX', 'shares': 15, 'price': 419.69, 'date': '2023-06-27 11:23:50'}, {'id': 1, 'user_id': 4, 'symbol': 'TSLA', 'shares': 1, 'price': 241.05, 'date': '2023-06-26 21:02:48'}, {'id': 2, 'user_id': 4, 'symbol': 'TSLA', 'shares': 5, 'price': 248.38, 'date': '2023-06-27 10:46:37'}]
        return render_template("sell.html", stocks=available_stocks)