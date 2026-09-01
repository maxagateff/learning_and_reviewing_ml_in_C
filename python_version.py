import torch as tr
import torch.nn as nn
from torch.optim import SGD

device = tr.device("cuda" if tr.cuda.is_available() else "cpu")
def main(epochs):
    X = tr.randn(5).to(device)
    Y = tr.randn(2).to(device)
    
    model = nn.Linear(5, 2).to(device)
    optimizer = SGD(model.parameters(), lr=0.01)
    
    for epoch in range(epochs):
        optimizer.zero_grad()
        output = model(X)
        error = output - Y
        loss = (error ** 2).sum()
        print(f"Epoch {epoch+1} | loss = {loss.item():.4f}")
        
        loss.backward()
        optimizer.step()

main(5)
