from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# initialize Flask app
app = Flask(__name__)

# configure session
app.config["SESSION_PERMAMENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# index() function
@app.route("/")
def index():
    # error check: if "name" is not in session we'll redirect back to login
    if not session.get("name"):
        return redirect("/login")
    # returns index page
    return render_template("index.html")

# login() function
@app.route("/login", methods=["GET", "POST"])
def login():
    # check: if method is POST we'll store "name" key and user's value in session
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    # if GET request we render login page
    return render_template("login.html")

# logout() function
@app.route("/logout")
def logout():
    session["name"] = None
    return redirect("/")

# execute Flask app
# $ flask run