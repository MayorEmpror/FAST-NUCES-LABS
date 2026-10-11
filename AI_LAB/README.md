# 🤖 AI Lab Repository (Labs 1–12)

This repository contains implementations and examples of core Artificial Intelligence and Data Science concepts, including optimization, probability, machine learning, preprocessing, and visualization.

---

## 📌 Topics Covered

* Problem Modeling & Solving using OR-Tools
* Basic Probability Concepts
* Game Trees, Minimax & Alpha-Beta Pruning
* Exploratory Data Analysis (EDA)
* Data Cleaning & Preprocessing
* Evaluation Metrics
* Machine Learning Algorithms
* Data Visualization

---

## 🧠 1. Problem Modeling & Solving (OR-Tools)

Example: Linear Optimization

```python
from ortools.linear_solver import pywraplp

solver = pywraplp.Solver.CreateSolver('GLOP')

x = solver.NumVar(0, solver.infinity(), 'x')
y = solver.NumVar(0, solver.infinity(), 'y')

solver.Maximize(3 * x + 4 * y)

solver.Add(x + 2 * y <= 14)
solver.Add(3 * x - y >= 0)
solver.Add(x - y <= 2)

solver.Solve()

print("Optimal value =", solver.Objective().Value())
print("x =", x.solution_value(), "y =", y.solution_value())
```

---

## 🎲 2. Basic Probability

```python
# Probability of at least one head in 2 tosses
p = 1 - (0.5 ** 2)
print(p)
```

---

## ♟️ 3. Game Trees, Minimax & Alpha-Beta

### Minimax

```python
def minimax(depth, is_max):
    if depth == 0:
        return 1

    if is_max:
        return max(minimax(depth-1, False), minimax(depth-1, False))
    else:
        return min(minimax(depth-1, True), minimax(depth-1, True))
```

### Alpha-Beta Pruning

```python
def alphabeta(depth, alpha, beta, maximizing):
    if depth == 0:
        return 1

    if maximizing:
        value = -float('inf')
        value = max(value, alphabeta(depth-1, alpha, beta, False))
        alpha = max(alpha, value)
        if alpha >= beta:
            return value
        return value
    else:
        value = float('inf')
        value = min(value, alphabeta(depth-1, alpha, beta, True))
        beta = min(beta, value)
        if beta <= alpha:
            return value
        return value
```

---

## 📊 4. Exploratory Data Analysis (EDA)

```python
import pandas as pd

df = pd.read_csv("data.csv")

print(df.head())
print(df.info())
print(df.describe())
```

---

## 🧹 5. Data Cleaning & Preprocessing

### Handling Missing Values

```python
df.fillna(df.mean(), inplace=True)
```

### Encoding

```python
df = pd.get_dummies(df, columns=['category'])
```

### Feature Scaling

```python
from sklearn.preprocessing import StandardScaler

scaler = StandardScaler()
df[['col']] = scaler.fit_transform(df[['col']])
```

---

## 📏 6. Evaluation Metrics

```python
from sklearn.metrics import accuracy_score, precision_score

accuracy = accuracy_score(y_true, y_pred)
precision = precision_score(y_true, y_pred)
```

---

## 📈 7. Linear & Logistic Regression

### Linear Regression

```python
from sklearn.linear_model import LinearRegression

model = LinearRegression()
model.fit(X, y)
```

### Logistic Regression

```python
from sklearn.linear_model import LogisticRegression

model = LogisticRegression()
model.fit(X, y)
```

---

## 🌳 8. Decision Trees

```python
from sklearn.tree import DecisionTreeClassifier

model = DecisionTreeClassifier()
model.fit(X, y)
```

---

## 📍 9. K-Nearest Neighbors (KNN)

```python
from sklearn.neighbors import KNeighborsClassifier

model = KNeighborsClassifier(n_neighbors=3)
model.fit(X, y)
```

---

## 🔵 10. K-Means Clustering

```python
from sklearn.cluster import KMeans

kmeans = KMeans(n_clusters=3)
kmeans.fit(X)
```

---

## 📉 11. Plotting & Visualization

```python
import matplotlib.pyplot as plt

plt.scatter(df['x'], df['y'])
plt.title("Scatter Plot")
plt.show()
```

---

## 🧪 Lab Structure

| Lab    | Content                       |
| ------ | ----------------------------- |
| Lab 7  | OR-Tools & Optimization       |
| Lab 8  | Probability & Game Trees      |
| Lab 9  | Exploratory Data Analysis     |
| Lab 10 | Data Cleaning & Preprocessing |
| Lab 11 | Machine Learning Models       |
| Lab 12 | Evaluation & Visualization    |

---

## 🚀 Setup & Run

```bash
pip install -r requirements.txt
python main.py
```

---

## 📁 Folder Structure

```
AI-Labs/
│── data/
│── notebooks/
│── src/
│── README.md
│── requirements.txt
```

---

## 📌 Notes

* This repository is for learning and academic purposes.
* Each lab builds upon the previous one.
* Code is kept simple for clarity and understanding.

---

## ⭐ Contribution

Feel free to fork, improve, and submit pull requests!
