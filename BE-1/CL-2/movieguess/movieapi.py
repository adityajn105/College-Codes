from flask import Flask
app = Flask(__name__)

@app.route('/getmovie')
def index():
	fp=open("movies.sample.json","r")
	return fp.read()

if __name__ == '__main__':
    app.run(debug=True)
