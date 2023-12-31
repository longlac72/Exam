// Name: Kim Hoang
// Date: 09/23/23
// Description: Chapter 11 Assignment

#include "input.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


const int maxSize = 100;
const int NUM_ELEMENTS = 118;

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

ChemistryElement periodicTable[NUM_ELEMENTS] = { {1, 1.008, " H", "Hydrogen", 0, 8, 0.0, 0.0, 1900, ""}, {2, 1.008, "He", "Helium", 0, 2, 0.0, 0.0, 1900, ""},
                                        {3, 1.008, "Li", " ", 0, 3, 0.0, 0.0, 1900, " "}, {4, 1.008, "Be", " ", 0, 4, 0.0, 0.0, 1900, " "},
                                        {5, 1.008, " B", " ", 0, 6, 0.0, 0.0, 1900, " "}, {6, 1.008, " C", " ", 0, 8, 0.0, 0.0, 1900, " "},
                                        {7, 1.008, " N", " ", 0, 1, 0.0, 0.0, 1900, " "}, {8, 1.008, " O", " ", 0, 1, 0.0, 0.0, 1900, " "}, 
                                        {9, 1.008, " F", " ", 0, 1, 0.0, 0.0, 1900, " "}, {10, 1.008, "Ne", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {11, 1.008, "Na", " ", 0, 1, 0.0, 0.0, 1900, " "}, {12, 1.008, "Mg", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {13, 1.008, "Al", "", 0, 1, 0.0, 0.0, 1900, ""}, {14, 1.008, "Si", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {15, 1.008, " P", "", 0, 1, 0.0, 0.0, 1900, ""}, {16, 1.008, " S", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {17, 1.008, "Cl", " ", 0, 1, 0.0, 0.0, 1900, " "}, {18, 1.008, "Ar", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {19, 1.008, " K", " ", 0, 1, 0.0, 0.0, 1900, " "}, {20, 1.008, "Ca", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {21, 1.008, "Sc", " ", 0, 1, 0.0, 0.0, 1900, " "}, {22, 1.008, "Ti", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {23, 1.008, " V", " ", 0, 1, 0.0, 0.0, 1900, " "}, {24, 1.008, "Cr", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {25, 1.008, "Mn", " ", 0, 1, 0.0, 0.0, 1900, " "}, {26, 1.008, "Fe", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {27, 1.008, "Co", " ", 0, 1, 0.0, 0.0, 1900, " "}, {28, 1.008, "Ni", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {29, 1.008, "Cu", " ", 0, 1, 0.0, 0.0, 1900, " "}, {30, 1.008, "Zn", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {31, 1.008, "Ga", " ", 0, 1, 0.0, 0.0, 1900, " "}, {32, 1.008, "Ge", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {33, 1.008, "As", " ", 0, 1, 0.0, 0.0, 1900, " "}, {34, 1.008, "Se", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {35, 1.008, "Br", " ", 0, 1, 0.0, 0.0, 1900, " "}, {36, 1.008, "Kr", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {37, 1.008, "Rb", " ", 0, 1, 0.0, 0.0, 1900, " "}, {38, 1.008, "Sr", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {39, 1.008, " Y", " ", 0, 1, 0.0, 0.0, 1900, " "}, {40, 1.008, "Zr", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {41, 1.008, "Nb", " ", 0, 1, 0.0, 0.0, 1900, " "}, {42, 1.008, "Mo", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {43, 1.008, "Tc", " ", 0, 1, 0.0, 0.0, 1900, " "}, {44, 1.008, "Ru", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {45, 1.008, "Rh", " ", 0, 1, 0.0, 0.0, 1900, " "}, {46, 1.008, "Pd", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {47, 1.008, "Ag", " ", 0, 1, 0.0, 0.0, 1900, " "}, {48, 1.008, "Cd", " ", 0, 1, 0.0, 0.0, 1900, " "}, 
                                        {49, 1.008, "In", " ", 0, 1, 0.0, 0.0, 1900, " "}, {50, 1.008, "Sn", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {51, 1.008, "Sb", " ", 0, 1, 0.0, 0.0, 1900, " "}, {52, 1.008, "Te", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {53, 1.008, " I", " ", 0, 1, 0.0, 0.0, 1900, " "}, {54, 1.008, "Xe", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {55, 1.008, "Cs", " ", 0, 1, 0.0, 0.0, 1900, " "}, {56, 1.008, "Ba", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {57, 1.008, "La", " ", 0, 1, 0.0, 0.0, 1900, " "}, {58, 1.008, "Ce", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {59, 1.008, "Pr", " ", 0, 1, 0.0, 0.0, 1900, " "}, {60, 1.008, "Nd", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {61, 1.008, "Pm", " ", 0, 1, 0.0, 0.0, 1900, " "}, {62, 1.008, "Sm", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {63, 1.008, "Eu", " ", 0, 1, 0.0, 0.0, 1900, " "}, {64, 1.008, "Gd", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {65, 1.008, "Tb", " ", 0, 1, 0.0, 0.0, 1900, " "}, {66, 1.008, "Dy", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {67, 1.008, "Ho", " ", 0, 1, 0.0, 0.0, 1900, " "}, {68, 1.008, "Er", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {69, 1.008, "Tm", " ", 0, 1, 0.0, 0.0, 1900, " "}, {70, 1.008, "Yb", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {71, 1.008, "Lu", " ", 0, 1, 0.0, 0.0, 1900, " "}, {72, 1.008, "Hf", " ", 0, 1, 0.0, 0.0, 1900, " "}, 
                                        {73, 1.008, "Ta", " ", 0, 1, 0.0, 0.0, 1900, " "}, {74, 1.008, " W", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {75, 1.008, "Re", " ", 0, 1, 0.0, 0.0, 1900, " "}, {76, 1.008, "Os", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {77, 1.008, "Ir", " ", 0, 1, 0.0, 0.0, 1900, " "}, {78, 1.008, "Pt", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {79, 1.008, "Au", " ", 0, 1, 0.0, 0.0, 1900, " "}, {80, 1.008, "Hg", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {81, 1.008, "Tl", " ", 0, 1, 0.0, 0.0, 1900, " "}, {82, 1.008, "Pb", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {83, 1.008, "Bi", " ", 0, 1, 0.0, 0.0, 1900, " "}, {84, 1.008, "Po", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {85, 1.008, "At", " ", 0, 1, 0.0, 0.0, 1900, " "}, {86, 1.008, "Rn", " ", 0, 1, 0.0, 0.0, 1900, " "},
                                        {87, 1.008, "Fr", "", 0, 1, 0.0, 0.0, 1900, ""}, {88, 1.008, "Ra", "", 0, 1, 0.0, 0.0, 1900, ""}, 
                                        {89, 1.008, "Ac", "", 0, 1, 0.0, 0.0, 1900, ""}, {90, 1.008, "Th", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {91, 1.008, "Pa", "", 0, 1, 0.0, 0.0, 1900, ""}, {92, 1.008, " U", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {93, 1.008, "Np", "", 0, 1, 0.0, 0.0, 1900, ""}, {94, 1.008, "Pu", "", 0, 1, 0.0, 0.0, 1900, ""}, 
                                        {95, 1.008, "Am", "", 0, 1, 0.0, 0.0, 1900, ""}, {96, 1.008, "Cm", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {97, 1.008, "Bk", "", 0, 1, 0.0, 0.0, 1900, ""}, {98, 1.008, "Cf", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {99, 1.008, "Es", "", 0, 1, 0.0, 0.0, 1900, ""}, {100, 1.008, "Fm", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {101, 1.008, "Md", "", 0, 1, 0.0, 0.0, 1900, ""}, {102, 1.008, "No", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {103, 1.008, "Lr", "", 0, 1, 0.0, 0.0, 1900, ""}, {104, 1.008, "Rf", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {105, 1.008, "Db", "", 0, 1, 0.0, 0.0, 1900, ""}, {106, 1.008, "Sg", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {107, 1.008, "Bh", "", 0, 1, 0.0, 0.0, 1900, ""}, {108, 1.008, "Hs", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {109, 1.008, "Mt", "", 0, 1, 0.0, 0.0, 1900, ""}, {110, 1.008, "Ds", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {111, 1.008, "Rg", "", 0, 1, 0.0, 0.0, 1900, ""}, {112, 1.008, "Cn", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {113, 1.008, "Nh", "", 0, 1, 0.0, 0.0, 1900, ""}, {114, 1.008, " H", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {115, 1.008, "Mc", "", 0, 1, 0.0, 0.0, 1900, ""}, {116, 1.008, "Lv", "", 0, 1, 0.0, 0.0, 1900, ""},
                                        {117, 1.008, "Ts", "", 0, 1, 0.0, 0.0, 1900, ""}, {118, 1.008, "Og", "", 0, 1, 0.0, 0.0, 1900, ""} };

// Prototypes
char menuOption();
void displayPeriodicTable(bool bySymbol);
int advanceBinaryFileOperationMenu();
int dynamicAllocatedArrayMenu();
int vectorMenu();
void searchAndUpdateAnElement();
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
        case 'x':
        case 'X':
            exit(1);
            break;
        case 'a':
        case 'A':
            advanceBinaryFileOperationMenu();
            break;
        case 'b':
        case 'B':
            dynamicAllocatedArrayMenu();
            break;
        case 'c':
        case 'C':
            vectorMenu();
            break;
        default: 
            //std::cout << "\t\tERROR - Invalid option. Please re-enter."; 
            break;
        }
        
    } while (true);

    return EXIT_SUCCESS;
}

// menuOption() function
// Precondition: Displays the menu of options to user and accepts input.
// Postcondition: Displays the menu of options to user and accepts input.

char menuOption()
{
    system("cls");
    
    displayPeriodicTable(true);

    std::cout << "\n\tCMPR121 - Exam 1 (Chapter 12 .. 1) by Kim Hoang (9/23/2023)";
    std::cout << "\n\t" << string(90, char(205));
    std::cout << "\n\tA. Advance Binary File Operation (chapter 12) 50 pts";
    std::cout << "\n\tB. Dynamic Allocated Array (chapter 9) 50 pts";
    std::cout << "\n\tC. Vector (array)          (chapter 7) 25Pts Xtra";
    std::cout << "\n\t" << string(90, char(196));
    std::cout << "\n\tx. exit";
    std::cout << "\n\t" << string(90, char(205));

    return  inputChar("\n\tOption: ");
}

void displayElement(ChemistryElement element)
{
    std::cout << "\n\t" << "Atomic Number "  << "\t\t\t\t: " << element.atomicNumber;
    std::cout << "\n\t" << "Symbol " << "\t\t\t\t\t: "  << element.symbol;
    std::cout << "\n\t" << "Name " << "\t\t\t\t\t: " << element.name;
    std::cout << "\n\t" << "Atomic Mass " << "\t\t\t\t: "  << element.atomicMass;
    std::cout << "\n\t" << "Chemical Group Block " << "\t\t\t: " << element.chemicalGroupBlock;
    std::cout << "\n\t" << "Standard State " << "\t\t\t\t: " << element.standardState;
    std::cout << "\n\t" << "Boiling point " << "\t\t\t\t: " << element.boilingPoint - 273.15 << " C (" << element.meltingPoint << " K)";
    std::cout << "\n\t" << "Melting point " << "\t\t\t\t: " << element.meltingPoint - 273.15 << " C (" << element.meltingPoint << " K)";
    std::cout << "\n\t" << "Year discovered " << "\t\t\t: " << element.yearDiscovered;
    std::cout << "\n\t" << "Discoverer " << "\t\t\t\t: "  << element.Discoverer;
}

string displayElementsFromBinaryFile()
{
    string fileName = inputString("\n\tEnter the binary data file name: ", false);
    ifstream readBinary(fileName, ios::binary | ios::out);
    int numberOfElementRead = 0;
    std::cout << "\n";
    while (readBinary.good() && numberOfElementRead < NUM_ELEMENTS) {
        ChemistryElement element;
        readBinary.read((char*)&element, sizeof(ChemistryElement));
        numberOfElementRead++;
        std::cout << "\n\n\tElement (struct) # " << numberOfElementRead << " - " << sizeof(ChemistryElement) << " Bytes";
        std::cout << "\n\t" << string(60, char(196));
        displayElement(element);
    }
    readBinary.close();
    return fileName;
}
int elementExists(string element)
{
    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        if (periodicTable[i].symbol == element.c_str())
        {
            return i;
        }
    }
    return -1;
}

void editAtomicNumber(ChemistryElement& element)
{
    int atomicNumber = inputInteger("\n\t Enter Atomic Number: ", 1, 118);
    element.atomicNumber = atomicNumber;
}

void editSymbol(ChemistryElement & element)
{
    string symbol = inputString("\n Enter Symbol: ", false);
    while (symbol.length() < 1 || symbol.length() > 3)
    {
        symbol = inputString("\n Enter Symbol: ", false);
    }
    strncpy_s(element.symbol, symbol.c_str(), symbol.length());
}
void editAtomicMass(ChemistryElement& element)
{
    double atomicMass = inputDouble("\n\t Enter Atomic Mass: ", 0, true);
    element.atomicMass = atomicMass;
}
void editName(ChemistryElement & element)
{
    char name[25] = "";
    string nameStr = inputString("\n\tEnter Name", false);
    strcpy_s(name, sizeof(nameStr.c_str()), nameStr.c_str());
    while (!validateString(name, 1, 25))
    {
        std::cout << "\n Invalide Name.  Enter Name:";
        strcpy_s(name, nameStr.size(), nameStr.c_str());
    }
    strcpy_s(element.name, sizeof(name), name);
}

void writeElementToFile(string fileName, ChemistryElement updatedElement, int elementPosition)
{
    
    std::fstream s(fileName, std::ios_base::binary | std::ios_base::in | std::ios_base::out);
    if (s.good())
    {
        s.seekp(elementPosition * sizeof(ChemistryElement), std::ios_base::beg);
        s.write((char*)&updatedElement, sizeof(ChemistryElement));
        s.close();
        std::cout << "\n\tElement has been successfully updated";
    }
    else
    {
        std::cout << "\n\tElement could not be updated because " << fileName << " could not be opened \n";
    }
    
}

ChemistryElement editElementPropertiesMenu(ChemistryElement element, int elementPosition, bool& saveUpdates)
{
    int option = -2; //inputInteger("\n\tOption: ", -1, 10);
    while ((option == -2))
    {
        std::cout << "\n";
        std::cout << "\n\t Edit Element Properties Menu";
        std::cout << "\n\t" << string(90, char(205));
        std::cout << "\n\t 1. Atomic Number";
        std::cout << "\n\t 2. Symbol";
        std::cout << "\n\t 3. Name";
        std::cout << "\n\t 4. Atomic Mass";
        std::cout << "\n\t 5. Chemical Groupd Block";
        std::cout << "\n\t 6. Standard State";
        std::cout << "\n\t 7. Melting point";
        std::cout << "\n\t 8. Boiling point";
        std::cout << "\n\t 9. Discovered year";
        std::cout << "\n\t 10. Discovered By";
        std::cout << "\n\t" << string(90, char(196));
        std::cout << "\n\t-1. return without committing the updates";
        std::cout << "\n\t 0. Committing the updates and return";
        std::cout << "\n\t" << string(90, char(205));
        option = inputInteger("\n\tOption: ", -1, 10);
        while (option < -1 || option > 10)
        {
            option = inputInteger("\n\tOption: ", -1, 10);
        }

        switch (option)
        {
        case 1:
            editAtomicNumber(element);
            option = -2;
            break;
        case 2:
            editSymbol(element);
            option = -2;
            break;
        case 3:
            editName(element);
            option = -2;
            break;
        case 4:
            editAtomicMass(element);
            option = -2;
            break;

        case 5:
            option = -2;
            break;
        case 6:
            option = -2;
            break;
        case 7:
            option = -2;
            break;
        case 8:
            option = -2;
            break;
        case 9:
            option = -2;
            break;
        case 10:
            option = -2;
            break;

        case 0:
            saveUpdates = true;
            
            break;

        case -1:
            std::cout << "\nElement has NOT been updated.";
            break;

        default:
            break;
        }
    }

    return element;

}

void searchAndUpdateAnElement(string fileName)
{
    if (fileName.empty())
    {
        std::cout << "\n\tERROR: no binary file has been specified from step #1.\n";
      
        return;
    }
    string symbol = inputString("\n\tEnter an Element Symbol to search and update:", false);   
    std::cout << "\n\t" << string(90, char(196));
    int elementIndex = -1;
    
    ifstream readBinary(fileName, ios::binary | ios::out | ios::in);
    if (readBinary.good())
    {
        readBinary.seekg(0, readBinary.end);
        ChemistryElement elements[NUM_ELEMENTS];
        streampos length = readBinary.tellg();
        size_t numOfElements = length / sizeof(ChemistryElement);
        readBinary.seekg(0, readBinary.beg);
        readBinary.read((char*)&elements, sizeof(ChemistryElement)*NUM_ELEMENTS);

        bool saveUpdate = false;
        for (int i = 0; i < numOfElements; i++)
        {
            ChemistryElement element;
            readBinary.seekg(0, readBinary.beg + (i * sizeof(ChemistryElement)));
            readBinary.read((char*)&element, sizeof(ChemistryElement));
            readBinary.close();
            if (element.symbol == symbol)
            {
                displayElement(element);
                ChemistryElement updated = editElementPropertiesMenu(element, i, saveUpdate);
                if (saveUpdate)
                {
                    writeElementToFile(fileName, updated, i);
                }
                break;
            }
        }
    }  
    
}


void searchAndUpdateAnElement(ChemistryElement * elements, int numOfElements, bool clearScreen, bool bySymbol)
{
    if (clearScreen)
    {
        system("cls");
    }
    if (numOfElements == 0)
    {
        std::cout << "\n\tBinary file has not been loaded into the array.  Please perform step #1 first";
        std::cout << "\n\t";
        
        return;
    }
    string prompt = "Symbol";
    if (!bySymbol)
    {
        prompt = "Name";
    }
    string search = inputString("\n\tEnter an Element " + prompt + "  to search and update:", false);
    int elementIndex = -1;

    bool saveUpdate = false;
    for (int i = 0; i < numOfElements; i++)
    {
        ChemistryElement element = elements[i];
        if (element.symbol == search)
        {
            displayElement(element);
            ChemistryElement updatedElement = editElementPropertiesMenu(element, i, saveUpdate);
            if (saveUpdate)
            {
                elements[i] = updatedElement;
                std::cout << "\n\tElement has been successfully update \n";
                system("pause");
            }
            break;
        }
    }
    
    std::cout << "\n\tERROR: Element with " << prompt  << search << ", cannot be found. \n ";
    system("pause");

}

void searchAndUpdateAnElementByAtomicNumber(ChemistryElement* elements, int numOfElements, bool clearScreen)
{
    if (clearScreen)
    {
        system("cls");
    }

    int atomic = inputInteger("\n\tEnter an Atomic Number (1.." + to_string(numOfElements) + ")  to search and update:", true);
    int elementIndex = -1;

    bool saveUpdate = false;
    for (int i = 0; i < numOfElements; i++)
    {
        ChemistryElement element = elements[i];
        if (element.atomicNumber == atomic)
        {
            displayElement(element);
            ChemistryElement updatedElement = editElementPropertiesMenu(element, i, saveUpdate);
            if (saveUpdate)
            {
                elements[i] = updatedElement;
                std::cout << "\n\tElement has been successfully updated \n";
                system("pause");
                return;
            }
            break;
        }
    }

    std::cout << "\n\tERROR: Element with Atomic Number, " << atomic << ", cannot be found. \n ";
    system("pause");

}

int advanceBinaryFileOperationMenu()
{
    int selection = -1;
    string fileName = "";
    do {
        system("cls");
        std::cout << "\tAdvance Binary File Operations Menu";
        std::cout << "\n\t" << string(90, char(205));
        std::cout << "\n\t1. Read and Display ALL elements from binary data file ";
        std::cout << "\n\t2. Search and update an element by Symbol from binary file";
        std::cout << "\n\t" << string(90, char(196));
        std::cout << "\n\t0. Return to main menu";
        std::cout << "\n\t" << string(90, char(205));

        selection = inputInteger("\n\tOption: ", 0, 2);

        switch (selection)
        {
        case 1:
            fileName = displayElementsFromBinaryFile();
            std::cout << "\n\n     ";
            system("pause");
            break;

        case 2:
            searchAndUpdateAnElement(fileName);
            std::cout << "\n\n     ";
            system("pause");
            break;

        case 0:
            std::cout << "\n";
            system("pause");
            break;
        }
        
    } while (selection != 0);

    return 1;// inputInteger("\n\tOption: ", 0, 2);
}

void selectionSort(int atomics[], ChemistryElement elements[],  int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (atomics[j] < atomics [min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
        {
            swap(atomics[min_idx], atomics[i]);
            swap(elements[min_idx], elements[i]);
        }
    }

}




void readStoreBinaryFileToSortedArray(ChemistryElement *& elements, int & numOfElements)
{
    string fileName = inputString("\n\tEnter the binary data file name: ", false);
    
    int atomics[NUM_ELEMENTS];

    ifstream unsortedFile(fileName, ios::binary | ios::in);
    numOfElements = 0;
    ChemistryElement * dynamicArray = NULL;
    if (unsortedFile.good())
    {
        unsortedFile.seekg(0, unsortedFile.end);
        streampos length = unsortedFile.tellg();
        numOfElements = length / sizeof(ChemistryElement);
        elements = new ChemistryElement[numOfElements];
        unsortedFile.seekg(0, unsortedFile.beg);
        unsortedFile.read((char*)elements, sizeof(ChemistryElement) * numOfElements);
        unsortedFile.close();
        selectionSort(atomics, elements, numOfElements);
        std::cout << "\n\tSUCCESS: " << numOfElements << " (struct) data from " << fileName << " have been stored into dynamic allocated array and sorted by Atomic number\n\n";

    }
    else
    {
        std::cout << "\n\tERROR: binary data file, " << fileName << ", could be not found";
    }
    
    system("pause");
}

void readStoreBinaryFileToVector(vector<ChemistryElement> & elements)
{
    string fileName = inputString("\n\tEnter the binary data file name: ", false);
    ifstream unsortedFile(fileName, ios::binary | ios::in);
    
    size_t numOfElements = 0;
    if (unsortedFile.good())
    {
        unsortedFile.seekg(0, unsortedFile.end);
        streampos length = unsortedFile.tellg();
        numOfElements = length / sizeof(ChemistryElement);
        elements.resize(numOfElements);
        unsortedFile.seekg(0, unsortedFile.beg);
        unsortedFile.read((char*)elements.data(), sizeof(ChemistryElement) * numOfElements);
        unsortedFile.close();
        cout << "\n\tSUCCESS: " << numOfElements << "(struct) binary data from " << fileName << " has been stored in unsorted array.";
    }
    else
    {
        std::cout << "\n\tERROR: binary data file, " << fileName << ", cannot be found.";
    }
    cout << "\n\t";
    system("pause");
    
}

void writeArrayToBinaryFile(ChemistryElement* elements, int numOfElement)
{
    if (elements != NULL)
    {
        string fileName = inputString("\nEnter the binary file name to write to:", false);
        ofstream outFile;
        outFile.open(fileName, ios::out);
        while (!outFile.is_open())
        {
            fileName = inputString("\nEnter the binary file name to write to:", false);
            
        }
        outFile.write((char*)elements, sizeof(ChemistryElement) * numOfElement);
        std::cout << "\n\t SUCCESS: " << numOfElement << " (struct) from array have been written to the binary data file, " << fileName << ".\n";
        system("pause");
    }
    else
    {
        std::cout << "\nBinary file has not been loaded";
    }
}
int dynamicAllocatedArrayMenu()
{
    int selection = -1;
    ChemistryElement* elements = NULL;
    int count = 0;
    do 
    {
        system("cls");
        displayPeriodicTable(false);
        std::cout << "\n\t\Dynamic Allocated Array Menu \n";
        std::cout << "\t" << string(90, char(205));
        std::cout << "\n\t1. Read, store ALL elements from binary file into the sorted array";
        std::cout << "\n\t2. Display ALL elements from the array";
        std::cout << "\n\t3. Search and update an element by Atomic Number for the array";
        std::cout << "\n\t4. Write All elements from the array into the binary file";
        std::cout << "\n\t" << string(90, char(196));
        std::cout << "\n\t0. Return to main menu";
        std::cout << "\n\t" << string(90, char(205));
        selection = inputInteger("\n\tOption: ", 0, 4);
        

        while (selection < 0 || selection > 4)
        {
            selection = inputInteger("\n\tOption: ", 0, 2);
        }

        switch (selection)
        {
        case 1:
            readStoreBinaryFileToSortedArray(elements, count);
            break;

        case 2:
            if (elements == NULL)
            {
                std::cout << "\n Binary file has not been loaded into the array.  Please perform step 1 first";
                break;
            }
            for (int i = 0; i < count; i++)
            {
                std::cout << "\n\n\tarray element[" << i << "]";
                std::cout << "\n\t" << string(90, char(196));
                displayElement(elements[i]);
            }
            std::cout << "\n ";
            system("pause");
            break;
        case 3:
           
            //displayPeriodicTable(false);
            searchAndUpdateAnElementByAtomicNumber(elements, count, false);

            break;
        case 4:
            writeArrayToBinaryFile(elements, count);

            break;

        case 0:
            delete elements;
            elements = NULL;
            std::cout << "\n";
            system("pause");
            break;
        }
        
    } while (selection != 0);
    
    return 1;
}
int vectorMenu()
{
    int selection = -1;
    vector<ChemistryElement> elements;
    
    do
    {
        system("cls");
        displayPeriodicTable(true);
        
        std::cout << "\n\tVector (array) Menu";
        std::cout << "\n\t" << string(60, char(205));
        std::cout << "\n\t1. Read, store ALL elements from binary file into the unsorted vector";
        std::cout << "\n\t2. Display ALL elements from the vector";
        std::cout << "\n\t3. Search and update an element by Name for the vector";
        std::cout << "\n\t4. Write All elements from the vector into the binary file";
        std::cout << "\n\t" << string(60, char(196));
        std::cout << "\n\t0. Return to main menu";
        std::cout << "\n\t" << string(60, char(205));
        selection = inputInteger("\n\tOption: ", 0, 4);


        while (selection < 0 || selection > 4)
        {
            selection = inputInteger("\n\tOption: ", 0, 2);
        }

        switch (selection)
        {
        case 1:
            readStoreBinaryFileToVector(elements);
            break;

        case 2:
            if (elements.size() == 0)
            {
                std::cout << "\n\tBinary file has not been loaded into the array.  Please perform step #1 first";
                std::cout << "\n\t";
                system("pause");
                break;
            }
            for (size_t i = 0; i < elements.size(); i++)
            {
                std::cout << "\nvector element[" << i << "]";
                std::cout << "\n\t" << string(60, char(205));
                displayElement(elements[i]);
            }
            std::cout << "\n";
            system("pause");
            break;
        case 3:
            searchAndUpdateAnElement(elements.data(), elements.size(), false, false);
            system("pause");
            break;
        case 4:
            writeArrayToBinaryFile(elements.data(), elements.size());
            std::cout << "\n";
            system("pause");
            break;

        case 0:
            
            break;
        }

    } while (selection != 0);
    return 1;
}

void drawEmptyElements(int numEle, bool bySymbol)
{
    string empty = "     ";
    if (bySymbol)
    {
        empty = "     ";
    }
    for (int i = 0; i < numEle; i++)
    {
        std::cout << empty;
    }
}

void drawElements(int startingAtomicNum, int howManyEle, bool bySymbol)
{
    
    for (int i = 0; i < howManyEle; i++)
    {
        int index = startingAtomicNum + i - 1;
        string atomicNumberStr = "";
        switch (periodicTable[index].chemicalGroupBlock)
        {
        case 1:
            std::cout << "\033[1;31m";
            break;
        case 2:
            std::cout << "\033[1;32m";
            break;
        case 3:
            std::cout << "\033[1;33m";
            break;
        case 4:
            std::cout << "\033[1;34m";
            break;
        case 5:
            std::cout << "\033[1;35m";
            break;
        case 6:
            std::cout << "\033[1;36m";
            break;
        case 7:
            std::cout << "\033[1;37m";
            break;
        case 8:
            std::cout << "\033[1;38m";
            break;
        }
        if (bySymbol)
        {
            std::cout << "[ " << periodicTable[index].symbol << "]";
        }
        else
        {
            if (periodicTable[index].atomicNumber < 10)
            {
                atomicNumberStr = "  " + to_string(periodicTable[index].atomicNumber);
            }
            else if (periodicTable[index].atomicNumber < 100)
            {
                atomicNumberStr = " " + to_string(periodicTable[index].atomicNumber);
            }
            else
            {
                atomicNumberStr = "" + to_string(periodicTable[index].atomicNumber);
            }
            std::cout << "[" << atomicNumberStr  << "]";
        }
        
    }
}

void displayPeriodicTable(bool bySymbol)
{
    int currentAtomic = 0;
    if (bySymbol)
    {
        std::cout << "\t\t\tPERIODIC TABLE OF ELEMENTS BY SYMBOL \n\n";
    }
    else
    {
        std::cout << "\t\t\tPERIODIC TABLE OF ELEMENTS BY ATOMIC NUMBER \n\n";
    }
    for (int row = 0; row < 10; row++)
    {
        std::cout << "\t";
        if (row == 0)
        { 
            drawElements(periodicTable[currentAtomic].atomicNumber, 1, bySymbol);
            currentAtomic++;
            drawEmptyElements(16, bySymbol);
            drawElements(periodicTable[currentAtomic].atomicNumber, 1, bySymbol);
            currentAtomic++;
            std::cout << "\n";
        }
        else if (row == 1 || row == 2)
        {
            drawElements(periodicTable[currentAtomic].atomicNumber, 2, bySymbol);
            currentAtomic += 2;
            drawEmptyElements(10, bySymbol);
            drawElements(periodicTable[currentAtomic].atomicNumber, 6, bySymbol);
            currentAtomic += 6;
            std::cout << "\n";
        }
        else if (row == 3 || row == 4)
        {
            drawElements(periodicTable[currentAtomic].atomicNumber, 18, bySymbol);
            currentAtomic += 18;
            std::cout << "\n";
        }
        else if (row == 5 || row == 6)
        {
            drawElements(periodicTable[currentAtomic].atomicNumber, 2, bySymbol);
            currentAtomic += 2;
            if (row == 5)
            {
                std::cout << "  *  ";
                drawElements(72, 15, bySymbol);
                currentAtomic += 15;
               
            }
            else
            {
                std::cout << "  ** ";
                drawElements(104, 15, bySymbol);
                currentAtomic += 15;
            }
            std::cout << "\n";
            
        }
        else if (row == 7)
        {
            std::cout << "\n";
        }
        else if (row == 8)
        {
            drawEmptyElements(2, bySymbol);
            std::cout << "  *  ";
            std::cout << "\033[1;34m";
            drawElements(57, 15, bySymbol);
            std::cout << "\033[0m\n";
        }
        else if (row == 9)
        {
            drawEmptyElements(2, bySymbol);
            std::cout << "  ** ";
            std::cout << "\033[1;30m";
            drawElements(89, 15, bySymbol);
            std::cout << "\033[0m\n";
        }

    }
}



int inputIntegerWithDecimalCheck(string prompt, bool posNeg) {
    double input;
    do {
        std::cout << prompt;
        cin >> input;

        if (input != static_cast<int>(input)) {
            std::cout << "\nERROR: Invalid input. Must be an integer value.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {

            return inputInteger(prompt, posNeg);
        }
    } while (true);
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
        std::cout << "Invalid input: " << inputStr << ".  Please enter a " << numberOfDigits << " digit number \n";
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
