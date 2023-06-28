from flask import Flask, render_template, request

# initialize app
app = Flask(__name__)

# #1
# # initialize default index page
# @app.route("/")
# def index():
#     # pass request.args.get("name_of_var", and "default_value")
#     name = request.args.get("name", "world")
#     return render_template("index.html", name=name)

# @app.route("/")
# def index():
#     return render_template("index.html")

# @app.route("/greet")
# def greet():
#     # define name to be used as 2nd param on return
#     # name = request.args.get("name", "world")
#     return render_template("greet.html", name=request.args.get("name", "world"))

# by default it uses "GET" method, but if needed we can add methods=["POST"]
# @app.route("/greet", methods=["POST"])
# def greet():
#     # define name to be used as 2nd param on return
#     # name = request.args.get("name", "world")
#     return render_template("greet.html", name=request.args.get("name", "world"))

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        # request.args only works with GET requests
        # for POST requests we need request.form
        return render_template("greet.html", name=request.form.get("name", "world"))

# execute app.py
# $ flask run