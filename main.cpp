/******************************************************************************
# Author:           Andy Joy
# Assignment:       Assignment 8
# Date:             06/06/2026
# Description:      This program calculates the final weighted numerical score 
#                   and letter grade when given assignment, and exam scores. 
#                   The program will only take 0-10 assignments using a 4 point 
#                   grading scale.
# Input:            userVal (int).
# Output:           readScorePrompt (string), numericFinalScore (double), 
#                   finalLetterGrade (char).
# Sources:          N/A
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Constants
const double ASSINGMENTS_WEIGHT = 0.6;
const double EXAMS_WEIGHT = 0.2;

//Function prototypes
void WelcomeMessage();
int readInt(string prompt);
void readScore(string prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double &midtermScore, double &finalExamScore);
double calcFinalScore(double assignAvg, double midterm, double final);
void calcLetterGrade(double finalScore, char &letter);

//Main function
int main() {

  int numAssigns = 0;
  double assignAverageScore = 0.0;
  double midtermExamScore = 0.0;
  double finalExamScore = 0.0;
  double numericFinalScore = 0.0;
  char finalLetterGrade;

  WelcomeMessage();

  numAssigns = readInt("\nEnter the number of assignments (0 to 10): ");

  while (numAssigns < 0 || numAssigns > 10) {
    cout << "Illegal Value! Please try again!!" << endl;
    numAssigns = readInt("Enter the number of assignments (0 to 10): ");
  }
  assignAverageScore = assignAverage(numAssigns);

  getInput(midtermExamScore, finalExamScore);

  cout << fixed << setprecision(1);
  numericFinalScore = calcFinalScore(assignAverageScore, midtermExamScore, finalExamScore);
  calcLetterGrade(numericFinalScore, finalLetterGrade);
  cout << "\nYour Final Numeric score is " << numericFinalScore << endl;
  cout << "Your Final Grade is " << finalLetterGrade << endl;
  cout << "\nThank you for using my Grade Calculator!" << endl;

  //End program
  return 0;
}

//Welcome Message
void WelcomeMessage() {
  cout << "Welcome to my Final Grade Calculator!" << endl;
  cout << "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!" << endl;
  cout << "The number of assignments must be between 0 and 10." << endl;
  cout << "All scores entered must be between 0 and 4." << endl;
}

//Integer input validation
int readInt(string prompt){
  int userVal = 0;

  cout << prompt;
  cin >> userVal;

  while (!cin) {
    cout << "Illegal Value! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> userVal;
  }
  cin.ignore(50, '\n');
  return userVal;
}

//Integer input score validation. Like normal validation but also checks that valuue is 0-4 inclusive.
void readScore(string prompt, double &num) {
  cout << prompt;
  cin >> num;

  while (!cin || num < 0 || num > 4) {
    cout << "Illegal Score! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> num;
  }
  cin.ignore(50, '\n');
}

//Reads assignment scores from the user. Then calculates average score.
double assignAverage(int numAssigns) {
  double totalAssignmentScore = 0.0;
  double assignmentScore = 0.0;
  double assignAverage = 0.0;
  int i = 0;
  string readScorePrompt;

  for (i = 1; i <= numAssigns; ++i) {
    readScorePrompt = "Enter score " + to_string(i) + ": ";
    readScore (readScorePrompt, assignmentScore);
    totalAssignmentScore += assignmentScore;
  }
  assignAverage = totalAssignmentScore / numAssigns;

  return assignAverage;
}

void getInput(double &midtermScore, double &finalExamScore) {
  readScore("\nEnter your midterm exam score: ", midtermScore);
  readScore("Enter your final exam score: ", finalExamScore);
}

//Takes assignment average score, midterm score, final exam score, and calculates final numerical score. Assignments weighted at 60%, midterm and final exams weighted at 20%.
double calcFinalScore(double assignAvg, double midterm, double final) {
  double finalScore = 0.0;

  finalScore += assignAvg * ASSINGMENTS_WEIGHT;
  finalScore += midterm * EXAMS_WEIGHT;
  finalScore += final * EXAMS_WEIGHT;

  return finalScore;
}

//Takes finalScore and returns letter grade.
void calcLetterGrade(double finalScore, char &letter) {
  if (finalScore >= 3.3 && finalScore <= 4.0){
    letter = 'A';
  }
  else if (finalScore >= 2.8 && finalScore < 3.3) {
    letter = 'B';
  }
  else if (finalScore >= 2.0 && finalScore < 2.8) {
    letter = 'C';
  }
  else if (finalScore >= 1.2 && finalScore < 2.0) {
    letter = 'D';
  }
  else {
    letter = 'F';
  }
}