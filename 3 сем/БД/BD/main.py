import sqlite3
from flask import g

DATABASE = 'kurs_bd.db'

from flask import Flask, render_template, request,jsonify,json,g
from flask_socketio import SocketIO, emit
from flask import flash

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)



@app.route('/')
def index():
    return render_template('index.html')

@app.route('/portfolio')
def portfolio():
    return render_template('portfolio.html')

@app.route('/contacts')
def contacts():
    return render_template('contacts.html')

@app.route('/about')
def about():
    return render_template('about.html')

@app.route('/price')
def price():
    return render_template('price.html')

@app.route('/map')
def map():
    return render_template('map.html')

@app.route('/lk', methods=['GET', 'POST'])
def lk():

    if request.method == 'GET':
        return render_template('lk.html')

    if (request.form.__contains__('username_login')):
        # login

        res = run_script_get(f"SELECT * FROM users WHERE login={request.form['username_login']}")
        print(res)

        if len(res) == 0:
            flash('Такого пользователя нет в ДБ', 'error')
            return render_template('lk.html')

        pass

    if (request.form.__contains__('username_register')):
        # register

        res = run_script_get(f"SELECT * FROM users WHERE login='{request.form['username_register']}'")
        print(res)

        if len(res) != 0:
            print('none')
            flash('Такой пользователь уже есть в ДБ. Выберите другой логин', 'error')
            return render_template('lk.html')


        req_str = f"""INSERT INTO users (login, password)\nVALUES ({request.form['username_register']}, {request.form['pwd']})"""
        print(req_str)
        res = run_script_write(f"""INSERT INTO users (login, password)\n
        VALUES ('{request.form['username_register']}', '{request.form['pwd']}')""")

        print(res)

        res = run_script_get(f"SELECT * FROM users WHERE login='{request.form['username_register']}'")
        print(res)


    return render_template('lk.html')


def get_db():



    db = getattr(g, '_database', None)
    if db is None:
        db = g._database = sqlite3.connect(DATABASE)
    return db


def run_txt_script(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        contents = file.read()
        with app.app_context():
            get_db().executescript(contents)

def run_script_get(strin):
    with app.app_context():
        return get_db().execute(strin).fetchall()

def run_script_write(strin):
    with app.app_context():
        return get_db().executescript(strin).fetchall()

def super_clear_db():
    with open(DATABASE, 'w', encoding='utf-8') as file:
        file.truncate(0)


super_clear_db()
run_txt_script("create_dbs.txt")
run_txt_script("test_add_some.txt")

print(run_script_get(f"SELECT * FROM users"))

@app.teardown_appcontext
def close_connection(exception):
    db = getattr(g, '_database', None)
    if db is not None:
        db.close()


if __name__ == '__main__':
    socketio.run(app, debug=True,allow_unsafe_werkzeug=True)