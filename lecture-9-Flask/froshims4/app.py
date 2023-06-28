# Implements a registration form, storing registrants in a SQLite database

from cs50 import SQL
from flask import Flask, redirect, render_template, request

# initialize Flask app
app = Flask(__name__)

# initialize SQL database and
db = SQL("sqlite:///froshims.db")

# initialize SPORTS global var as LIST
SPORTS = [
    "Soccer",
    "Basketball",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/deregister", methods=["POST"])
def deregister():
    # forget registrant
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")

@app.route("/register", methods=["POST"])
def register():
    # validate submission
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("failure.html")
    # remember registrant
    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)
    # confirm registration
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)

# execute Flask app?
# $ flask run