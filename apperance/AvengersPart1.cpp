/* Name: Claudio Florio
Date: 03/21/2022
Section:
Assignment: Module 7: Avengers - Number of Appearances Program Part 1
Due Date: 03/27/2022
About this project: Displays the number of Appearances of every avenger ever and allows you to change the
number of appearances.
Assumptions: N/A.
All work below was performed by Claudio Florio */

#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_AVENGERS =173;

int getValidNumAppearances();
int getValidAvenger();
void displayNumAppearances(int numAppearances[NUM_AVENGERS]);
void ChangeANumAppearances(int numAppearances[NUM_AVENGERS]);
void displayMaxNumAppearances(int numAppearances[NUM_AVENGERS]);

int main() {

    int choice;    // To hold menu choices

    const int numberOfAppearanceChoice = 1,
            appearanceAvengerChoice=2,
            maxNumOfAppearanceChoice=3,
            exitChoice=4;    // Constants for the menu choices

    //Array Values
    int numAppearances[NUM_AVENGERS]={
            1269, 1165, 3068, 2089, 2402,
            612, 3458, 1456, 769, 1214,
            115, 741, 780, 1036, 482,
            1112, 160, 1886, 332, 557,
            197, 106, 692, 109, 100,
            132, 108, 100, 156, 254,
            935, 576, 141, 355, 933,
            348, 206, 533, 374, 2,
            2305, 83, 402, 352, 565,
            112, 218, 149, 168, 1561,
            217, 158, 86, 41, 68,
            70, 61, 2125, 1761, 293,
            36, 22, 31, 34, 33,
            4, 47, 7, 3, 16,
            575, 58, 237, 4333, 126,
            158, 355, 517, 202, 31,
            28, 50, 27, 18, 302,
            330, 101, 43, 126, 24,
            886, 159, 3130, 241, 67,
            23, 103, 123, 110, 160,
            132, 121, 59, 629, 1324,
            236, 663, 525, 205, 108,
            359, 299, 333, 88, 369,
            380, 545, 6, 126, 417,
            31, 310, 40, 26, 63,
            2, 73, 22, 153, 73,
            59, 66, 43, 55, 108,
            64, 62, 94, 18, 81,
            1598, 1375, 746, 561, 592,
            679, 491, 65, 55, 44,
            65, 877, 176, 24, 25,
            35, 44, 78, 22, 77,
            115, 77, 69, 173, 75,
            12, 14, 13, 198, 29,
            45, 49, 35
    };

    // Welcome Message
    cout << "Welcome to the Avengers Program!" << endl;
    do {

        cout << "1) Display the number of appearances\n";
        cout << "2) Change the number of appearances for an Avenger\n";
        cout << "3) Display the max number of appearances \n";
        cout << "4) Quit \n";

        //User selects choices between 1-4
        cout << "Select an option (1..4)..";
        cin >> choice;

        //Input Validation for menu choices
        while (choice < numberOfAppearanceChoice || choice > exitChoice) {
            cout << "Select an option (1..4): ";
            cin >> choice;
        }

        //switch for choice made by user.
        switch (choice){
            case numberOfAppearanceChoice:
                displayNumAppearances(numAppearances);
                break;
            case appearanceAvengerChoice:
                ChangeANumAppearances(numAppearances);
                break;
            case maxNumOfAppearanceChoice:
                displayMaxNumAppearances(numAppearances);
                break;
        }
    } while (choice!=exitChoice);

    return 0;
}

// User Validation for number of Appearances. Appearances = Value of subscript
int getValidNumAppearances(){
    int num;
    do{
        cout << "Please enter in the Number of Appearances:";
        cin >> num;
    }while ( num < 1);

    return num;
}

// User validation for number of the Avenger. Avenger = Subscript of array
int getValidAvenger(){
    int avenger;
    do {
        cout << "Please enter in the number of the Avenger:";
        cin >> avenger;
    }while (avenger<1 || avenger > NUM_AVENGERS);
    avenger-=1;

    return avenger;
}

// Displays the NUM_AVENGERS array.
void displayNumAppearances(int numAppearances[NUM_AVENGERS]){
    cout <<"Display Number Of Appearances\n";
    int i=0, j=NUM_AVENGERS/5;
    for(int k=0; k<j;k++)
    {
        cout << setw(8) << right << numAppearances[i] << setw(8) << right << numAppearances[i+1]
             << setw(8) << right << numAppearances[i+2] << setw(8) << right  << numAppearances[i+3]
             << setw(8) << right << numAppearances[i+4] << endl;
        i=i+5;
    }
    for(j=0;j<NUM_AVENGERS%5;j++)
        cout << setw(8) << right << numAppearances[i++];
    cout <<""<< endl;
}

// Function to change the number of appearances in the array.
void ChangeANumAppearances(int numAppearances[NUM_AVENGERS]){
    cout <<"Change A Number of Appearances\n";
    int avengerNumber = getValidAvenger();  //Defines the variable with the return of the function getValidAvenger()
    int appearance = getValidNumAppearances();  //Defines the variable with the return of the function getValidNumAppearances()
    numAppearances[avengerNumber]=appearance;
}

// Function that displays the max
void displayMaxNumAppearances(int numAppearances[NUM_AVENGERS]){
    int max;
    int count;
    max = numAppearances[0];

    for (count = 1; count < NUM_AVENGERS; count++)
    {
        if(numAppearances[count] > max)
            max = numAppearances[count];
    }

    cout << "The max number of appearances of the Avengers was " << max <<endl;
}
