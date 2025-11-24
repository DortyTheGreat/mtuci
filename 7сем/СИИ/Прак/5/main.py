'''
Этот скрипт при запуске создаст все те файлы, что я прикрепил
'''

import numpy as np
import pandas as pd
from tensorflow.keras.layers import Input, Dense
from tensorflow.keras.models import Model
from tensorflow.keras.optimizers import Adam

np.random.seed(123456)

N = 5000
X = np.random.normal(0, np.sqrt(10), N)
e = np.random.normal(0, np.sqrt(0.3), N)
feature = -X + e

y = X 

df = pd.DataFrame({
    "X": X,
    "feature": feature,
    "y": y
})

df.to_csv("dataset.csv", index=False)

input_layer = Input(shape=(1,), name="input")
h1 = Dense(16, activation='relu', name="h1")(input_layer)
h2 = Dense(8, activation='relu', name="h2")(h1)

encoded = Dense(2, activation='linear', name="encoded")(h2)

dec_h1 = Dense(8, activation='relu', name="dec_h1")(encoded)
dec_h2 = Dense(16, activation='relu', name="dec_h2")(dec_h1)
decoded = Dense(1, activation='linear', name="decoded")(dec_h2)

reg_h1 = Dense(8, activation='relu', name="reg_h1")(encoded)
reg_output = Dense(1, activation='linear', name="reg_output")(reg_h1)

model = Model(inputs=input_layer, outputs=[decoded, reg_output])
model.compile(optimizer=Adam(0.001),
              loss={"decoded": "mse", "reg_output": "mse"})






model.fit(X.reshape(-1, 1),
          {"decoded": X.reshape(-1, 1),
           "reg_output": y.reshape(-1, 1)},
          epochs=40, batch_size=32, verbose=1)






encoder = Model(input_layer, encoded)
encoder.save("encoder_model.h5")

encoded_input = Input(shape=(2,), name="encoded_input")
d1 = model.get_layer("dec_h1")(encoded_input)
d2 = model.get_layer("dec_h2")(d1)
dout = model.get_layer("decoded")(d2)
decoder = Model(encoded_input, dout)
decoder.save("decoder_model.h5")

reg_input = Input(shape=(1,), name="reg_input")
rh1 = model.get_layer("h1")(reg_input)
rh2 = model.get_layer("h2")(rh1)
renc = model.get_layer("encoded")(rh2)
rr1 = model.get_layer("reg_h1")(renc)
rout = model.get_layer("reg_output")(rr1)

regressor = Model(reg_input, rout)
regressor.save("regressor_model.h5")





encoded_data = encoder.predict(X.reshape(-1, 1))
decoded_data = decoder.predict(encoded_data)
reg_pred = regressor.predict(X.reshape(-1, 1))

pd.DataFrame(encoded_data, columns=["z1", "z2"]).to_csv("encoded.csv", index=False)
pd.DataFrame(decoded_data, columns=["decoded"]).to_csv("decoded.csv", index=False)
pd.DataFrame({"y_true": y, "y_pred": reg_pred[:, 0]}).to_csv("regression_results.csv", index=False)
