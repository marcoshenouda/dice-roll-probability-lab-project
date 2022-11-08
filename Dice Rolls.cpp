/*
	Name: Dice Rolls
	Copyright: 2022
	Author: Marco Shenouda
	Date: 09/08/22 9:45
	Description: A program to simulate random dice rolls and print the frequency of each score for probability lab project.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Data types
const int SCORE_SIZE = 13;
typedef int DiceRollResultsType[SCORE_SIZE];

// Function prototypes
void getScores(DiceRollResultsType, int);
void printDiceRollResults(const DiceRollResultsType, int);

// Main test driver
int main() {
	DiceRollResultsType scoreResults = {0};
	getScores(scoreResults, SCORE_SIZE);
	printDiceRollResults(scoreResults, SCORE_SIZE);
	return 0;
}

// Random Dice Roll Generator
void getScores(DiceRollResultsType scores, int size)
{

	// Declaring Variables
	int rollInput;
	int roll_one;
	int roll_two;
	int doubleRoll;

	// Get number of desired dice rolls from user
	cout << "How many times do you want to roll the dice? "
		"Enter a positive integer with no commas: ";
	cin >> rollInput;

	// Initializing random number generator in C++
    srand(time(0));
    for(int x=0; x<rollInput ;x++){
        roll_one = 1+ (rand() % 6);
        roll_two = 1+ (rand() % 6);
        doubleRoll = roll_one + roll_two;
        scores[doubleRoll]++;
    }
}    

// Print the dice roll Score results to the screen
void printDiceRollResults(const DiceRollResultsType scores, int size)
{
	cout << "\nHere are the dice roll results:\n\n";
	for (int score = 2; score < SCORE_SIZE; score++)
	{
		if (scores[score] != 0)
		{
			cout << score << ": " << scores[score] << endl;
		}
	}
	cout << endl;
}