import sqlite3
from flask import g

DATABASE = 'kurs_bd.db'

from flask import Flask, render_template, request,jsonify,json,g
from flask_socketio import SocketIO, emit
from flask import flash
from flask import session
from flask import redirect
from flask import url_for

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)



@app.route('/')
def index():
    return render_template('index.html')

@app.route('/logout')
def logout():
    session.pop('username')
    return redirect(url_for('lk'))

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
def lk(method='any', get_matr = -1):

    if request.method == 'GET' or method == 'get':
        user_logged = False
        loginname = "Unknown"
        res = [(-1,-1,-1,-1,-1,-1,-1)]
        res_projects = []
        user_id = 0
        if 'username' in session:
            loginname = session['username']
            user_logged = True
            res = run_script_get(f"SELECT * FROM users WHERE login='{loginname}'")

            user_id = run_script_get(f"SELECT id FROM users WHERE login='{loginname}'")[0][0]
            res_projects = run_script_get(f"SELECT * FROM projects WHERE user_id='{user_id}'")
        #
        if len(res) == 0:
            session.pop('username')
            return lk('get')

        print(user_id, res_projects)

        lenX = -1
        lenY = -1
        try:
            if (get_matr != -1):
                lenX = len(get_matr)
                lenY = len(get_matr[0])
        except:
            lenX = -1
            lenY = -1

        print(res)
        print(get_matr)
        print(lenX, lenY)
        return render_template('lk.html', user_logged=user_logged, login=loginname, email=res[0][2],
                               name= res[0][1], status = res[0][5], proj_table = res_projects, pt_len = len(res_projects),
                               get_matr = get_matr, lenX = lenX, lenY = lenY)


    if (request.form.__contains__('name_change')):
        res = run_script_write(
            f"UPDATE users SET name = '{request.form['name_change']}' WHERE login='{session['username']}' ")

    if (request.form.__contains__('email_change')):
        res = run_script_write(
            f"UPDATE users SET email = '{request.form['email_change']}' WHERE login='{session['username']}' ")

    if (request.form.__contains__('write')):
        print(request.form['sql'])
        res = run_script_write(request.form['sql'])

    if (request.form.__contains__('get')):
        print(request.form['sql'])
        res = run_script_get(request.form['sql'])
        return lk('get', res)

    if (request.form.__contains__('submit_login')):
        # login

        res = run_script_get(f"SELECT * FROM users WHERE login='{request.form['username']}' AND password = '{request.form['pwd']}'")
        print(res)

        if len(res) == 0:
            flash('Неверный пароль или логин', 'error')
            return lk('get')


        flash('Вы были успешно авторизированы')
        session['username'] = request.form['username']

    if (request.form.__contains__('submit_register')):
        # register

        res = run_script_get(f"SELECT * FROM users WHERE login='{request.form['username']}'")
        print(res)

        if len(res) != 0:
            flash('Такой пользователь уже есть в ДБ. Выберите другой логин', 'error')
            return render_template('lk.html')


        req_str = f"""INSERT INTO users (login, password)\nVALUES ({request.form['username']}, {request.form['pwd']})"""
        print(req_str)
        res = run_script_write(f"""INSERT INTO users (login, password, status)\n
        VALUES ('{request.form['username']}', '{request.form['pwd']}', 'user')""")

        session['username'] = request.form['username']
        flash('Вы были успешно зарегестрированы')



    return lk('get')


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