/*
*Carter Pride
* Professor Schaffner
* Write a program that produces a bar chart for the population growth of a town. The data is stored in intervals over the past several years, with the population for that year (rounded to the nearest 1,000 people) in each line of the file. A test data file called People.txt has been provided on Canvas that contains the population numbers for several years. For this data set, the starting year is 1900 and the interval between data points is 20. 
The program should ask for the name of the data file and the name of the town. The program should open the file and verify that it has opened with no errors. Then the program should read the population figure, calculate the year, and display the year and population on a bar chart. For each year, it should display the year and a bar consisting of one asterisk for each 1,000 people.
Here is an example of how the chart might begin:
My Town Population Growth
(each * represents 1,000 people)
1900 **
1920 ****
1940 *****
* 11/2025
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    string fileName, townName;

    cout << " Enter the population data file name: ";
    cin >> fileName;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << " Enter the name of the town: ";
    getline(cin, townName);

    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << " Error: coult not open file " << fileName << endl;
        return 1;
    }

    cout << "\n" << townName << " Population Growth\n";
    cout << " (each * represents 1,000 people)|n|n";

    int year = 1900, population;

    while (inputFile >> population) {
        cout << year << " ";

        int stars = population / 1000;
        for (int i = 0; i < stars; ++i) {
            cout << '*';
        }
        cout << endl;

        year += 20;
    }

    inputFile.close();
    return 0;
}


