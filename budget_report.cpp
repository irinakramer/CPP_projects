//******************************************************
// Irina Kramer
// Project 3A - Monthly Budget
// 11/7/2013
// CS10 - #1368 (S Sarkar)
//******************************************************
// This program compares monthly budget amounts with
// actual spent amounts, and prints out a budget report
// indicating budgeted, spent and over/under budget
// items.
//******************************************************
//******************************************************


#include <iostream>
#include <iomanip>
using namespace std;

// Structure declaration
// MonthlyBudget structure holds members for each budget item
struct MonthlyBudget
{
    int housing,
        utilities,
        household,
        transport,
        food,
        medical,
        insurance,
        ent,
        clothing,
        misc;

    // Default constructor
    // initialize member values to zeros
    MonthlyBudget()
    {
        housing = 0;
        utilities = 0;
        household = 0;
        transport = 0;
        food = 0;
        medical = 0;
        insurance = 0;
        ent = 0;
        clothing = 0;
        misc = 0;
    }
    // Parameterized constructor
    MonthlyBudget (int h1, int u1, int h2, int t1, int f1, int m1, int i1, int e1, int c1, int m2)
    {
        housing = h1;
        utilities = u1;
        household = h2;
        transport = t1;
        food = f1;
        medical = m1;
        insurance = i1;
        ent = e1;
        clothing = c1;
        misc = m2;
    }
};




// Function prototypes
void displayBudget(/*inout*/const MonthlyBudget&, /*out*/int&);
void getExpenses(/*inout*/MonthlyBudget&, /*out*/int&);
void compareExpenses(/*inout*/const MonthlyBudget&,
                     /*inout*/const MonthlyBudget&,
                     /*in*/int, /*in*/int);
void getInput (/*out*/int&, /*in*/string);
void compareItem(/*in*/string, /*in*/int, /*in*/int);





int main()
{
    // Variable declarations
    // budget and spent are objects of MonthlyBudget type
        // budget holds initial budget amounts
    MonthlyBudget budget (580,    //housing
                        150,    //utilities
                        65,     //household
                        50,     //transportation
                        250,    //food
                        30,     //medical
                        100,    //insurance
                        150,    //entertainment
                        75,     //clothing
                        50);    //misc

    MonthlyBudget spent;        // holds default values

    int budgetSum = 0;          // sum of budget members
    int spentSum = 0;           // sum of spent members

    // Function calls
    displayBudget(budget, budgetSum);
    getExpenses(spent, spentSum);
    compareExpenses(budget, spent, budgetSum, spentSum);

    // Ending statement
    if (budgetSum - spentSum >= 0)
        cout << "Congratulations! You were $"
        << setprecision(2) << float(budgetSum - spentSum)
        << " under budget this month." << endl;
    else
        cout << "You are over budget. Revise your spending habits." << endl;

    return 0;
}




//***********************************************************
// Function displayBudget definition
// This function displays initial budget amounts
//***********************************************************
void displayBudget(/*inout*/const MonthlyBudget& items,     // budgeted amount
                   /*out*/int& sum)                         // total budget
// Pre: const MonthlyBudget items and int sum are initialized
// Post: budget items and amounts are formatted and printed
//       sum is calculated and printed
{
    cout << "Here is your monthly budget:" << endl << endl
        << "\nHousing         $" << right << setw(5) << items.housing
        << "\nUtilities       $" << right << setw(5) << items.utilities
        << "\nHousehold       $" << right << setw(5) << items.household
        << "\nTransportation  $" << right << setw(5) << items.transport
        << "\nFood            $" << right << setw(5) << items.food
        << "\nMedical         $" << right << setw(5) << items.medical
        << "\nInsurance       $" << right << setw(5) << items.insurance
        << "\nEntertainment   $" << right << setw(5) << items.ent
        << "\nClothing        $" << right << setw(5) << items.clothing
        << "\nMiscellaneous   $" << right << setw(5) << items.misc
        << endl;
        sum = items.housing
        + items.utilities
        + items.household
        + items.transport
        + items.food
        + items.medical
        + items.insurance
        + items.ent
        + items.clothing
        + items.misc;
    cout << "==============================================="
        << "\nTotal Budgeted  $" << right << setw(5)
        << sum << endl
        << "===============================================" << endl << endl;
}





//***********************************************************
// Function getExpenses definition.
// This function prompts user to enter amounts,
// and calculates the sum.
//***********************************************************
void getExpenses(/*inout*/MonthlyBudget& expItems,  // spent amount
                 /*out*/int& sum)                   // total spent
// Pre: expItems and sum are initialized
// Post: amounts are entered and passed by reference, sum calculated
{
    cout << "Enter actual monthly expenditures for each category" << endl << endl;
        // Function calls
       getInput(expItems.housing, "Rent/mortgage:");
       getInput(expItems.utilities, "Utilities:");
       getInput(expItems.household, "Household:");
       getInput(expItems.transport, "Transportation:");
       getInput(expItems.food, "Food:");
       getInput(expItems.medical, "Medical:");
       getInput(expItems.insurance, "Insurance:");
       getInput(expItems.ent, "Entertainment:");
       getInput(expItems.clothing, "Clothing:");
       getInput(expItems.misc, "Miscellaneous:");

       sum = expItems.housing
           + expItems.utilities
           + expItems.household
           + expItems.transport
           + expItems.food
           + expItems.medical
           + expItems.insurance
           + expItems.ent
           + expItems.clothing
           + expItems.misc;
    cout << endl << endl;
}





//***********************************************************
// Function getInput definition
// This function asks user to enter an amount for each
// expense item. It checks that the amount is positive.
// It is called by the getExpenses function.
//***********************************************************
void getInput (/*out*/int& num,         // amount of expense
               /*in*/string category)   // name of expense category
// Pre: num and category are initialized
// Post: expense amount is received from user
//      and passed to the calling function
{
    cout << left << setw(16) << category << "$ ";
    cin >> num;
    // loop to check for positive numbers
    while (num < 0)
    {
        cout << "ERROR: You must enter a positive number.\n"
            << left << setw(16) << category << "$ ";
        cin >> num;
    }
}





//***********************************************************
// Function compareItem definition
// This function prints one line of the report, including
// expense category, budget, expense and difference.
//***********************************************************
void compareItem(/*in*/string categoryItem, // name of budget category
                 /*in*/int budgetItem,      // budgeted amount
                 /*in*/int spentItem)       // spent amount
// Pre: categoryItem, budgetItem, spentItem are initialized
// Post: one line of the report is formatted and printed,
//      and passed to the calling function.
{
    cout << left << setw(15) << categoryItem << fixed
        << right << setprecision(2) << setw(10) << float(budgetItem)
        << right << setprecision(2) << setw(10) << float(spentItem)
        << right << setprecision(2) << setw(10) << float(budgetItem - spentItem) << endl;
}





//***********************************************************
// Function compareExpenses definition
// This function prints the entire budget report.
//***********************************************************
void compareExpenses(/*inout*/const MonthlyBudget& budget,  // budgeted amount
                     /*inout*/const MonthlyBudget& spent,   // expense amount
                     /*in*/int sum1,                        // total budget
                     /*in*/int sum2)                        // total expenses
// Pre: budget, spent, sum1, sum2 are assigned
// Post: Report is formatted and printed, totals calculated and printed.
{
    cout << right << setw(25) << "Budgeted"
         << right << setw(10) << "Spent"
         << right << setw(12) << "Difference" << endl;
    cout << "===============================================" << endl;
    compareItem("Housing", budget.housing, spent.housing);
    compareItem("Utilities", budget.utilities, spent.utilities);
    compareItem("Household", budget.household, spent.household);
    compareItem("Transportation", budget.transport, spent.transport);
    compareItem("Food", budget.food, spent.food);
    compareItem("Medical", budget.medical, spent.medical);
    compareItem("Insurance", budget.insurance, spent.insurance);
    compareItem("Entertainment", budget.ent, spent.ent);
    compareItem("Clothing", budget.clothing, spent.clothing);
    compareItem("Miscellaneous", budget.misc, spent.misc);
    cout << "===============================================" << endl;
    compareItem("Total", sum1, sum2);
    cout << "===============================================" << endl << endl;
}
