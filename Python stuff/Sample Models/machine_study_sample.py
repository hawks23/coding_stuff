'''import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

# Step 1: Gather Data
hours_studied = np.array([2, 3, 4, 5, 6, 7, 8, 9, 10, 11])
pass_fail = np.array(['Fail', 'Fail', 'Fail', 'Fail', 'Pass', 'Pass', 'Pass', 'Pass', 'Pass', 'Pass'])

# Step 2: Data Preprocessing
X = hours_studied.reshape(-1, 1)
y = pass_fail

# Step 3: Split Data into Training and Testing Sets
split_index = int(0.8 * len(X))
X_train = X[:split_index]
X_test = X[split_index:]
y_train = y[:split_index]
y_test = y[split_index:]

# Step 4: Choose a Model
model = LogisticRegression()

# Step 5: Train the Model
model.fit(X_train, y_train)

# Step 6: Make Predictions
y_pred = model.predict(X_test)

# Step 7: Evaluate the Model
accuracy = accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)

a = int(input("Enter hours studied :"))
y_pred = model.predict(a)
print(y_pred)'''

import numpy as np
from sklearn.linear_model import LogisticRegression

# Step 1: Gather Data
hours_studied = np.array([2, 3, 4, 5, 6, 7, 8, 9, 10, 11])
pass_fail = np.array(['Fail', 'Fail', 'Fail', 'Fail', 'Pass', 'Pass', 'Pass', 'Pass', 'Pass', 'Pass'])

# Step 2: Data Preprocessing
X = hours_studied.reshape(-1, 1)
y = pass_fail

# Step 4: Choose a Model
model = LogisticRegression()

# Step 5: Train the Model
model.fit(X, y)

# Interactive Section
while True:
    hours = float(input("Enter the number of hours studied (or enter q to quit): "))
    if hours == 'q':
        break

    # Preprocess the user input
    input_data = np.array([[hours]])

    # Step 6: Make Prediction
    predicted_label = model.predict(input_data)

    print("Predicted label: ", predicted_label[0])
