//Chris Sun
//COSC 1320 C++
//asking a user how many students and how many movies each student watched. outputting user the average,  median, and mode

#include "pch.h"
#include <iostream>
#include <array>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

//prototypes
double calculateAverage(int *, int);
double calculateMedian(int *, int);
double calculateMode(int *, int);


int main()
{	//variables
	int studentNum = 0;		//to hold the number of students
	int *student;				//to dynamically allocate an array

	//asking the user how many students surveyed
	cout << "How many students did you survey?" << endl;
	cin >> studentNum;

	//input validations
	while (studentNum < 0) {
		cout << "Invalid number of students." << endl;
		cout << "How many students did you survey?" << endl;
		cin >> studentNum;
	}

	student = new int[studentNum];		//new array with the number of students entered

	//loop to get the number of movies watched for each student
	for (int count = 0; count < studentNum; count++) {
		cout << "Number of movies watched by student " << (count + 1) << ": " << endl;
		cin >> student[count];

		//input validation for movies
		while (student[count] < 0) {
			cout << "Invalid number. Please enter a positive number." << endl;
			cout << "Number of movies watched by student " << (count + 1) << ": " << endl;
			cin >> student[count];
		}

	}

	//output to the user
	cout << "\n The average movies watched is: ";
	cout << round(calculateAverage(student, studentNum)) << endl;		//rounded movies for output

	cout << "\n The median is: ";
	cout << calculateMedian(student, studentNum) << endl;

	cout << "\n The mode is: ";
	cout << calculateMode(student, studentNum) << endl;

	return 0;
}


//function to calculate the average movies watched
double calculateAverage(int *student, int studentNum) {
	//variables
	double total = 0;		
	double average;

	//loop to add the movies watched by students
	for (int count = 0; count < studentNum; count++) {
		total += student[count];
	}
	average = total / studentNum;		//calculating average by dividing total by the number of students
	return average;						//returning the average
}

//function to calculate the median
double calculateMedian(int *student, int studentNum) {
	sort(student, student+studentNum);		//sorting the array to figure out the median

	//variables
	double median = 0.0;

	if (studentNum % 2 == 0) {
		median = (student[studentNum / 2] + student[(studentNum / 2) + 1]) / 2;		//if there is an odd number of students
	}
	else
		median = student[studentNum / 2];		//if there is an even number of students

	return median;
}

//function to calculate the mode
double calculateMode(int *student, int studentNum) {
	sort(student, student + studentNum);	//sorting the array

	//variables
	int number = student[0];
	int mode = number;
	int count = 1;
	int countMode = 1;

	for (int i = 1; i < studentNum;i++) {
		if (student[i] == number) {		//counts the occurences of current number
			++count;
		}
		else {							//if its a different number
			if (count > countMode) {
				countMode = count;		//modes is the biggest occurence
				mode = number;
			}
			count = 1;					//resets count for the new number
			number = student[i];
		}
	}
	return mode;
}