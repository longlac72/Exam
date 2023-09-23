// Name: Kim Hoang
// Date: 09/23/23
// Description: Chapter 11 Assignment

#include "input.h"
#include <iostream>
using namespace std;


const int maxSize = 100;

struct ChemistryElement
{
    int atomicNumber = 0;
    double atomicMass = 0.0;
    char symbol[3];
    char name[25];
    int standardState = 0;
    int chemicalGroupBlock = 0;
    double meltingPoint = 0.0; //in K degree
    double boilingPoint = 0.0; // in K degree
    int yearDiscovered = 1900;
    char Discoverer[100] = "";
};

// Prototypes
int menuOption();
struct MovieData;
struct CompanyData;



//bool validateNumericString(char inputStr[maxSize], int numberOfDigits, bool checkForLen);
bool validateString(char name[100], int minLen, int maxLen);

// Main Function
// Precondition: User must enter one of the ints in the switch case
// Postcondition: Calls the appropriate function based on user input. If user inputs invalid option, program returns an error msg

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0:
            exit(1);
            break;
        case 2:
            
            break;
        case 3:
            
            break;
       
        case 12:
            break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

// menuOption() function
// Precondition: Displays the menu of options to user and accepts input.
// Postcondition: Displays the menu of options to user and accepts input.

int menuOption()
{
    system("cls");
    cout << "\n\tChapter 11 - Assignments by Kim Hoang";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t2. Challenge 2 - Movie Profit";
    cout << "\n\t3. Challenge 3 - Corporate Sales Data";
    cout << "\n\t5. Challenge 5 - Weather Statistics Modification";
    cout << "\n\t6. Challenge 6 - Soccer Scores";
    cout << "\n\t8. Challenge 8 - Search Function for Customer Accounts";
    cout << "\n\t12. Challenge 12 - Course Grade";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t0. exit";
    cout << "\n\t" << string(60, char(205));

    return inputInteger("\n\tOption: ", 0, 12);
}





int inputIntegerWithDecimalCheck(string prompt, bool posNeg) {
    double input;
    do {
        cout << prompt;
        cin >> input;

        if (input != static_cast<int>(input)) {
            cout << "\nERROR: Invalid input. Must be an integer value.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {

            return inputInteger(prompt, posNeg);
        }
    } while (true);
}

bool validateDate(string date)
{
    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    if (month < 1 || month > 12)
    {
        cout << "Month has to be between 1 and 12.  ";
        return false;
    }
    if (year < 1900 || year > 2023)
    {
        cout << "Year has to be between 1900 and 2023.  ";
        return false;
    }
    if (day < 1)
    {
        cout << "Day cannot be less than 1.  ";
        return false;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31)
        {
            cout << "Day cannot be greater than 31 for this month.  ";
            return false;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            cout << "Day cannot be greater than 30 for this month.  ";
            return false;
        }
    }
    else
    {
        if (day > 29)
        {
            cout << "Day cannot be greater than 29 for this month.  ";
            return false;
        }
    }
    return true;
}



char determineGrade(double average)
{
    if (average >= 91.0 && average <= 100.0) {
        return 'A';
    }
    else if (average >= 81.0 && average <= 90.0) {
        return 'B';
    }
    else if (average >= 71.0 && average <= 80.0) {
        return 'C';
    }
    else if (average >= 61.0 && average <= 70.0) {
        return 'D';
    }
    else {
        return 'F';
    }
}




bool validateNumericString(char inputStr[maxSize], int numberOfDigits, bool checkForLen)
{
    bool valid = true;
    for (int i = 0; i < numberOfDigits; i++)
    {
        if (!isdigit(inputStr[i]))
        {
            valid = false;
            break;
        }
    }
    if (checkForLen && strlen(inputStr) != numberOfDigits)
    {

        valid = false;
    }

    if (!valid)
    {
        cout << "Invalid input: " << inputStr << ".  Please enter a " << numberOfDigits << " digit number \n";
    }
    return valid;
}


/*  This function check to make sure the input length is between the min and the max.  
* It also checks to make sure the input is not a blank line
*/
bool validateString(char input [100], int minLen, int maxLen)
{
    int numOfSpaces = 0;
    if (strlen(input) < minLen || strlen(input) > maxLen)
    {
        return false;
    }

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            numOfSpaces++;
        }
    }

    if (numOfSpaces == strlen(input))
    {
        return false;
    }
    return true;
}