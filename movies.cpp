//******************************************************
// Irina Kramer
// Project 5 - 2D Arrays - Movie Ratings Program
// 12/10/2013
// CS10 - #1368 (S Sarkar)
//******************************************************
// This program displays ratings from four movie
// reviewers, lets the user select a menu option,
// then performs ratings calculations and displays
// ratings analytics.
//******************************************************
#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_REVIEWERS = 4;    //Number of rows in reviews array
const int NUM_MOVIES = 6;	    //Number of columns in reviews array

// FUNCTION PROTOTYPES
void displayRatings(/*in*/const int[][NUM_MOVIES], /*in*/const int[], /*in*/int);
void showAverageRatings(/*in*/const int[][NUM_MOVIES], /*in*/const int[], /*in*/int);
void showReviewersHighestRating(/*in*/const int[][NUM_MOVIES], /*in*/const int[], /*in*/int);
void showReviewersLowestRating(/*in*/const int[][NUM_MOVIES], /*in*/const int[], /*in*/int);
void getNewRatings(/*out*/int[][NUM_MOVIES], /*in*/const int[], /*in*/int);

int main()
{
// Variable declarations
// 2D array to store initial ratings
int movieReviews[NUM_REVIEWERS][NUM_MOVIES] = {{3,1,5,2,1,5},
                                                {4,2,1,4,2,4},
                                                {3,1,2,4,4,1},
                                                {5,1,4,2,4,2}};
// 1D array to store movie IDs
int movieID[NUM_MOVIES] = {100,101,102,103,104,105};
int choice;         // user choice of menu options

    do
    {               //program interface with menu options
        cout<<"---------------------------------------------------"<<endl;
        cout<<"2-D ARRAY PROCESSING MENU OPTIONS"<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"1. Display current movie ratings"<<endl;
        cout<<"2. Show the average rating for each movie."<<endl;
        cout<<"3. Show a reviewers highest rated movie. (enter reviewer# 1-4)"<<endl;
        cout<<"4. Show a movies lowest rating. (enter movie# 100-105)"<<endl;
        cout<<"5. Enter new ratings (1-5) for movie# 100-105 for four reviewers"<<endl;
        cout<<"6. Quit program"<<endl;
        cout<<endl<<"Enter your choice:";
        cin>>choice;
        cout << endl;
        switch (choice)
        {
            case 1 : displayRatings(movieReviews, movieID, NUM_REVIEWERS);
                    break;
            case 2 : showAverageRatings(movieReviews, movieID, NUM_REVIEWERS);
                    break;
            case 3 : showReviewersHighestRating(movieReviews, movieID, NUM_REVIEWERS);
                    break;
            case 4 : showReviewersLowestRating(movieReviews, movieID, NUM_REVIEWERS);
                    break;
            case 5 : getNewRatings(movieReviews, movieID, NUM_REVIEWERS);
                    break;
            case 6 : cout << "Array processing test now concluded. Exiting program ....." << endl;
                    return 1;
                    break;
            default : cout << "Please enter a choice from 1 to 6.";
        }
    }while(choice!=6);
 return 0;
}




// FUNCTION DEFINITIONS
//******************************************************
// This function displays current values in the in the
// 2-D array
//******************************************************
void displayRatings(const int ratings[][NUM_MOVIES], const int movie[], int rows)
// Pre: ratings and movie arrays, and # of rows are assigned
// Post: table with movie ratings is displayed
{
    cout << "********************** MOVIE RATINGS ********************" << endl;
    cout << setw(9) << "REVIEWER\\";
    // loop thru 1D array to output movie ID numbers
    for (int m = 0; m < NUM_MOVIES; m++)
        cout << setw(5) << "MV#" << movie[m];
    cout << "\n*********************************************************" << endl;

    // Loop thru 2D array to output all ratings
    for (int i = 0; i < rows; i++)
    {
        cout << setw(5) << "#" << i + 1;
        for (int j = 0; j < NUM_MOVIES; j++)
            cout << setw(8) << ratings[i][j];
        cout << endl;
    }
    cout << endl;
}



//******************************************************
// This function calculates the average for each column
// in the 2-D array
//******************************************************
void showAverageRatings(const int ratings[][NUM_MOVIES], const int movie[], int rows)
// Pre: ratings and movie arrays, and # of rows are assigned
// Post: average rating for each movie is displayed
{
    displayRatings(ratings, movie, rows);   // call to display current values
    cout << "Average rating for each movie:" << endl;
    // column processing
    for (int j = 0; j < NUM_MOVIES; j++)
    {
        int sum = 0; // set sum to 0 for each column
        for (int i = 0; i < rows; i++)
            sum = sum + ratings[i][j];
        cout << "Movie #" << movie[j] << setw(6) << float(sum)/rows << endl;
    }
    cout << endl;
}



//******************************************************
// This function finds the highest value for a row
// in the 2-D array
//******************************************************
void showReviewersHighestRating(const int ratings[][NUM_MOVIES], const int movie[], int rows)
// Pre: ratings and movie arrays, and # of rows are assigned
// Post: user prompted to enter reviewer number,
//      the highest ratings are found and
//      displayed, including multiple movie cases
{
    displayRatings(ratings, movie, rows);  // call to display current values
    int j;              // loop control variable
    int reviewer = 0;   // variable to store user input
    int count = 0;      // counter for highest ratings

    cout << "Enter a reviewer number (1-4), to find the Movie they rated the highest:";
    cin >> reviewer;

    // validate reviewer number range 1 - 4
    while (reviewer < 1 || reviewer > 4)
    {
        cout << "That is an invalid reviewer number." << endl;
        cout << "Enter a reviewer number (1-4), to find the Movie they rated the highest:";
        cin >> reviewer;
    }

    cout << "Reviewer #" << reviewer << " rated Movie #";
    int highest = ratings[reviewer - 1][0]; // initialize highest to 1st element
                                            //  of a given row

    // loop through array to find highest ratings
    for (j = 0; j < NUM_MOVIES; j++)
    {
        if (ratings[reviewer - 1][j] > highest)
            highest = ratings[reviewer - 1][j];
    }

    // loop through array to count all highest occurencies
    count = 0;
    for (j = 0; j < NUM_MOVIES; j++)
    {
        if (ratings[reviewer - 1][j] == highest)
            count++;
    }

    // loop through array to print out highest rated movies
    for (j = 0; j < NUM_MOVIES; j++)
    {
        if (ratings[reviewer - 1][j] == highest)
        {
            cout << movie[j];
            count --;
            if (count == 1)
                cout << " and ";
            else if (count > 1)
                cout << ", ";
            else if (count == 0)
                cout << " as the highest." << endl << endl;
        }
    }
}




//******************************************************
// This function finds the lowest value for a column
// in the 2-D array
//******************************************************
void showReviewersLowestRating(const int ratings[][NUM_MOVIES], const int movie[], int rows)
// Pre: ratings and movie arrays, and # of rows are assigned
// Post: user prompted to enter movie number,
//      the corresponding column is found,
//      the lowest rating is found and displayed.
{
    displayRatings(ratings, movie, rows);    // call to display current values
    int movieNum;       // variable to store user input
    int j;              // loop control variable
    cout << "Enter a movie number (100-105), to find the lowest rating:";
    cin >> movieNum;

    // validate movie numbers
    while (movieNum < 100 || movieNum > 105)
    {
        cout << "That is an invalid movie number." << endl;
        cout << "Enter a movie number (100-105), to find the lowest rating:";
        cin >> movieNum;
    }

    // loop through 1D array to find the index of movieNum
    for (j = 0; j < NUM_MOVIES; j++)
        if (movieNum == movie[j])
            break;
    cout << "Movie #" << movieNum << " lowest rating is ";

    int lowest = ratings[0][j];

    // loop through array column to find the lowest rating
    for (int i = 0; i < rows; i++)
    {
        if (ratings[i][j] < lowest)
            lowest = ratings[i][j];
    }
    cout << lowest << endl << endl;
}




//******************************************************
// This function asks user to enter ratings from
// a keyboard and writes them into the 2D array
//******************************************************
void getNewRatings(int ratings[][NUM_MOVIES], const int movie[], int rows)
// Pre: ratings and movie arrays, and # of rows are assigned
// Post: user is prompted to enter array elements,
//      the elements are stored in a 2D array.
{
    cout << "********DATA ENTRY FOR NEW MOVIE RATINGS ***********" << endl;

    // outer loop
    for (int i = 0; i < rows; i++)
    {
        cout << "****************************************************" << endl;
        cout << "REVIEWER# " << i + 1 << endl;
        cout << "****************************************************" << endl;
        // inner loop
        for (int j = 0; j < NUM_MOVIES; j++)
        {
            cout << "Enter rating (1-5) for movie #" << movie[j] << ": ";
            cin >> ratings[i][j];
            // validate user entry range 1 - 5
            while (ratings[i][j] < 1 || ratings[i][j] > 5)
            {
                cout << "Invalid rating.  It must be from 1-5." << endl;
                cout << "Enter rating (1-5) for movie #" << movie[j] << ": ";
                cin >> ratings[i][j];
            }
        }
    }
    cout << endl;
}
