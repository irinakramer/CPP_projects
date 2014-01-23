//******************************************************
// Irina Kramer
// Project 4 - 1D Arrays - Score Analysis Program
// 12/6/2013
// CS10 - #1368 (S Sarkar)
//******************************************************
// This program reads test scores from the user
// or from a file, lets the user select a menu option,
// then performs and displays score analytics.
//******************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Function prototypes
int Prompt();
void InputScores(int[], const int);
void ReadScores(int[], const int);
void PrintScores(const int[], const int);
void PrintHighest(const int[], const int);
void PrintLowest(const int[], const int);
void PrintAverage(const int[], const int);
void PrintEntry(const int[], const int);
void FileOpen(/*inout*/ifstream&);
void SortScores(int[], const int);
void BinarySearch(int[], const int);


int main()
{
    //Declarations
    const int NUM_SCORES = 10;      // number of scores
    int scores[NUM_SCORES] = {0};   // Array of scores, initialized to 0.
    int userChoice;                 // User choice of menu options 1-10

     do
    {
        userChoice = Prompt();
        switch (userChoice)
        {
            case 1 : InputScores(scores, NUM_SCORES);
                    break;
            case 2 : ReadScores(scores, NUM_SCORES);
                    break;
            case 3 : PrintScores(scores, NUM_SCORES);
                    break;
            case 4 : PrintHighest(scores, NUM_SCORES);
                    break;
            case 5 : PrintLowest(scores, NUM_SCORES);
                    break;
            case 6 : PrintAverage(scores, NUM_SCORES);
                    break;
            case 7 : PrintEntry(scores, NUM_SCORES);
                    break;
            case 8 : cout << "Array processing test now concluded. Exiting program ....." << endl;
                    break;
            case 9 : SortScores(scores, NUM_SCORES);
                    cout << "The scores have been sorted in descending order. \nPlease select the print all scores menu option to view the scores." << endl;
                    break;
            case 10 : BinarySearch(scores, NUM_SCORES);
                    break;
            default : cout << "INVALID CHOICE ...please retype" << endl;
        }
    } while (userChoice != 8);
    return 0;
}



//      FUNCTION DEFINITIONS
//************************************************************
// Function Prompt
// This function prompts the user to enter a choice, it
// returns a value of this choice.
//************************************************************
int Prompt()
// Post: value of choice returned
{
    int choice = 0;
    cout
    << "---------------------------------------------------" << endl
    << "1-D ARRAY PROCESSING MENU OPTIONS" << endl
    << "---------------------------------------------------" << endl
    << "1. Read in 10 scores from user." << endl
    << "2. Read in 10 scores from the file, scores.txt." << endl
    << "3. Print all scores." << endl
    << "4. Print the highest score." << endl
    << "5. Print the lowest score." << endl
    << "6. Print the average score." << endl
    << "7. Print one score (give its entry number)" << endl
    << "8. Quit program" << endl
    << "9. Sort scores in descending order" << endl
    << "10. Search for a score" << endl << endl
    << "Enter your choice: ";
    cin >> choice;
    return choice;
}




//************************************************************
// #1 - Function InputScores
// This function reads score values from user input
// and stores them into the array.
//************************************************************
void InputScores(int values[], const int size)
// Pre: values array and size are assigned
// Post: values[0 ... size] have been read from the user
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter score #" << i + 1 << ": ";
        cin >> values[i];
    }
    cout << endl;
}




//************************************************************
// #2 - Function ReadScores
// This function reads score values from a file
// and stores them into an array.
//************************************************************
void ReadScores(int values[], const int size)
// Pre: values array and size are assigned
// Post: values[0 ... size] have been read from a file
//      and stored into an array
{
    ifstream file;            // File containing test scores
    FileOpen(file);            // Call to a function opening the file
    // loop through array elements to read and store values
    for (int i = 0; i < size; i++)
        file >> values[i];
    cout << "File has successfully opened and 10 scores have been read and stored.\nPlease select the print all scores menu option to view the scores." << endl << endl;
    file.close();               // close the file
}




//************************************************************
// Function FileOpen
// This function opens a file specified by a user,
// it validates that files opens successfully.
//************************************************************
void FileOpen(ifstream& file)
// Pre: file assigned
// Post: file successfully opened
{
    string fileName;            // declare string variable
    cout << "Please enter filename: ";
    cin >> fileName;

    file.open(fileName.c_str());
    // control loop to prompt user for correct file name
    while(!file)
    {
        cout << "File not found" << endl;
        file.clear();
        cout << "Please enter correct data filename" << endl;
        cin >> fileName;
        file.open(fileName.c_str());
    }
}




//************************************************************
// #3 - Function PrintScores
// This function reads score values from an array
//************************************************************
void PrintScores(const int values[], const int size)
// Pre: array values and size assigned
// Post: scores [0 ... size] are printed
{
    for (int i = 0; i < size; i++)
        cout << values[i] << endl;
}




//************************************************************
// #4 - Function PrintHighest
// This function finds and prints the highest score in the array
//************************************************************
void PrintHighest(const int values[], const int size)
// Pre: array values and size assigned
// Post: highest score printed
{
    int highest = values[0];        // assign highest to 1st element
    for (int i = 0; i < size; i++)  // loop thru all elements to find the highest
    {
        if (values[i] > highest)
            highest = values[i];
    }
    cout << "The highest score is " << highest << endl << endl;
}




//************************************************************
// #5 - Function PrintLowest
// This function finds and prints the lowest score in the array
//************************************************************
void PrintLowest(const int values[], const int size)
// Pre: array values and size assigned
// Post: lowest score printed
{
    int lowest = values[0];         // assign lowest to 1st element
    for (int i = 0; i < size; i++)  // loop thru all elements to find the lowest
    {
        if (values[i] < lowest)
            lowest = values[i];
    }
    cout << "The lowest score is " << lowest << endl << endl;
}




//************************************************************
// #6 - Function PrintAverage
// This function finds and prints the average score
//************************************************************
void PrintAverage(const int values[], const int size)
// Pre: array values and size assigned
// Post: average is calculated and printed
{
    int sum = 0;                    // declare sum, initialize to 0
    for (int i = 0; i < size; i++)  // loop thru all elements to find the sum
        sum = sum + values[i];
    // Calculate and display the average
    cout << "The average score is " << fixed << setprecision(2) << float(sum)/float(size) << endl << endl;
}




//************************************************************
// #7 - Function PrintEntry
// This function reads an entry from the user and displays
// its score value and statistics
//************************************************************
void PrintEntry(const int values[], const int size)
// Pre: array values and size assigned
// Post: entry is read, value and statistics are displayed
{
    int entry = 0;              // user entry declared and init to 0
    int counter = 0;            // counter declared and init to 0
    cout << "Please enter entry or row # of score you want:";
    cin >> entry;
    // control loop to disallow entries between 1 and size
    while (entry < 1 || entry > size)
    {
        cout << "Invalid entry. Please select a number between 1 and " << size << endl;
        cin >> entry;
    }
    cout << "Entry # " << entry << " score: " << values[entry-1] << endl << endl;
    // loop through array elements
    for (int i = 0; i < size; i++)
    {
        // count scores that are higher than entry
        if (values[entry-1] < values[i])
            counter++;
    }
    cout << "Score statistics: " << counter << " higher" << endl << endl;
}




//      EXTRA CREDIT
//************************************************************
// #9 - Function SortScores
// This function reads an entry from the user and displays
// its score value and statistics.
// The algorithm was adopted from the original on page 678
//************************************************************
void SortScores(int values[], const int size)
// Pre: array values and size assigned
// Post: scores sorted in descending order
{
    int temp;           // temporary value to hold the contents of value[]
    // straight selection sort loops
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
            if (values[j] > values[i])
            {
                //swap the contents of values[i] and [j]
                temp = values[j];
                values[j] = values[i];
                values[i] = temp;
            }
    }
}




//      EXTRA CREDIT
//************************************************************
// #10 - Function  BinarySearch
// This function searches the array for a particular score.
// BinarySearch is adopted from the original code on page 687.
//************************************************************
void BinarySearch(int values[], const int size)
// Pre: array values and size assigned
// Post: score is entered by user.
//      If found, its position is displayed
//      If not found, so stated
{
    int first = 0;              // Lower index bound
    int last = size - 1;        // Upper index bound
    int middle;                 // Middle index
    int item;                   // Value to search on, user entered
    bool found = false;         // Boolean for found

    SortScores(values, size);   // Sort array first
    cout << "Enter a score: ";
    cin >> item;

    while (last >= first && !found)
    {
        middle = (first + last)/2;      // find middle

        if (item > values[middle])
            last = middle - 1;
            // item is not in [first ... middle]
        else if (item < values[middle])
            first = middle + 1;
            // item is not in [middle ... last]
        else
        {
            // item == middle
            found = true;
            cout << "Score is found in position " << middle + 1 << endl << endl;
        }
    }
    if (found == false)
        // item not found
        cout << "Score is not found." << endl << endl;
}
