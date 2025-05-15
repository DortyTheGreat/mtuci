from airflow import DAG
from airflow.operators.dummy_operator import DummyOperator
from airflow.operators.bash_operator import BashOperator
from airflow.operators.python_operator import PythonOperator
from airflow.utils.dates import days_ago
from datetime import datetime, timedelta


def print_date():
        print('Current date: ', datetime.now())

default_args = {
        'owner': 'kuleshov_bei-22-2',
        'start_date': days_ago(2),
        'poke_interval': 600
}

dag = DAG(
        'kuleshov_bei-22-2',
        default_args=default_args,
        description='A DAG with Dummy, Bash and Python operators',
        schedule_interval=timedelta(days=1),
)

start_task = DummyOperator(task_id='start_task', dag=dag)

bash_task = BashOperator(
        task_id='bash_task',
        bash_command='date',
        dag=dag
)

python_task = PythonOperator(
        task_id='python_task',
        python_callable=print_date,
        dag=dag
)

start_task >> bash_task >> python_task