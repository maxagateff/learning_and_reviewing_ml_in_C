import torch as tr
import torch.nn as nn
from torch.optim import SGD

def main(epochs): 
    X = tr.randn(5)
    Y = tr.randn(5)
    model = nn.Linear(5, 2)
    optimizer = SGD(model.parameters(), lr=0.01)
    for epoch in range(epochs):
        optimizer.zero_grad()
        output = model(X)
        error = output - y
        loss = error ** 2
        loss.backward()
        optimizer.step()
        print(f"loss = {loss} | model.parameters = {model.parameters}")
