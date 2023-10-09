// Name: Kim Hoang
// Date: 09/23/23
// Description: Exam 1

#include "input.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


const int maxSize = 100;
const int NUM_ELEMENTS = 118;

string ChemicalGroupBlock[11] = { "unknown", "Nonmetal", "Noble Gas", "Alkali Metal", "Alkaline Earth Metal", "Post-transition Metal", "Metalloid", "Halogen", "Nonmetal", "Lanthanide", "Actinide" };
string StandardState[4] = { "unknown", "Gas", "Liquid", "Solia" };

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

ChemistryElement periodicTable[NUM_ELEMENTS] = { {1, 1.008, "H", "Hydrogen", 1, 1, 20.28, -259.14, 1766, "Henry Cavendish"}, {2, 4.003, "He", "Helium", 1, 18, -268.93, -272.15, 1895, "William Ramsay"},
                                        {3, 6.941, "Li", "Lithium", 3, 1, 453.69, 1615, 1817, "Johan August Arfwedson"},
                                        {4, 9.012, "Be", "Beryllium", 3, 2, 1287.2, 2742, 1798, "Louis Nicolas Vauquelin"},
                                        {5, 10.811, "B", "Boron", 3, 13, 2350, 4200, 1808, "Humphry Davy"},
                                        {6, 12.011, "C", "Carbon", 3, 14, 3500, 4827, 0, "Ancient"},
                                        {7, 14.007, "N", "Nitrogen", 1, 15, -210.0, -195.8, 1772, "Daniel Rutherford"},
                                        {8, 15.999, "O", "Oxygen", 3, 16, -218.4, -182.95, 1774, "Carl Wilhelm Scheele"},
                                        {9, 18.998, "F", "Fluorine", 1, 17, -220.0, -188.14, 1886, "Henri Moissan"},
                                        {10, 20.180, "Ne", "Neon", 1, 18, -248.59, -246.04, 1898, "William Ramsay"},
                                        {11, 22.990, "Na", "Sodium", 3, 1, 97.72, 883, 1807, "Sir Humphry Davy"},
                                        {12, 24.305, "Mg", "Magnesium", 3, 2, 650.6, 1363, 1828, "Joseph Louis Gay-Lussac"},
                                        {13, 26.982, "Al", "Aluminum", 3, 13, 660.37, 2792, 1825, "Friedrich W?hler"},
                                        {14, 28.086, "Si", "Silicon", 3, 14, 1414, 3538, 1823, "J?ns Jakob Berzelius"},
                                        {15, 30.974, "P", "Phosphorus", 3, 15, 44.2, 553.7, 1660, "Hennig Brand"},
                                        {16, 32.065, "S", "Sulfur", 3, 16, 119.2, 717.8, 0, "Unknown"},
                                        {17, 35.453, "Cl", "Chlorine", 1, 17, -101.5, -34.04, 1774, "Carl Wilhelm Scheele"},
                                        {18, 39.948, "Ar", "Argon", 1, 18, -189.4, -185.8, 1894, "William Ramsay"},
                                        {19, 39.098, "K", "Potassium", 3, 1, 336.5, 1032, 1807, "Sir Humphry Davy"},
                                        {20, 40.078, "Ca", "Calcium", 3, 2, 1115, 1757, 1808, "Sir Humphry Davy"},
                                        {21, 44.956, "Sc", "Scandium", 3, 3, 1814, 3345, 1879, "Lars Fredrik Nilson"},
                                        {22, 47.867, "Ti", "Titanium", 3, 4, 1941, 3560, 1791, "William Gregor"},
                                        {23, 50.942, "V", "Vanadium", 3, 5, 2183, 3407, 1801, "Andr?s Manuel del R?o"},
                                        {24, 51.996, "Cr", "Chromium", 3, 6, 2180, 3076, 1797, "Louis Nicolas Vauquelin"},
                                        {25, 54.938, "Mn", "Manganese", 3, 7, 1519, 2334, 1774, "Johan Gottlieb Gahn"},
                                        {26, 55.845, "Fe", "Iron", 3, 8, 1811, 3134, 0, "Meteorites"},
                                        {27, 58.933, "Co", "Cobalt", 3, 9, 1768, 3157, 1735, "George Brandt"},
                                        {28, 58.693, "Ni", "Nickel", 3, 10, 1768, 3003, 1751, "Axel Fredrik Cronstedt"},
                                        {29, 63.546, "Cu", "Copper", 3, 11, 1357, 2835, 0, "Unknown"},
                                        {30, 65.409, "Zn", "Zinc", 3, 12, 692.68, 907, 0, "Unknown"},
                                        {31, 69.723, "Ga", "Gallium", 3, 13, 302.9, 2403, 1875, "Paul ?mile Lecoq de Boisbaudran"},
                                        {32, 72.640, "Ge", "Germanium", 3, 14, 1211.4, 3106, 1886, "Clemens Winkler"},
                                        {33, 74.922, "As", "Arsenic", 3, 15, 1090, 887, 0, "Unknown"},
                                        {34, 78.971, "Se", "Selenium", 3, 16, 221.1, 494.5, 0, "Unknown"},
                                        {35, 79.904, "Br", "Bromine", 2, 17, -7.22, 59.5, 1826, "Carl Jacob L?wig"},
                                        {36, 83.798, "Kr", "Krypton", 1, 18, -157.4, -153.4, 1898, "Sir William Ramsay"},
                                        {37, 85.467, "Rb", "Rubidium", 3, 1, 39.3, 961, 1861, "Robert Bunsen"},
                                        {38, 87.62, "Sr", "Strontium", 3, 2, 1050, 1384, 1790, "Adair Crawford"},
                                        {39, 88.906, "Y", "Yttrium", 3, 3, 1799, 3380, 1794, "Johan Gadolin"},
                                        {40, 91.224, "Zr", "Zirconium", 3, 4, 2128, 4371, 1789, "Martin Heinrich Klaproth"},
                                        {41, 92.906, "Nb", "Niobium", 3, 5, 2750, 5027, 1801, "Charles Hatchett"},
                                        {42, 95.96, "Mo", "Molybdenum", 3, 6, 2623, 4912, 1782, "Carl Wilhelm Scheele"},
                                        {43, 98, "Tc", "Technetium", 3, 7, 2430, 4538, 1937, "Carlo Perrier, Emilio Segre"},
                                        {44, 101.07, "Ru", "Ruthenium", 3, 8, 2607, 4345, 1828, "Karl Klaus"},
                                        {45, 102.906, "Rh", "Rhodium", 3, 9, 2237, 3968, 1803, "William Hyde Wollaston"},
                                        {46, 106.42, "Pd", "Palladium", 3, 10, 1828, 3236, 1803, "William Hyde Wollaston"},
                                        {47, 107.8682, "Ag", "Silver", 3, 11, 1234.95, 2435, 0, "Unknown"},
                                        {48, 112.411, "Cd", "Cadmium", 3, 12, 594.22, 1040, 1817, "Friedrich Stromeyer"},
                                        {49, 114.818, "In", "Indium", 3, 13, 429.8, 2345, 1863, "Ferdinand Reich"},
                                        {50, 118.71, "Sn", "Tin", 3, 14, 505.08, 2875, 0, "Unknown"},
                                        {51, 121.76, "Sb", "Antimony", 3, 15, 903, 1807,},
                                        {52, 127.6, "Te", "Tellurium", 3, 16, 722.66, 1307, 1782, "Franz-Joseph M?ller von Reichenstein"},
                                        {53, 126.905, "I", "Iodine", 3, 17, 114.7, 461, 1811, "Bernard Courtois"},
                                        {54, 131.293, "Xe", "Xenon", 1, 18, -111.9, -108.1, 1898, "Morris Travers"},
                                       {55, 132.905, "Cs", "Cesium", 3, 1, 301.7, 944, 1860, "Robert Bunsen, Gustav Kirchhoff"},
                                        {56, 137.327, "Ba", "Barium", 3, 2, 1000, 2118, 1808, "Sir Humphry Davy"},
                                        {57, 138.905, "La", "Lanthanum", 3, 3, 1193, 3737, 1839, "Carl Gustaf Mosander"},
                                        {58, 140.116, "Ce", "Cerium", 3, 3, 1071, 3697, 1803, "Martin Heinrich Klaproth, J?ns Jakob Berzelius, Wilhelm Hisinger"},
                                        {59, 140.907, "Pr", "Praseodymium", 3, 3, 1208, 3793, 1885, "Carl Auer von Welsbach"},
                                        {60, 144.242, "Nd", "Neodymium", 3, 3, 1297, 3347, 1885, "Carl Auer von Welsbach"},
                                        {61, 145, "Pm", "Promethium", 0, 3, 1315, 3273, 1945, "Chien Shiung Wu"},
                                        {62, 150.36, "Sm", "Samarium", 3, 3, 1345, 2067, 1879, "Lecoq de Boisbaudran, F.A. Giesel"},
                                        {63, 151.984, "Eu", "Europium", 3, 3, 1099, 1802, 1901, "Eug?ne-Anatole Demar?ay"},
                                        {64, 157.25, "Gd", "Gadolinium", 3, 3, 1585, 3546, 1880, "Jean Charles Galissard de Marignac"},
                                        {65, 158.925, "Tb", "Terbium", 3, 3, 1629, 3503, 1843, "Carl Gustaf Mosander"},
                                        {66, 162.5, "Dy", "Dysprosium", 3, 3, 1680, 2840, 1886, "Paul ?mile Lecoq de Boisbaudran"},
                                        {67, 164.930, "Ho", "Holmium", 3, 3, 1747, 2973, 1878, "Marc Delafontaine"},
                                        {68, 167.259, "Er", "Erbium", 3, 3, 1770, 3141, 1843, "Carl Gustaf Mosander"},
                                        {69, 168.934, "Tm", "Thulium", 3, 3, 1818, 2223, 1879, "Per Teodor Cleve"},
                                        {70, 173.045, "Yb", "Ytterbium", 3, 3, 1092, 1469, 1878, "Jean Charles Galissard de Marignac"},
                                        {71, 174.966, "Lu", "Lutetium", 3, 3, 1925, 3675, 1907, "Georges Urbain, Charles James"},
                                        {72, 178.49, "Fr", "Hafnium", 3, 4, 2506, 4876, 1923, "Dirk Coster, George de Hevesy"},
                                        {73, 180.947, "Ra", "Tantalum", 3, 5, 3290, 5731, 1802, "Anders Gustaf Ekeberg"},
                                        {74, 183.84, "W", "Tungsten", 3, 6, 3695, 5828, 1783, "Carl Wilhelm Scheele"},
                                        {75, 186.207, "Re", "Rhenium", 3, 7, 3459, 5869, 1925, "Walter Noddack, Ida Tacke, Otto Berg"},
                                        {76, 190.23, "Os", "Osmium", 3, 8, 3306, 5285, 1803, "Smithson Tennant"},
                                        {77, 192.217, "Ir", "Iridium", 3, 9, 2719, 4701, 1803, "Smithson Tennant"},
                                        {78, 195.084, "Pt", "Platinum", 3, 10, 2041, 4098, 0, "Unknown"},
                                        {79, 196.966, "Au", "Gold", 3, 11, 1337.33, 3129, 0, "Unknown"},
                                        {80, 200.592, "Hg", "Mercury", 3, 12, 234.32, 629.88, 0, "Unknown"},
                                        {81, 204.383, "Tl", "Thallium", 3, 13, 577, 1746, 1861, "William Crookes"},
                                        {82, 207.2, "Pb", "Lead", 3, 14, 600.61, 2022, 0, "Unknown"},
                                        {83, 208.980, "Bi", "Bismuth", 3, 15, 544.55, 1837},
                                        {84, 210, "Po", "Polonium", 3, 16, 527, 1235, 1898, "Marie Curie, Pierre Curie"},
                                        {85, 210, "At", "Astatine", 3, 17, 575, 610, 1940, "Dale R. Corson, Emilio Segr?, Kenneth Ross MacKenzie"},
                                        {86, 222, "Rn", "Radon", 3, 18, 202, 211.4, 1900, "Friedrich Ernst Dorn"},
                                        {87, 223, "Fr", "Francium", 0, 1, 300, 950, 1939, "Marguerite Perey"},
                                        {88, 226, "Ra", "Radium", 3, 2, 973, 2010, 1898, "Marie Curie, Pierre Curie"},
                                        {89, 227, "Ac", "Actinium", 3, 3, 1323, 3471, 1899, "Friedrich Oskar Giesel"},
                                        {90, 232.038, "Th", "Thorium", 3, 4, 2115, 5061, 1828, "J?ns Jakob Berzelius"},
                                        {91, 231.036, "Pa", "Protactinium", 3, 5, 1841, 4300, 1913, "Kasimir Fajans, Oswald Helmuth G?hring"},
                                        {92, 238.029, "U", "Uranium", 3, 6, 1405.3, 4404, 1789, "Martin Heinrich Klaproth"},
                                        {93, 237, "Np", "Neptunium", 3, 7, 913, 4175, 1940, "Edwin McMillan, Philip H. Abelson"},
                                        {94, 244, "Pu", "Plutonium", 3, 8, 912.5, 3505, 1940, "Glenn T. Seaborg"},
                                        {95, 243, "Am", "Americium", 3, 9, 1449, 2880, 1944, "Glenn T. Seaborg"},
                                        {96, 247, "Cm", "Curium", 3, 10, 1613, 3383, 1944, "Glenn T. Seaborg"},
                                        {97, 247, "Bk", "Berkelium", 3, 11, 1259, 2900, 1949, "Glenn T. Seaborg"},
                                        {98, 251, "Cf", "Californium", 3, 12, 1173, 1743, 1950, "Glenn T. Seaborg"},
                                        {99, 252, "Es", "Einsteinium", 3, 13, 1133, 1269, 1952, "Albert Ghiorso"},
                                        {100, 257, "Fm", "Fermium", 3, 14, 1800, 1890, 1952, "Albert Ghiorso"},
                                        {101, 258, "Md", "Mendelevium", 3, 15, 1100, 1035, 1955, "Albert Ghiorso"},
                                        {102, 259, "No", "Nobelium", 3, 16, 1100, 430, 1958, "Albert Ghiorso"},
                                        {103, 262, "Lr", "Lawrencium", 3, 17, 1900, 2600, 1961, "Albert Ghiorso"},
                                        {104, 267, "Rf", "Rutherfordium", 3, 4, 2400, 5800, 1969, "Joint Institute for Nuclear Research (JINR)"},
                                        {105, 270, "Db", "Dubnium", 3, 5, 0, 0, 1967, "Joint Institute for Nuclear Research (JINR)"},
                                        {106, 269, "Sg", "Seaborgium", 3, 6, 0, 0, 1974, "Albert Ghiorso"},
                                        {107, 270, "Bh", "Bohrium", 3, 7, 0, 0, 1981, "Gesellschaft f?r Schwerionenforschung (GSI)"},
                                        {108, 277, "Hs", "Hassium", 3, 8, 0, 0, 1984, "Gesellschaft f?r Schwerionenforschung (GSI)"},
                                        {109, 278, "Mt", "Meitnerium", 3, 9, 0, 0, 1982, "Gesellschaft f?r Schwerionenforschung (GSI)"},
                                        {110, 281, "Ds", "Darmstadtium", 3, 10, 0, 0, 1994, "Gesellschaft f?r Schwerionenforschung (GSI)"},
                                        {111, 282, "Rg", "Roentgenium", 3, 11, 0, 0, 1994, "Gesellschaft f?r Schwerionenforschung (GSI)"},
                                        {112, 285, "Cn", "Copernicium", 3, 12, 0, 0, 1996, "Gesellschaft f?r Schwerionenforschung (GSI)"},
                                        {113, 286, "Nh", "Nihonium", 3, 13, 0, 0, 2003, "RIKEN, JINR"},
                                        {114, 289, "Fl", "Flerovium", 3, 14, 0, 0, 1998, "Joint Institute for Nuclear Research (JINR)"},
                                        {115, 288, "Mc", "Moscovium", 3, 15, 0, 0, 2003, "RIKEN, JINR"},
                                        {116, 293, "Lv", "Livermorium", 3, 16, 0, 0, 2000, "Joint Institute for Nuclear Research (JINR)"},
                                        {117, 294, "Ts", "Tennessine", 3, 17, 0, 0, 2010, "Joint Institute for Nuclear Research (JINR), Oak Ridge National Laboratory (ORNL)"},
                                        {118, 294, "Og", "Oganesson", 3, 18, 0, 0, 2002, "Joint Institute for Nuclear Research (JINR)"} };

// Prototypes
char menuOption();
void displayPeriodicTable(bool bySymbol);
int advanceBinaryFileOperationMenu();
int dynamicAllocatedArrayMenu();
int vectorMenu();
void searchAndUpdateAnElement();

// Function: validateString(char name[100], int minLen, int maxLen)
// Precondition: User must enter a valid string
// Postcondition: Returns true if the string is valid, otherwise returns false

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
            cout << "\t\tERROR - Invalid input. Must be an alphabet character.\n\t";
            system("pause");
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

    cout << "\n\tCMPR121 - Exam 1 (Chapter 12 .. 1) by Kim Hoang (9/23/2023)";
    cout << "\n\t" << string(90, char(205));
    cout << "\n\tA. Advance Binary File Operation (chapter 12) 50 pts";
    cout << "\n\tB. Dynamic Allocated Array (chapter 9) 50 pts";
    cout << "\n\tC. Vector (array)          (chapter 7) 25Pts Xtra";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tx. exit";
    cout << "\n\t" << string(90, char(205));

    return  inputChar("\n\tOption: ");
}

// Function: displayElement(ChemistryElement element)
// Precondition: User must enter a valid elementa
// Postcondition: Displays the element

void displayElement(ChemistryElement element)
{
    cout << "\n\t" << "Atomic Number " << "\t\t\t\t: " << element.atomicNumber;
    cout << "\n\t" << "Symbol " << "\t\t\t\t\t: " << element.symbol;
    cout << "\n\t" << "Name " << "\t\t\t\t\t: " << element.name;
    cout << "\n\t" << "Atomic Mass " << "\t\t\t\t: " << element.atomicMass << " u";
    if (element.chemicalGroupBlock > -1 && element.chemicalGroupBlock < 11)
    {
        cout << "\n\t" << "Chemical Group Block " << "\t\t\t: " << ChemicalGroupBlock[element.chemicalGroupBlock];
    }
    if (element.standardState > -1 && element.standardState < 4)
    {
        cout << "\n\t" << "Standard State " << "\t\t\t\t: " << StandardState[element.standardState];
    }
    cout << "\n\t" << "Melting point " << "\t\t\t\t: " << element.meltingPoint - 273.15 << "\370" << "C (" << element.meltingPoint << " K)";
    cout << "\n\t" << "Boiling point " << "\t\t\t\t: " << element.boilingPoint - 273.15 << "\370" << "C (" << element.meltingPoint << " K)";
    cout << "\n\t" << "Year discovered " << "\t\t\t: " << element.yearDiscovered;
    cout << "\n\t" << "Discoverer " << "\t\t\t\t: " << element.Discoverer;
}

// Function: displayElementsFromBinaryFile()
// Precondition: User must enter a valid file name
// Postcondition: Displays the elements from the binary file

string displayElementsFromBinaryFile()
{
    string fileName = inputString("\n\tEnter the binary data file name: ", false);
    ifstream readBinary(fileName, ios::binary | ios::out);
    int numberOfElementRead = 0;
    cout << "\n";
    if (readBinary.good())
    {
        while (readBinary.good() && numberOfElementRead < NUM_ELEMENTS) {
            ChemistryElement element;
            readBinary.read((char*)&element, sizeof(ChemistryElement));
            numberOfElementRead++;
            cout << "\n\n\tElement (struct) # " << numberOfElementRead << " - " << sizeof(ChemistryElement) << " Bytes";
            cout << "\n\t" << string(60, char(196));
            displayElement(element);
        }
        readBinary.close();
    }
    else
    {
        cout << "\tERROR: Binary data file, " << fileName << ", cannot be found.";
    }
    return fileName;
}

// Function: elementExists(string element)
// Precondition: User must enter a valid element
// Postcondition: Returns the index of the element if it exists, otherwise returns -1

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

// Function: editAtomicNumber(ChemistryElement& element)
// Precondition: User must enter a valid atomic number
// Postcondition: Edits the atomic number of the element

void editAtomicNumber(ChemistryElement& element)
{
    int atomicNumber = inputInteger("\n\t Enter Atomic Number: ", 1, 118);
    element.atomicNumber = atomicNumber;
}

// Function: editSymbol(ChemistryElement& element)
// Precondition: User must enter a valid symbol
// Postcondition: Edits the symbol of the element

void editSymbol(ChemistryElement& element)
{
    string symbol = inputString("\n Enter Symbol: ", false);
    while (symbol.length() == 0 || symbol.length() > 2)
    {
        symbol = inputString("\nSymbol cannot be longer than 2 characters.  Enter Symbol: ", false);
    }
    strncpy_s(element.symbol, symbol.c_str(), symbol.length());
}

// Function: editAtomicMass(ChemistryElement& element)
// Precondition: User must enter a valid atomic mass
// Postcondition: Edits the atomic mass of the element

void editAtomicMass(ChemistryElement& element)
{
    double atomicMass = inputDouble("\n\t Enter Atomic Mass: ", 0, true);
    element.atomicMass = atomicMass;
}

// Function: editName(ChemistryElement& element)
// Precondition: User must enter a valid name
// Postcondition: Edits the name of the element

void editName(ChemistryElement& element)
{
    string nameStr = inputString("\n\tEnter Name: ", false);

    while (nameStr.length() > 25)
    {
        nameStr = inputString("\n\tElement name cannot be longer than 25 characters.  Enter Name: ", false);
    }
    strcpy_s(element.name, nameStr.length() + 1, nameStr.c_str());
}

// Function: editChemicalGroupBlock(ChemistryElement& element)
// Precondition: User must enter a valid chemical group block
// Postcondition: Edits the chemical group block of the element5 

void editChemicalGroupBlock(ChemistryElement& element)
{
    int chemicalGroupBlock = inputInteger("\n\t Enter the Chemical Group Block (0 - unknown, 1 - Nonmetal, 2 - Nobel Gas, 3 - Alkali Metal, 4 - Alkaline Earth Metal, 5 - Post-transition Metal, 6 - Metalloid, 7 - Halogen, 8 - Nonmetal, 9 - Lanthanide, or 10 - Actinide) : ", 0, 10);
    element.chemicalGroupBlock = chemicalGroupBlock;
}

// Function: editStandardState(ChemistryElement& element)
// Precondition: User must enter a valid standard state
// Postcondition: Edits the standard state of the element

void editStandardState(ChemistryElement& element)
{
    int standardState = inputInteger("\n\t Enter the Standard State (0 - unknown, 1 - Gas, 2 - Liquid, or 3 - Solid) : ", 0, 3);
    element.standardState = standardState;
}

// Function: editMeltingPoint(ChemistryElement& element)
// Precondition: User must enter a valid melting point
// Postcondition: Edits the melting point of the element

void editMeltingPoint(ChemistryElement& element)
{
    double meltingPoint = inputDouble("\n\t Enter the Melting Point (K): ");
    element.meltingPoint = meltingPoint;
}

// Function: editBoilingPoint(ChemistryElement& element)
// Precondition: User must enter a valid boiling point
// Postcondition: Edits the boiling point of the element

void editBoilingPoint(ChemistryElement& element)
{
    double boilingPoint = inputDouble("\n\t Enter the Boiling Point (K): ");
    element.boilingPoint = boilingPoint;
}

// Function: editYearDiscovered(ChemistryElement& element)
// Precondition: User must enter a valid year discovered
// Postcondition: Edits the year discovered of the element

void editYearDiscovered(ChemistryElement& element)
{
    int yearDiscovered = inputInteger("\n\t Enter Year Discovered: ", 0, 3000);
    element.yearDiscovered = yearDiscovered;
}

// Function: editDiscoverer(ChemistryElement& element)
// Precondition: User must enter a valid discoverer
// Postcondition: Edits the discoverer of the element

void editDiscoverer(ChemistryElement& element)
{
    string discovererStr = inputString("\n\tEnter the Discoverer(s): ", false);
    while (discovererStr.length() > 100)
    {
        discovererStr = inputString("\n\tDiscoverer(s) cannot be longger than 100 characters.  Ennter the Discoverer(s)", false);
    }
    strcpy_s(element.Discoverer, discovererStr.length() + 1, discovererStr.c_str());

}

// Function: writeElementToFile(string fileName, ChemistryElement updatedElement, int elementPosition)
// Precondition: User must enter a valid file name
// Postcondition: Writes the element to the file

void writeElementToFile(string fileName, ChemistryElement updatedElement, int elementPosition, bool showResults)
{

    //fstream s(fileName, ios_base::binary | ios_base::in | ios_base::out);
    ofstream outFile;
    outFile.open(fileName, ios_base::binary | ios_base::in | ios_base::out);

    if (!outFile.good())
    {
        outFile.open(fileName, ios_base::binary | ios_base::out);
    }

    if (outFile.good())
    {
        outFile.seekp(elementPosition * sizeof(ChemistryElement), ios_base::beg);
        outFile.write((char*)&updatedElement, sizeof(ChemistryElement));
        outFile.close();
        if (showResults)
            cout << "\n\tElement has been successfully updated";
    }
    else
    {
        if (showResults)
            cout << "\n\tElement could not be updated because " << fileName << " could not be opened \n";
    }

}

// Function: editElementPropertiesMenu(ChemistryElement element, int elementPosition, bool& saveUpdates)
// Precondition: User must enter a valid option
// Postcondition: Edits the element properties

ChemistryElement editElementPropertiesMenu(ChemistryElement element, int elementPosition, bool& saveUpdates)
{
    int option = -2; //inputInteger("\n\tOption: ", -1, 10);
    while ((option == -2))
    {
        cout << "\n";
        cout << "\n\t Edit Element Properties Menu";
        cout << "\n\t" << string(90, char(205));
        cout << "\n\t 1. Atomic Number";
        cout << "\n\t 2. Symbol";
        cout << "\n\t 3. Name";
        cout << "\n\t 4. Atomic Mass";
        cout << "\n\t 5. Chemical Group Block";
        cout << "\n\t 6. Standard State";
        cout << "\n\t 7. Melting point";
        cout << "\n\t 8. Boiling point";
        cout << "\n\t 9. Discovered year";
        cout << "\n\t 10. Discovered By";
        cout << "\n\t" << string(90, char(196));
        cout << "\n\t-1. return without committing the updates";
        cout << "\n\t 0. Committing the updates and return";
        cout << "\n\t" << string(90, char(205));
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
            editChemicalGroupBlock(element);
            option = -2;
            break;
        case 6:
            editStandardState(element);
            option = -2;
            break;
        case 7:
            editMeltingPoint(element);
            option = -2;
            break;
        case 8:
            editBoilingPoint(element);
            option = -2;
            break;
        case 9:
            editYearDiscovered(element);
            option = -2;
            break;
        case 10:
            editDiscoverer(element);
            option = -2;
            break;

        case 0:
            saveUpdates = true;

            break;

        case -1:
            cout << "\nElement has NOT been updated.";
            break;

        default:
            break;
        }
    }

    return element;

}

// Function: searchAndUpdateAnElement(string fileName)
// Precondition: User must enter a valid file name
// Postcondition: Searches and updates the element

void searchAndUpdateAnElement(string fileName)
{
    if (fileName.empty())
    {
        cout << "\n\tERROR: no binary file has been specified from step #1.\n";

        return;
    }

    string symbol = inputString("\n\tEnter an Element Symbol to search and update: ", false);

    int elementIndex = -1;

    fstream readBinary(fileName, ios::binary | ios::in);
    if (readBinary.good())
    {
        bool found = false;
        readBinary.seekg(0, readBinary.end);
        ChemistryElement elements[NUM_ELEMENTS];
        streampos length = readBinary.tellg();
        size_t numOfElements = length / sizeof(ChemistryElement);

        bool saveUpdate = false;
        for (int i = 0; i < numOfElements; i++)
        {
            ChemistryElement element;
            readBinary.seekp(i * sizeof(ChemistryElement));
            readBinary.read((char*)&element, sizeof(ChemistryElement));

            if (element.symbol == symbol)
            {
                cout << "\n\t" << string(90, char(196));

                displayElement(element);
                ChemistryElement updated = editElementPropertiesMenu(element, i, saveUpdate);
                if (saveUpdate)
                {
                    writeElementToFile(fileName, updated, i, true);
                }
                found = true;
                break;
            }
        }
        readBinary.close();
        if (found == false)
        {
            cout << "\n\tERROR: Element cannot be found from binary file.";
        }
    }
    else
    {
        cout << "\n\tERROR: binary data file, " << fileName << ", cannot be found.";
    }


}

// Function: searchAndUpdateAnElement()
// Precondition: User must enter a valid option
// Postcondition: Searches and updates the element

void searchAndUpdateAnElement(ChemistryElement* elements, int numOfElements, bool clearScreen, bool bySymbol)
{
    if (clearScreen)
    {
        system("cls");
    }
    if (numOfElements == 0)
    {
        cout << "\n\tBinary file has not been loaded into the array.  Please perform step #1 first";
        cout << "\n\t";

        return;
    }
    string prompt = "Symbol";
    if (!bySymbol)
    {
        prompt = "Name";
    }
    string search = inputString("\n\tEnter an Element " + prompt + " to search and update:", false);
    int elementIndex = -1;

    bool saveUpdate = false;
    for (int i = 0; i < numOfElements; i++)
    {
        ChemistryElement element = elements[i];
        if (element.name == search)
        {
            displayElement(element);
            ChemistryElement updatedElement = editElementPropertiesMenu(element, i, saveUpdate);
            if (saveUpdate)
            {
                elements[i] = updatedElement;
                cout << "\n\tElement has been successfully updated \n\n";
                system("pause");
            }
            return;
        }
    }

    cout << "\n\tERROR: Element with " << prompt << ", " << search << ", cannot be found. \n ";
    system("pause");

}

// Function: searchAndUpdateAnElementByAtomicNumber(ChemistryElement* elements, int numOfElements, bool clearScreen)
// Precondition: User must enter a valid option
// Postcondition: Searches and updates the element

void searchAndUpdateAnElementByAtomicNumber(ChemistryElement* elements, int numOfElements, bool clearScreen)
{
    if (clearScreen)
    {
        system("cls");
    }

    if (elements == NULL)
    {
        cout << "\n Binary file has not been loaded into the array.  Please perform step #1 first.\n" << "\n";
        system("pause");
    }

    int atomic = inputInteger("\n\tEnter an Atomic Number (1.." + to_string(numOfElements) + ")  to search and update: ", 1, numOfElements);
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
                cout << "\n\tElement has been successfully updated \n";
                system("pause");
                return;
            }
            else
            {
                cout << "\n";
                system("pause");
                return;
            }
            break;
        }
    }

    /*   cout << "\n\tERROR: Element with Atomic Number, " << atomic << ", cannot be found. \n ";
       system("pause");*/

}

// Function: advanceBinaryFileOperationMenu()
// Precondition: User must enter a valid option
// Postcondition: Displays the menu of options to user and accepts input.

int advanceBinaryFileOperationMenu()
{
    int selection = -1;
    string fileName = "";
    do {
        system("cls");
        cout << "\tAdvance Binary File Operations Menu";
        cout << "\n\t" << string(90, char(205));
        cout << "\n\t1. Read and Display ALL elements from binary data file ";
        cout << "\n\t2. Search and update an element by Symbol from binary file";
        cout << "\n\t" << string(90, char(196));
        cout << "\n\t0. Return to main menu";
        cout << "\n\t" << string(90, char(205));

        selection = inputInteger("\n\tOption: ", 0, 2);

        switch (selection)
        {
        case 1:
            fileName = displayElementsFromBinaryFile();
            cout << "\n\n     ";
            system("pause");
            break;

        case 2:
            searchAndUpdateAnElement(fileName);
            cout << "\n\n     ";
            system("pause");
            break;

        case 0:
            cout << "\n";
            system("pause");
            break;
        }

    } while (selection != 0);

    return 1;// inputInteger("\n\tOption: ", 0, 2);
}

// Function: selectionSort(int atomics[], ChemistryElement elements[],  int n)
// Precondition: User must enter a valid option
// Postcondition: Sorts the elements by atomic number

void selectionSort(int atomics[], ChemistryElement elements[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (atomics[j] < atomics[min_idx])
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

// Function: readStoreBinaryFileToSortedArray(ChemistryElement *& elements, int & numOfElements)
// Precondition: User must enter a valid option
// Postcondition: Reads and stores the binary file to sorted array

void readStoreBinaryFileToSortedArray(ChemistryElement*& elements, int& numOfElements)
{
    string fileName = inputString("\n\tEnter the binary data file name: ", false);

    int atomics[NUM_ELEMENTS];

    ifstream unsortedFile(fileName, ios::binary | ios::in);
    numOfElements = 0;

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
        cout << "\n\tSUCCESS: " << numOfElements << " (struct) data from " << fileName << " have been stored into dynamic allocated array and sorted by Atomic number\n\n";

    }
    else
    {
        cout << "\n\tERROR: binary data file, " << fileName << ", could be not found\n";
    }

    system("pause");
}

// Function: readStoreBinaryFileToVector(vector<ChemistryElement> & elements)
// Precondition: User must enter a valid option
// Postcondition: Reads and stores the binary file to vector

void readStoreBinaryFileToVector(vector<ChemistryElement>& elements)
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
        cout << "\n\tERROR: binary data file, " << fileName << ", cannot be found.";
    }
    cout << "\n\t";
    system("pause");

}

// Function: writeArrayToBinaryFile(ChemistryElement* elements, int numOfElement)
// Precondition: User must enter a valid option
// Postcondition: Writes the array to binary file

void writeArrayToBinaryFile(ChemistryElement* elements, int numOfElement)
{
    if (elements != NULL)
    {
        string fileName = inputString("\nEnter the binary file name to write to: ", false);
        for (int i = 0; i < numOfElement; i++)
        {
            writeElementToFile(fileName, elements[i], i, false);
        }
        /*ofstream outFile;
        outFile.open(fileName, ios::out);
        while (!outFile.is_open())
        {
            fileName = inputString("\nEnter the binary file name to write to:", false);

        }
        outFile.write((char*)elements, sizeof(ChemistryElement) * numOfElement);

        outFile.close();*/
        cout << "\n\t SUCCESS: " << numOfElement << " (struct) from array have been written to the binary data file, " << fileName << ".\n";
        system("pause");
    }
    else
    {
        cout << "\nBinary file has not been loaded";
    }
}

// Function: dynamicAllocatedArrayMenu()
// Precondition: User must enter a valid option
// Postcondition: Displays the menu of options to user and accepts input.

int dynamicAllocatedArrayMenu()
{
    int selection = -1;
    ChemistryElement* elements = NULL;
    int count = 0;
    do
    {
        system("cls");
        displayPeriodicTable(false);
        cout << "\n\t\Dynamic Allocated Array Menu \n";
        cout << "\t" << string(90, char(205));
        cout << "\n\t1. Read, store ALL elements from binary file into the sorted array";
        cout << "\n\t2. Display ALL elements from the array";
        cout << "\n\t3. Search and update an element by Atomic Number for the array";
        cout << "\n\t4. Write All elements from the array into the binary file";
        cout << "\n\t" << string(90, char(196));
        cout << "\n\t0. Return to main menu";
        cout << "\n\t" << string(90, char(205));
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
                cout << "\n Binary file has not been loaded into the array.  Please perform step 1 first.\n" << "\n";
                system("pause");
                break;
            }
            for (int i = 0; i < count; i++)
            {
                cout << "\n\n\tarray element[" << i << "]";
                cout << "\n\t" << string(90, char(196));
                displayElement(elements[i]);
            }
            cout << "\n ";
            system("pause");
            break;
        case 3:
            if (elements == NULL)
            {
                cout << "\n Binary file has not been loaded into the array.  Please perform step 1 first.\n" << "\n";
                system("pause");
                break;
            }
            searchAndUpdateAnElementByAtomicNumber(elements, count, false);

            break;
        case 4:
            if (elements == NULL)
            {
                cout << "Binary file has not been loaded into the array.  Please perform step 1 first.\n" << "\n";
                system("pause");
                break;
            }
            writeArrayToBinaryFile(elements, count);

            break;

        case 0:
            delete elements;
            elements = NULL;
            cout << "\n";
            system("pause");
            break;
        }

    } while (selection != 0);

    return 1;
}

// Function: vectorMenu()
// Precondition: User must enter a valid option
// Postcondition: Displays the menu of options to user and accepts input.

int vectorMenu()
{
    int selection = -1;
    vector<ChemistryElement> elements;

    do
    {
        system("cls");
        displayPeriodicTable(true);

        cout << "\n\tVector (array) Menu";
        cout << "\n\t" << string(60, char(205));
        cout << "\n\t1. Read, store ALL elements from binary file into the unsorted vector";
        cout << "\n\t2. Display ALL elements from the vector";
        cout << "\n\t3. Search and update an element by Name for the vector";
        cout << "\n\t4. Write All elements from the vector into the binary file";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t0. Return to main menu";
        cout << "\n\t" << string(60, char(205));
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
                cout << "\n\tBinary file has not been loaded into the array.  Please perform step #1 first";
                cout << "\n\t";
                system("pause");
                break;
            }
            for (size_t i = 0; i < elements.size(); i++)
            {
                cout << "\nvector element[" << i << "]";
                cout << "\n\t" << string(60, char(205));
                displayElement(elements[i]);
            }
            cout << "\n";
            system("pause");
            break;
        case 3:
            searchAndUpdateAnElement(elements.data(), elements.size(), false, false);

            break;
        case 4:
            writeArrayToBinaryFile(elements.data(), elements.size());
            cout << "\n";
            system("pause");
            break;

        case 0:

            break;
        }

    } while (selection != 0);
    return 1;
}

// Function: drawEmptyElements(int numEle, bool bySymbol)
// Precondition: 
// Postcondition: Draws the empty elements

void drawEmptyElements(int numEle, bool bySymbol)
{
    string empty = "     ";
    if (bySymbol)
    {
        empty = "     ";
    }
    for (int i = 0; i < numEle; i++)
    {
        cout << empty;
    }
}

// Function: drawElements(int startingAtomicNum, int howManyEle, bool bySymbol)
// Precondition:
// Postcondition: Draws the elements

void drawElements(int startingAtomicNum, int howManyEle, bool bySymbol)
{

    for (int i = 0; i < howManyEle; i++)
    {
        int index = startingAtomicNum + i - 1;
        string atomicNumberStr = "";
        switch (periodicTable[index].chemicalGroupBlock)
        {
        case 0:
            cout << "\033[1;30m";
            break;
        case 1:
            cout << "\033[1;31m";
            break;
        case 2:
            cout << "\033[1;32m";
            break;
        case 3:
            cout << "\033[1;33m";
            break;
        case 4:
            cout << "\033[1;34m";
            break;
        case 5:
            cout << "\033[1;35m";
            break;
        case 6:
            cout << "\033[1;36m";
            break;
        case 7:
            cout << "\033[1;37m";
            break;
        case 8:
            cout << "\033[1;38m";
            break;
        case 9:
            cout << "\033[1;39m";
            break;
        case 10:
            cout << "\033[1;40m";
            break;
        }
        if (bySymbol)
        {
            if (strlen(periodicTable[index].symbol) == 1)
            {
                cout << "[  " << periodicTable[index].symbol << "]";
            }
            else
            {
                cout << "[ " << periodicTable[index].symbol << "]";
            }
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
            cout << "[" << atomicNumberStr << "]";
        }

    }
}

// Function: displayPeriodicTable(bool bySymbol)
// Precondition:
// Postcondition: Displays the periodic table

void displayPeriodicTable(bool bySymbol)
{
    int currentAtomic = 0;
    if (bySymbol)
    {
        cout << "\t\t\tPERIODIC TABLE OF ELEMENTS BY SYMBOL \n\n";
    }
    else
    {
        cout << "\t\t\tPERIODIC TABLE OF ELEMENTS BY ATOMIC NUMBER \n\n";
    }
    for (int row = 0; row < 10; row++)
    {
        cout << "\t";
        if (row == 0)
        {
            drawElements(periodicTable[currentAtomic].atomicNumber, 1, bySymbol);
            currentAtomic++;
            drawEmptyElements(16, bySymbol);
            drawElements(periodicTable[currentAtomic].atomicNumber, 1, bySymbol);
            currentAtomic++;
            cout << "\n";
        }
        else if (row == 1 || row == 2)
        {
            drawElements(periodicTable[currentAtomic].atomicNumber, 2, bySymbol);
            currentAtomic += 2;
            drawEmptyElements(10, bySymbol);
            drawElements(periodicTable[currentAtomic].atomicNumber, 6, bySymbol);
            currentAtomic += 6;
            cout << "\n";
        }
        else if (row == 3 || row == 4)
        {
            drawElements(periodicTable[currentAtomic].atomicNumber, 18, bySymbol);
            currentAtomic += 18;
            cout << "\n";
        }
        else if (row == 5 || row == 6)
        {
            drawElements(periodicTable[currentAtomic].atomicNumber, 2, bySymbol);
            currentAtomic += 2;
            if (row == 5)
            {
                cout << "  *  ";
                drawElements(72, 15, bySymbol);
                currentAtomic += 15;

            }
            else
            {
                cout << "  ** ";
                drawElements(104, 15, bySymbol);
                currentAtomic += 15;
            }
            cout << "\n";

        }
        else if (row == 7)
        {
            cout << "\n";
        }
        else if (row == 8)
        {
            drawEmptyElements(2, bySymbol);
            cout << "  *  ";
            //cout << "\033[1;34m";
            drawElements(57, 15, bySymbol);
            cout << "\n";
        }
        else if (row == 9)
        {
            drawEmptyElements(2, bySymbol);
            cout << "  ** ";
            //cout << "\033[1;30m";
            drawElements(89, 15, bySymbol);
            cout << "\n";
        }

    }
}

// Function: inputIntegerWithDecimalCheck(string prompt, bool posNeg)
// Precondition: User must enter a valid option
// Postcondition: Checks if the input is a valid integer

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

// Function: validateNumericString(char inputStr[maxSize], int numberOfDigits, bool checkForLen)
// Precondition: User must enter a valid option
// Postcondition: Checks if the input is a valid numeric string

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
bool validateString(char input[100], int minLen, int maxLen)
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