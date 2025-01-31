"""Softmax model."""

import numpy as np
import math


class Softmax:
    def __init__(self, n_class: int, lr: float, epochs: int, reg_const: float):
        """Initialize a new classifier.

        Parameters:
            n_class: the number of classes
            lr: the learning rate
            epochs: the number of epochs to train for
            reg_const: the regularization constant
        """
        self.w = None  # TODO: change this
        self.lr = lr
        self.epochs = epochs
        self.reg_const = reg_const
        self.n_class = n_class

    def calc_gradient(self, X_train: np.ndarray, y_train: np.ndarray) -> np.ndarray:
        """Calculate gradient of the softmax loss.

        Inputs have dimension D, there are C classes, and we operate on
        mini-batches of N examples.

        Parameters:
            X_train: a numpy array of shape (N, D) containing a mini-batch
                of data
            y_train: a numpy array of shape (N,) containing training labels;
                y[i] = c means that X[i] has label c, where 0 <= c < C

        Returns:
            gradient with respect to weights w; an array of same shape as w
        """
        # TODO: implement me
        

        return

    def train(self, X_train: np.ndarray, y_train: np.ndarray):
        """Train the classifier.

        Hint: operate on mini-batches of data for SGD.

        Parameters:
            X_train: a numpy array of shape (N, D) containing training data;
                N examples with D dimensions
            y_train: a numpy array of shape (N,) containing training labels
        """
        # TODO: implement me
        self.w = np.zeros((self.n_class, X_train.shape[1]))
        print("train start")
        N = X_train.shape[0]
        for passes in range(self.epochs):
            for cycle in range(N):
                current_max = 0;
                for j in range(self.n_class):
                    check = np.dot(self.w[j].T, X_train[cycle])
                    if check > current_max:
                        current_max = check
                 
                current_max = current_max * -1
                denom = 0
                for j in range(self.n_class):
                    denom += np.exp(np.dot(self.w[j].T, X_train[cycle]) + current_max)

                for c in range(self.n_class):
                    num = np.exp(np.dot(self.w[c].T, X_train[cycle])+ current_max)
                    grad = num/denom
                    if c == y_train[cycle]:
                        self.w[c] = self.w[c] - self.lr * (grad-1) * X_train[cycle]
                    else:
                        self.w[c] = self.w[c] - self.lr * grad * X_train[cycle]
        print("train done")


    def predict(self, X_test: np.ndarray) -> np.ndarray:
        """Use the trained weights to predict labels for test data points.

        Parameters:
            X_test: a numpy array of shape (N, D) containing testing data;
                N examples with D dimensions

        Returns:
            predicted labels for the data in X_test; a 1-dimensional array of
                length N, where each element is an integer giving the predicted
                class.
        """
        # TODO: implement me
        labels = []
        for example in range(X_test.shape[0]):
            labels.append(np.argmax(np.dot(self.w, X_test[example])))
        
        return labels
