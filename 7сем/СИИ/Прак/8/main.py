'''
16 по списку -> 2 вариант
'''

import numpy as np
import tensorflow as tf
from tensorflow.keras import layers, models
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder

from var2 import gen_data  


from datetime import datetime
# 16 по списку -> 4 вариант
class SaveOnEpochs(tf.keras.callbacks.Callback):
    def __init__(self, epochs_to_save, prefix="model"):
        super().__init__()
        self.epochs_to_save = set(epochs_to_save)
        self.prefix = prefix
        self.date = datetime.now().strftime("%Y-%m-%d")

    def on_epoch_end(self, epoch, logs=None):
        ep = epoch + 1
        if ep in self.epochs_to_save:
            filename = f"{self.date}_{self.prefix}_{ep}.h5"
            self.model.save(filename)
            print(f"\n>>> Model saved: {filename}\n")


X, y = gen_data(size=1000, img_size=50)


X = X[..., np.newaxis].astype("float32")


le = LabelEncoder()
y_encoded = le.fit_transform(y.ravel())


X_train, X_test, y_train, y_test = train_test_split(
    X, y_encoded, test_size=0.2, shuffle=True, stratify=y_encoded
)


X_train, X_val, y_train, y_val = train_test_split(
    X_train, y_train, test_size=0.2, shuffle=True, stratify=y_train
)








model = models.Sequential([
    layers.Conv2D(16, (3, 3), activation='relu', input_shape=(50, 50, 1)),
    layers.MaxPooling2D((2, 2)),

    layers.Conv2D(32, (3, 3), activation='relu'),
    layers.MaxPooling2D((2, 2)),

    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.MaxPooling2D((2, 2)),

    layers.Flatten(),
    layers.Dense(64, activation='relu'),
    layers.Dense(1, activation='sigmoid')   # бинарная классификация
])

model.compile(
    optimizer='adam',
    loss='binary_crossentropy',
    metrics=['accuracy']
)

model.summary()




callback = SaveOnEpochs(
    epochs_to_save=[1, 3, 5, 10],   # здесь можно указать любые эпохи
    prefix="shapes_model"
)

history = model.fit(
    X_train, y_train,
    epochs=10,
    
    batch_size=32,
    validation_data=(X_val, y_val),
    callbacks=[callback]
)







loss, acc = model.evaluate(X_test, y_test)
print(f"\nTest accuracy: {acc:.4f}")
