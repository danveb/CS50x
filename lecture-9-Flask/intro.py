# Flask
# third-party library that allows to host web apps using Flask framework within Python
# we combine with Jinja, not a framework, that allows to use "placeholders" to write code

# sample project
# - app.py
# - requirements.txt
# - static/
# - templates/

# sample app.py
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

# we can avoid repetition of templates by using a "layout" in templates directory

# request.args.get -> GET method only
# request.form.get -> POST method only

# be careful with Flask/Jinja templating on Forms because it's vulnerable to malicious "injection"

# Session
# implement cookies, small files stored on computer, so that we can authorize user for log in

# API
# application program interface
# allows to interact with another web-based service, like WeatherAPI, IMDB API, etc.

