'''
Тут реализованы все варианты. На всякий случай.

Ещё можно поменять число эпох на какое-нибудь низкое число, по типу 5 и увидеть как модель выдаст лажу.
'''

import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np

VARIANT = 4
EPOCHS = 1000

X = torch.tensor([[0,0,0],
                  [0,0,1],
                  [0,1,0],
                  [0,1,1],
                  [1,0,0],
                  [1,0,1],
                  [1,1,0],
                  [1,1,1]], dtype=torch.float32)

def get_target(variant):
    a, b, c = X[:,0], X[:,1], X[:,2]
    if variant == 1:  # (a and b) or (a and c)
        Y = torch.logical_or(torch.logical_and(a.bool(), b.bool()),
                             torch.logical_and(a.bool(), c.bool()))
    elif variant == 2:  # (a or b) xor not(b and c)
        Y = torch.logical_xor(torch.logical_or(a.bool(), b.bool()),
                              torch.logical_not(torch.logical_and(b.bool(), c.bool())))
    elif variant == 3:  # (a and b) or c
        Y = torch.logical_or(torch.logical_and(a.bool(), b.bool()), c.bool())
    elif variant == 4:  # (a or b) and (b or c)
        Y = torch.logical_and(torch.logical_or(a.bool(), b.bool()),
                              torch.logical_or(b.bool(), c.bool()))
    elif variant == 5:  # (a xor b) and (b xor c)
        Y = torch.logical_and(torch.logical_xor(a.bool(), b.bool()),
                              torch.logical_xor(b.bool(), c.bool()))
    elif variant == 6:  # (a and not b) or (c xor b)
        Y = torch.logical_or(torch.logical_and(a.bool(), torch.logical_not(b.bool())),
                             torch.logical_xor(c.bool(), b.bool()))
    elif variant == 7:  # (a or b) and (a xor not b)
        Y = torch.logical_and(torch.logical_or(a.bool(), b.bool()),
                              torch.logical_xor(a.bool(), torch.logical_not(b.bool())))
    elif variant == 8:  # (a and c and b) xor (a or not b)
        Y = torch.logical_xor(torch.logical_and(torch.logical_and(a.bool(), b.bool()), c.bool()),
                              torch.logical_or(a.bool(), torch.logical_not(b.bool())))
    else:
        raise ValueError("Variant must be 1-8")
    
    return Y.float().reshape(-1,1)

Y = get_target(VARIANT)

# -------------------------------
# 3. Модель
# -------------------------------
class LogicNet(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc = nn.Linear(3, 1)
        self.sigmoid = nn.Sigmoid()
    
    def forward(self, x):
        return self.sigmoid(self.fc(x))

model = LogicNet()

# -------------------------------
# 4. Извлечение весов
# -------------------------------
def get_weights(model):
    w = model.fc.weight.detach().numpy().flatten()
    b = model.fc.bias.detach().numpy()[0]
    return w, b

# -------------------------------
# 5. Симуляция модели
# -------------------------------
def simulate_elementwise(X_tensor, weights):
    w, b = weights
    out = []
    for x in X_tensor:
        z = x[0]*w[0] + x[1]*w[1] + x[2]*w[2] + b
        y = 1 / (1 + np.exp(-z))  # sigmoid
        out.append(y)
    return torch.tensor(out).reshape(-1,1)

def simulate_numpy(X_tensor, weights):
    w, b = weights
    X_np = X_tensor.numpy()
    z = np.dot(X_np, w) + b
    y = 1 / (1 + np.exp(-z))  # sigmoid
    return torch.tensor(y).reshape(-1,1)

# -------------------------------
# 6. Проверка до обучения
# -------------------------------
initial_weights = get_weights(model)
with torch.no_grad():
    pred_model = model(X)
    pred_elem = simulate_elementwise(X, initial_weights)
    pred_numpy = simulate_numpy(X, initial_weights)

print("=== До обучения ===")
print("Model output:\n", pred_model)
print("Elementwise simulation:\n", pred_elem)
print("NumPy simulation:\n", pred_numpy)

# -------------------------------
# 7. Обучение модели
# -------------------------------
criterion = nn.BCELoss()
optimizer = optim.SGD(model.parameters(), lr=0.1)

for epoch in range(EPOCHS):
    optimizer.zero_grad()
    output = model(X)
    loss = criterion(output, Y)
    loss.backward()
    optimizer.step()

trained_weights = get_weights(model)

# -------------------------------
# 8. Проверка после обучения
# -------------------------------
with torch.no_grad():
    pred_model = model(X)
    pred_elem = simulate_elementwise(X, trained_weights)
    pred_numpy = simulate_numpy(X, trained_weights)

print("\n=== После обучения ===")
print("Model output:\n", pred_model)
print("Elementwise simulation:\n", pred_elem)
print("NumPy simulation:\n", pred_numpy)

print("\n=== После обучения (round) ===")
print("Model output:\n", pred_model.round())
print("Elementwise simulation:\n", pred_elem.round())
print("NumPy simulation:\n", pred_numpy.round())

print("Target:\n", Y)
