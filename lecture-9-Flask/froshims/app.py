from flask import Flask, render_template, request

# initialize Flask app
app = Flask(__name__)

# global vars
# initialize a new dictionary
REGISTRANTS = {}

# initialize SPORTS list
SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

# initialize "/" route
@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

# initialize /register
# require methods=["POST"]
@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    if not name:
        return render_template("failure.html")
    sport = request.form.get("sport")
    if sport not in SPORTS:
        return render_template("failure.html")
    REGISTRANTS[name] = sport
    return render_template("success.html")

@app.route("/registrants")
def registrants():
    # pass registrants dictionary to output on app
    return render_template("registrants.html", registrants=REGISTRANTS)

# execute Flask app
# $ flask run