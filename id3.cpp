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

using namespace std;

int main (int argc, char* argv[]) {

	// Number of features included in the data for each example
	int numberOfFeatures = 1;

	// Names of the training and testing input files
	string trainingFileName = "training.txt", testingFileName = "testing.txt";

	// Collect command line argument data
	if (argc == 4) {
		numberOfFeatures = atoi(argv[1]);
		trainingFileName = argv[2];
		testingFileName = argv[3];
		printf("Features: %d\nTraining File: %s\nTesting File: %s\n", numberOfFeatures, trainingFileName.c_str(), testingFileName.c_str());
	} else {
		printf("Usage: id3 [features] [training filename] [testing filename]\n");
	}

	return 0;
}
