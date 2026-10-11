import numpy as np
import pandas as pd

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, classification_report

# -----------------------
# 1. Load dataset
# -----------------------
iris = load_iris()

df = pd.DataFrame(iris.data, columns=iris.feature_names)
df['target'] = iris.target

print(df.head())

# -----------------------
# 2. Split features/labels
# -----------------------
X = df.drop('target', axis=1).values
y = df['target'].values

# -----------------------
# 3. Train-test split
# -----------------------
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# -----------------------
# 4. Feature scaling (important for KNN)
# -----------------------
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# -----------------------
# 5. Build KNN model
# -----------------------
k = 5
model = KNeighborsClassifier(n_neighbors=k)

model.fit(X_train, y_train)

# -----------------------
# 6. Predictions
# -----------------------
y_pred = model.predict(X_test)

# -----------------------
# 7. Evaluation
# -----------------------
print("Accuracy:", accuracy_score(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))