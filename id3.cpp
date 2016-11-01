//  Project:		ID3 Decision Tree
//  Date:			10 - 27 - 2016
//  Class:			CSCI 4350 - Intro to Artificial Intelligence
//  Assignment:		Open Lab 3 - Supervised Learning
//  Filename:		ID3 Source Code
//  Author:			Grayson M. Dubois
//	Instructor:		Joshua L. Phillips
//  Institution:	Middle Tennessee State University
//  Department:		Computer Science

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Example stores the values of all features and classification of a single example in the data set
struct Example {
	int numberOfFeatures;
	vector<double> featureValues;
	int classValue;

	Example(int numFeatures) {
		numberOfFeatures = numFeatures;
		featureValues.resize(numberOfFeatures);
	}

	void readExample(ifstream& fin) {
		for (auto& feature : featureValues) {
			fin >> feature;
		}
		fin >> classValue;
	}
};

ostream& operator<<(ostream& out, const Example ex) {
	if (ex.numberOfFeatures > 0) {
		out << ex.featureValues[0];
		for (int i = 1; i < ex.numberOfFeatures; i++) {
			out << "\t" << ex.featureValues[i];
		}
		out << "\t" << ex.classValue << "\n";
	}
	return out;
}


// Declarations of ID3 Methods



int main (int argc, char* argv[]) {

	// Number of features included in the data for each example
	int numberOfFeatures = 1;

	// Names of the training and testing input files
	string trainingFileName, testingFileName;

	// Collect command line argument data
	if (argc == 4) {
		numberOfFeatures = atoi(argv[1]);
		trainingFileName = argv[2];
		testingFileName = argv[3];
	} else {
		printf("Usage: id3 [features] [training filename] [testing filename]\n");
		return 9;
	}

	/**** Collect Training data from input ****/
	
	// Open filestream for training file
	ifstream fin;
	fin.open(trainingFileName);

	// Create the training data as a vector of examples
	vector<Example> trainingExamples;

	// Read in new examples until the end of the file
	while (!fin.eof()) {
		Example ex(numberOfFeatures);
		ex.readExample(fin);
		if (fin.eof()) break;
		trainingExamples.push_back(ex);
	}

	fin.close();

	
	/**** Collect Training data from input ****/
	
	// Open filestream for training file
	fin.open(testingFileName);

	// Create the training data as a vector of examples
	vector<Example> testingExamples;

	// Read in new examples until the end of the file
	while (!fin.eof()) {
		Example ex(numberOfFeatures);
		ex.readExample(fin);
		if (fin.eof()) break;
		testingExamples.push_back(ex);
	}

	fin.close();


	/**** ID3 Decision Tree Construction ****/


	// Print out all examples in training data
	printf("\nTraining Data\n");
	for (auto example : trainingExamples) {
		cout << example;
	}

	// Print out all examples in testing data
	printf("\nTesting Data\n");
	for (auto example : testingExamples) {
		cout << example;
	}


	// Test out sorting methods
	int index;
	do {
		printf("Enter an index to sort by from 0 to %d (-1 to quit): ", numberOfFeatures);
		cin >> index;

		std::sort(trainingExamples.begin(), trainingExamples.end(), [index](auto && l, auto && r) { return l.featureValues[index] < r.featureValues[index]; });

		// Print out all examples in training data
		printf("\nSorted Training Data\n");
		for (auto example : trainingExamples) {
			cout << example;
		}	

	} while (index != -1);


	// For each feature, sort the data on that feature, 
	// and calculate the maximum information gain for
	// split points between every example, and insert the
	// split with the greatest gain into the decision tree
	double split = 0.0;
	for (int f = 0; f < numberOfFeatures; f++) {

		// Sort the examples by the currently selected feature
		sort(trainingExamples.begin(), trainingExamples.end(), 
			 [f] (auto && l, auto && r) { 
				return l.featureValues[f] < r.featureValues[f]; 
			 });

		// Find split point that yields the maximum information gain
		for (int s = 1; s < trainingExamples.size(); s++) {
			split = (trainingExamples[s-1].featureValues[f] + trainingExamples[s].featureValues[f]) / 2;
			printf("Split between example[%d][%d] = %f and example[%d][%d] = %f is %f\n", 
				   s-1, f, trainingExamples[s-1].featureValues[f], s, f,
				   trainingExamples[s].featureValues[f], split);
		}
	}


	return 0;
}
