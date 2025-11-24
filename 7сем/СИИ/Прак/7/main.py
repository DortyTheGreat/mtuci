'''
16 вариант -> 8 вариант
'''

import numpy as np
import math
import random
import matplotlib.pyplot as plt
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, Dense
from tensorflow.keras.optimizers import Adam



def func(i):
    return ((i % 20) + 1) / 20

def gen_sequence(seq_len=1000):
    seq = [abs(math.sin(i/20)) + func(i) + random.normalvariate(0, 0.04)
           for i in range(seq_len)]
    return np.array(seq)

def draw_sequence():
    seq = gen_sequence(250)
    plt.plot(range(len(seq)), seq)
    plt.show()




def gen_data_from_sequence(sequence, window=20):
    X, y = [], []
    for i in range(len(sequence) - window):
        X.append(sequence[i:i + window])
        y.append(sequence[i + window])
    X = np.array(X)
    y = np.array(y)
    return X, y




seq = gen_sequence(2000)

WINDOW = 20
X, y = gen_data_from_sequence(seq, WINDOW)

# Нормализация
mean = X.mean()
std = X.std()
X = (X - mean) / std
y = (y - mean) / std

X = np.expand_dims(X, axis=2)   



train_size = int(len(X) * 0.7)
val_size = int(len(X) * 0.15)

X_train = X[:train_size]
y_train = y[:train_size]

X_val = X[train_size:train_size+val_size]
y_val = y[train_size:train_size+val_size]

X_test = X[train_size+val_size:]
y_test = y[train_size+val_size:]







model = Sequential([
    LSTM(32, return_sequences=False, input_shape=(WINDOW, 1)),
    Dense(1)
])

model.compile(optimizer=Adam(0.001), loss='mse')
model.summary()





history = model.fit(
    X_train, y_train,
    epochs=20,
    batch_size=32,
    validation_data=(X_val, y_val),
    verbose=1
)






y_pred = model.predict(X_test)


y_pred_denorm = y_pred * std + mean
y_test_denorm = y_test * std + mean





# Plotting...
plt.figure(figsize=(12, 5))
plt.plot(y_test_denorm, label="Real")
plt.plot(y_pred_denorm, label="Predicted")
plt.legend()
plt.title("Prediction on Test Sequence")
plt.show()
