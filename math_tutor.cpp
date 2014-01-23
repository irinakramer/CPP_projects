//******************************************************
// Irina Kramer
// Project 2 - Math Tutor program
// 10/31/2013
// CS10 - #1368 (S Sarkar)
//******************************************************
// This program will ask a user to answer a series of
// arithmetic questions and will report on how the
// user performs.

#include <iostream>
#include <ctime>    // used by srand (time) function
#include <cstdlib> // for random number generator

using namespace std;

void doOneSet(/*in*/char, /*in*/int, /*out*/int&); // function prototype
void doOneProblem(/*in*/char, /*in*/int, /*out*/int&); // function prototype
void getNumbers(/*out*/int&, /*out*/int&, /*in*/int);  // function prototype
void checkAnswer(/*in*/int, /*in*/int, /*out*/int&);    // function prototype
void calcCorrectAnswer(/*in*/int, /*in*/int, /*in*/char, /*out*/int&); // function prototype
void getProbPerSet(/*out*/int&); // function prototype
void printHeader(/*in*/char);   // function prototype
void getMaxNum(/*out*/int&); // function prototype
void printReport(/*in*/int, /*in*/int, /*in*/int, /*in*/int); // function prototype

int main()
{
    // Declare local variables
    int probsPerSet;
    int set1Correct=0, set2Correct=0, set3Correct=0;
    // Function calls
    srand(time(0)); // uses the clock time to initialize the random number generator
    getProbPerSet(probsPerSet);
    doOneSet('+', probsPerSet, set1Correct);
    doOneSet('-', probsPerSet, set2Correct);
    doOneSet('*', probsPerSet, set3Correct);
    printReport(probsPerSet, set1Correct, set2Correct, set3Correct);

    return 0;
}




//***********************************************************
// Function void getProbPerSet definition.
// This function lets the user specify the number of
// problems per set.
//***********************************************************
void getProbPerSet(/*out*/int& numProbs)
// Pre: numProbs assigned
// Post: numProbs received from user and passed to the calling function
{
    do
    {
        cout << "Enter problems per set (between 3 and 8): ";
        cin >> numProbs;
    }
    while (numProbs < 3 || numProbs > 8); // specify range between 3 and 8.
}





//***********************************************************
// Function void doOneSet definition.
// This function prints a set of problems depending given
// arithmetic operator and number of problems.
// Char name is sign for different types of arithmetic (+, -, *)
//***********************************************************
void doOneSet(/*in*/char sign,
              /*in*/int numProbs,
              /*out*/int& countCorrect)
// Pre: sign, numProbs and countCorrect are assigned
// Post: output one set of problems
{
    // local variable declared
    int maxNum;
    // function calls
    printHeader(sign);
    getMaxNum(maxNum);
    // loop to output a set of problems
    for (int i = 1; i <= numProbs; i++)
    {
        doOneProblem(sign, maxNum, countCorrect);
    }
}




//***********************************************************
// Function void printHeader definition.
// This function prints out header for each problem set.
//***********************************************************
void printHeader(/*in*/char sign)
// Pre: sign assigned
// Post: header printed
{
    // switch statement to print the specific header
    // indicated by the sign argument.
    switch(sign)
    {
        case '+' : cout << "\nSet #1" << endl
                    << "----------" << endl;
                    break;
        case '-' : cout << "\nSet #2" << endl
                    << "----------" << endl;
                    break;
        case '*' : cout << "\nSet #3" << endl
                    << "----------" << endl;
                    break;
        default : cout << "incorrect sign.";
    }
}




//***********************************************************
// Function void getMaxNum definition.
// This function asks user to enter a max range for a problem
// values and passes it to the calling function.
//***********************************************************
void getMaxNum(/*out*/int& maxNum)
// Pre: outgoing parameter maxNum is assign
// Post: maxNum received from user
{
    cout << "What is the maximum number for this set? ";
    cin >> maxNum;
}




//***********************************************************
// Function void doOneProblem definition.
// This function generates one problem and receives user answer.
//***********************************************************
void doOneProblem(/*in*/char problemSign,
                  /*in*/int maxNum,
                  /*out*/int& countCorrect)
// Pre: problemSign has been assigned
// Post: output problem, get user answer, output correct or incorrect
{
        // declare local variables
        int num1, num2; // random numbers
        int userAnswer; // store user answer
        int correctAnswer = 0; // store correct answer

        // Function call to generate random numbers
        getNumbers(num1, num2, maxNum);

        // output the problem, ask for user to solve
        cout << num1 << " " << problemSign << " " << num2 << " = ";
        cin >> userAnswer;

        // Function call to calculate correct answer
        calcCorrectAnswer(num1, num2, problemSign, correctAnswer);

        // Function call to check if user answer is correct or not
        checkAnswer (userAnswer, correctAnswer, countCorrect);
}




//***********************************************************
// Function void getNumbers definition.
// This function generates two random numbers.
//***********************************************************
void getNumbers(/*out*/int& value1,
                /*out*/int& value2,
                /*in*/int max_range)
// Pre: value1 and value2 parameters are assigned as outgoing types,
//      max_range assigned as incoming type.
// Post: value1 and value2 random numbers are generated and passed
//      to acalling function.
{
    value1 = rand() % (max_range +1);
    value2 = rand() % (max_range +1);
}




//***********************************************************
// Function void calcCorrectAnswer definition.
// This function calculates correct answer based on the
// problem type (addition, subtraction or multiplication).
//***********************************************************
void calcCorrectAnswer (/*in*/int value1,
                        /*in*/int value2,
                        /*in*/char arithmSign,
                        /*out*/int& value3)
// Pre: value1, value2, and arithmetic sign are assigned
//      as incoming types, value3 assigned as outgoing type.
// Post: correct answer calculated and passed to the calling function
{
    // use switch statement to calculate correct answer.
    switch(arithmSign)
    {
        case '+' : value3 = value1 + value2;
        break;
        case '-' : value3 = value1 - value2;
        break;
        case '*' : value3 = value1 * value2;
        break;
        default : cout << "incorrect sign.";
    }
}




//***********************************************************
// Function void checkAnswer definition.
// This functions compares user answer with correct answer,
// it outputs correct or incorrect statement.
//***********************************************************
void checkAnswer (/*in*/int userValue,
                  /*in*/int correctValue,
                  /*out*/int& countCorrect)
// Pre: userValue and correctValue have been assigned,
//      countCorrect is assigned as outgoing type.
// Post: output "correct" or "incorrect";
//      number of correct passed to calling function.
{
    if (userValue == correctValue)
    {
        cout << "correct" << endl;
        countCorrect++;
    }
    else
        cout << "incorrect" << endl;
}




//***********************************************************
// Function void printReport definition.
// This function prints out a report indicating number of
// correct answers out of total, and the overall performance.
//***********************************************************
void printReport(/*in*/int probsPerSet,
                 /*in*/int set1Correct,
                 /*in*/int set2Correct,
                 /*in*/int set3Correct)
// Pre: probsPerSet, set1Correct,set2Correct,set3Correct
//      are assigned as incoming parameters.
// Post: values calculated and report is printed.
{
    // explicit type casting is performed for the percentage indicator.
    cout << "\nSet #1: You got " << set1Correct << " correct out of "
        << probsPerSet << " for " << int(set1Correct * 100.0 / probsPerSet + 0.5)
        << "%." << endl;

    cout << "Set #2: You got " << set2Correct << " correct out of "
        << probsPerSet << " for " << int(set2Correct * 100.0 / probsPerSet + 0.5)
        << "%." << endl;

    cout << "Set #3: You got " << set3Correct << " correct out of "
        << probsPerSet << " for " << int(set3Correct * 100.0 / probsPerSet + 0.5)
        << "%." << endl;

    cout << "Overall you got " << set1Correct + set2Correct + set3Correct << " out of "
        << probsPerSet * 3 << " for "
        << int(((set1Correct + set2Correct + set3Correct) * 100.0 ) / (probsPerSet * 3) + 0.5)
        << "%." << endl;
}


