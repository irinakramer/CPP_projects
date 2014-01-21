//******************************************************
// Irina Kramer
// Project 1 - Rocket program
// 10/24/2013
// CS10 - #1368 (S Sarkar)
//******************************************************
// This program draws a rocket shape using stars (*) based
// on user input of three values: width, height and stages.
// Depending on user input of odd or even values,
// the shape of the rocket box can be solid or outlined,
// and the shape of the cone can be pointy or not.


#include <iostream>;
using namespace std;

// Function declarations
// Void function prototypes with data types and direction of data flow
void drawHorizontalLine(/*in*/int);
void drawVerticalLines(/*in*/int, /*in*/int);
void drawSpaces(/*in*/int);
void drawBox(/*in*/int, /*in*/int);
void drawCone(/*in*/int);
void drawRocket(/*in*/int, /*in*/int, /*in*/int);
void getDimensions(/*out*/int&, /*out*/int&, /*out*/int&);



int main()
{
    // Declare variables for rocket width, height and stages.
    int width;
    int height;
    int stages;

    // call to functions
    getDimensions(width, height, stages);   // get user input
    drawRocket(width, height, stages);      // draw the rocket based on user input
    return 0;
}



//********************************************************************
// This function prompts the user to enter three values for the rocket:
// width, height and stages. These values are collected and passed by
// reference to main(), where they will be called as arguments in
// drawRocket function.  This function validates that width and height
// values are between 3 and 15, and stages is non-negative.
// The outgoing value parameters are of data type int.
//********************************************************************
void getDimensions(/*out*/int& value1, /*out*/int& value2, /*out*/int& value3)
// Pre: value1, value2, and value3 are assigned as pass-by-reference types
// Post: User is prompted to enter values:
//      value1 for width,
//      value2 for height,
//      value3 for stages.
// The outgoing values are passed to main() as arguments for drawRocket
{
    cout << "Enter positive values for width, height and stages." << endl
        << "Width and height must be between 3 and 15: " << endl;
    cin >> value1 >> value2 >> value3;
    // Validating values using while loop.
    // The user must enter in-range values in order to proceed.
    while (value1 < 3 || value1 > 15 || value2 < 3 || value2 > 15 || value3 < 0)
    {
        cout << "One or more values are out of range. Please enter correct values: " << endl;
        cin >> value1 >> value2 >> value3;
    }
}



//********************************************************************
// This function draws an entire rocket by connecting a top cone with
// middle boxes (number of boxes is number of stages) and a bottom cone.
// The incoming value parameters are of data type int.
//********************************************************************
void drawRocket(/*in*/int rktWidth, /*in*/int rktHeight, /*in*/int rktStages)
// Pre: rktWidth, rktHeight and rktStages are assigned
// Post: rocket is output
{
    drawCone(rktWidth); // top cone
    // loop to draw number of boxes based on input stages
    for (int count = 1; count <= rktStages; count++)
        drawBox(rktWidth, rktHeight);
    drawCone(rktWidth); // bottom cone
}



//********************************************************************
// This function creates an outline of a cone with one of the two options:
// 1) pointy end - if the value for the width is an odd number;
// 2) two stars ** at the end - if the value for the width is an even number.
// The incoming value parameter is of data type int.
//********************************************************************
void drawCone(/*in*/int coneWidth)
// Pre: coneWidth is assigned
// Post: the cone is output
{
    // calculate coneHeight based on the input coneWidth
    int coneHeight = coneWidth / 2; // if an odd width is divided by 2,
                                    // it will be coerced to the closest int down.
    int coneRow = 0;    // counter for rows

    // if the width is even, draw cone with ** at the end
    if (coneWidth % 2 == 0)
    {
        // loop thru the cone rows until their number exceeds cone height
        for (coneRow = 1; coneRow <= coneHeight; coneRow++)
        {
            // use drawSpaces function,
            // arguments are expressions to calculate spaces to the left side
            // of the cone and inside the cone
            drawSpaces(coneHeight - coneRow); // spaces before the 1st star
            cout << "*";
            drawSpaces((coneRow - 1) * 2); // spaces after the 1st and before 2nd star
            cout << "*" << endl;
        }
    }
    // otherwise the width is odd, so draw cone with a pointy end
    else
    {
            drawSpaces(coneHeight);
            cout << "*" << endl;    // draw single * as the pointy end
        for (coneRow = 1; coneRow <= coneHeight; coneRow++)
        {
            drawSpaces(coneHeight - coneRow);
            cout << "*";
            drawSpaces(coneRow * 2 - 1);
            cout << "*" << endl;
        }
    }
}




//********************************************************************
// This function creates one of the two types of a box:
// 1) outlined box - if the value for the height is an even number;
// 2) solid box - if the value for the height is an odd number.
// The incoming value parameters are of data type int.
//********************************************************************
void drawBox(/*in*/int boxWidth, /*in*/int boxHeight)
// Pre: boxWidth and boxHeight are assigned
// Post: box is output
{
    // if height is odd, draw solid box using only horizontal lines
    if (boxHeight % 2 == 1)
    {
        for (int count = 1; count <= boxHeight; count++)
            drawHorizontalLine(boxWidth);
    }
    // otherwise height is even, so draw outline of the box
    // using both horizontal and vertical lines functions
    else
    {
        drawHorizontalLine(boxWidth);
        drawVerticalLines(boxHeight, boxWidth);
        drawHorizontalLine(boxWidth);
    }
}




//********************************************************************
// This function draws a horizontal line of stars * given the number
// of the incoming value parameters of data type int.
//********************************************************************
void drawHorizontalLine(/*in*/int numStars)
// Pre: numStars is assigned
// Post: the horizontal line is output
{
    for (int count = 1; count <= numStars; count++)
        cout << "*";
    cout << endl;
}



//********************************************************************
// This function draws two vertical lines of stars *, separated by spaces,
// given the number of the incoming value parameters of data type int.
// The spaces are inserted via drawSpace() function.
//********************************************************************
void drawVerticalLines(/*in*/int numRows, /*in*/int numCols)
// Pre: numRows and numCols are assigned
// Post: the horizontal line of spaces is output
{
    for (int rowCount = 1; rowCount <= numRows-2; rowCount++)
    {
        cout << "*";
        drawSpaces(numCols - 2); // calling drawSpaces function
        cout << "*" << endl;
    }
}



//********************************************************************
// This function draws a horizontal line of blank spaces given the
// number of the incoming value parameters of data type int.
//********************************************************************
void drawSpaces(/*in*/int numSpaces)
// Pre: numSpaces is assigned
// Post: the horizontal line of spaces is output
{
    for (int count = 1; count <= numSpaces; count++)
        cout << " ";
}



