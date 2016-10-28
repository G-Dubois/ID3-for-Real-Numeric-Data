# ID3 for Real Numeric Data

* * *

ID3 program creates an ID3 decision tree to classify a set of input training data and then reports the classification performance on a separate set of input testing data.

	* Program takes **3 command line arguments** (integer: the number of real-valued features in the data set, sting: intput training data filename, string: input testing data filename)
	* The program reads in the **training data** file (one training example per line, see below)
	* The program reads in the **testing data** file (one testing example per line, see below)
	* Each line contains the specified number of real feature values and a single integer value (the class label) at the end
	* The program builds an ID3 decision tree by **sorting** the training data by each feature/attribute and determining potential split points based on **attribute value changes** (average the two values to make the split) and **maximum information gain**
	* **Ties** (in maximum information gain) should be broken such that the split best preserving the **prior probabilities** of the class labels is used, then by feature order as found in the input file
	* Once the decision tree has been created, each of the testing examples should be classified using the resulting decision tree
	* The program should then output the number of testing examples classified **correctly** by the decision tree

Link to original data set [here] (https://archive.ics.uci.edu/ml/datasets/Iris "Iris@UCI")
