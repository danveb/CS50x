from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# initialize Flask app
app = Flask(__name__)

# connect to db
db = SQL("sqlite:///store.db")

# configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# index route
@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    # print(books) -> prints  [{}] from which we can iterate and use its "id", "title"
    # [{'id': 1, 'title': "Harry Potter and the Sorcerer's Stone"}, {'id': 2, 'title': 'Harry Potter and the Chamber of Secrets'}, {'id': 3, 'title': 'Harry Potter and the Prisoner of Azkaban'}, {'id': 4, 'title': 'Harry Potter and the Goblet of Fire'}, {'id': 5, 'title': 'Harry Potter and the Order of the Phoenix'}, {'id': 6, 'title': 'Harry Potter and the Half-Blood Prince'}, {'id': 7, 'title': 'Harry Potter and the Deathly Hallows'}]
    return render_template("books.html", books=books)

# cart route; takes methods GET/POST
@app.route("/cart", methods=["GET", "POST"])
def cart():
    # ensure cart exists
    if "cart" not in session:
      session["cart"] = []
    # POST
    if request.method == "POST":
       id = request.form.get("id")
       if id:
          session["cart"].append(id)
       return redirect("/cart")
    # GET
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)
