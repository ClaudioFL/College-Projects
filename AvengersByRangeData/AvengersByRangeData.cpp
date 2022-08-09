/* Name: Claudio Florio
Date: 03/21/2022
Section:
Assignment: Module 11: Avengers - Number of Appearances Program Part 1
Due Date: 03/27/2022
About this project: Displays the number of Appearances of every avenger ever and allows you to change the
number of appearances.
Assumptions: N/A.
All work below was performed by Claudio Florio */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct AvengersData {
    string RangeNumOfAppearance;
    int RangeUpperLimit;
    int NumOfMaleAvengers;
    int NumOfFemaleAvengers;
    int NumOfAvengersThatDied;
    int NumOfAvengersAlive;
};

void displayData(AvengersData range[]);
void rangeDeadAvengers(AvengersData range[]);
void readData(AvengersData range[]);
void rangeLargestPercentageFemale(AvengersData range[]);

int main() {

    char choice;   // To hold menu choices

    //Array holding the data for the range
    AvengersData range[6];
    range[0].RangeNumOfAppearance = "            <=750";
    range[0].NumOfFemaleAvengers = range[0].NumOfMaleAvengers = range[0].NumOfAvengersAlive = range[0].NumOfAvengersThatDied = 0;
    range[1].RangeNumOfAppearance = " > 750 and <=1500";
    range[1].NumOfFemaleAvengers = range[1].NumOfMaleAvengers = range[1].NumOfAvengersAlive = range[1].NumOfAvengersThatDied = 0;
    range[2].RangeNumOfAppearance = "> 1500 and <=2250";
    range[2].NumOfFemaleAvengers = range[2].NumOfMaleAvengers = range[2].NumOfAvengersAlive = range[2].NumOfAvengersThatDied = 0;
    range[3].RangeNumOfAppearance = "> 2250 and <=3000";
    range[3].NumOfFemaleAvengers = range[3].NumOfMaleAvengers = range[3].NumOfAvengersAlive = range[3].NumOfAvengersThatDied = 0;
    range[4].RangeNumOfAppearance = "> 3000 and <=3750";
    range[4].NumOfFemaleAvengers = range[4].NumOfMaleAvengers = range[4].NumOfAvengersAlive = range[4].NumOfAvengersThatDied = 0;
    range[5].RangeNumOfAppearance = "> 3750 and <=4500";
    range[5].NumOfFemaleAvengers = range[5].NumOfMaleAvengers = range[5].NumOfAvengersAlive = range[5].NumOfAvengersThatDied = 0;

    readData(range);

    // Welcome Message
    cout << "Welcome to Avengers Data By Range Program" << endl;
    do{
        // Menu Options
        cout << "A) Display Data\n";
        cout << "B) Find Range with the largest number of Avengers who have died\n";
        cout << "C) Find Range with the largest percentage of Avengers who are female \n";
        cout << "D) Quit \n";

        // User selects choices between 1-5
        cout << "Select an option (A-D):";
        cin >> choice;


        if (choice == 'A' || choice == 'a')
            displayData(range);
        else if (choice == 'B' || choice == 'b')
            rangeDeadAvengers(range);
        else if (choice == 'C' || choice == 'c')
            rangeLargestPercentageFemale(range);
    }while (choice!='D' && choice!='d');

}

//***************************//
// Reads Data from text file //
//***************************//
void readData(AvengersData range[]){
    //Reads the file
    ifstream DataFile;
    //Opens file and reads through it.
    DataFile.open("AvengersData.txt");
    if (DataFile)
    {
        string data1,data3,data4;
        int data2;

        while(DataFile>>data1>>data2>>data3>>data4){
            if (data2 <=750){
                range[0].RangeUpperLimit=750;           //Sets range upper limit
                if (data3 == "MALE")                    //Checks if male or female
                    range[0].NumOfMaleAvengers++;
                else
                    range[0].NumOfFemaleAvengers++;
                if (data4 == "YES")                     //Checks if avenger has died
                    range[0].NumOfAvengersThatDied++;
                else
                    range[0].NumOfAvengersAlive++;
            }
            else if(data2 > 750 && data2 <= 1500){
                range[1].RangeUpperLimit=1550;
                if (data3 == "MALE")
                    range[1].NumOfMaleAvengers++;
                else
                    range[1].NumOfFemaleAvengers++;
                if (data4 == "YES")
                    range[1].NumOfAvengersThatDied++;
                else
                    range[1].NumOfAvengersAlive++;
            }
            else if(data2 > 1500 && data2 <=2250){
                range[2].RangeUpperLimit=2250;
                if (data3 == "MALE")
                    range[2].NumOfMaleAvengers++;
                else
                    range[2].NumOfFemaleAvengers++;
                if (data4 == "YES")
                    range[2].NumOfAvengersThatDied++;
                else
                    range[2].NumOfAvengersAlive++;
            }
            else if(data2 > 2250 && data2 <=3000){
                range[3].RangeUpperLimit=3000;
                if (data3 == "MALE")
                    range[3].NumOfMaleAvengers++;
                else
                    range[3].NumOfFemaleAvengers++;
                if (data4 == "YES")
                    range[3].NumOfAvengersThatDied++;
                else
                    range[3].NumOfAvengersAlive++;
            }
            else if(data2 > 3000 && data2 <=3750){
                range[4].RangeUpperLimit=3750;
                if (data3 == "MALE")
                    range[4].NumOfMaleAvengers++;
                else
                    range[4].NumOfFemaleAvengers++;
                if (data4 == "YES")
                    range[4].NumOfAvengersThatDied++;
                else
                    range[4].NumOfAvengersAlive++;
            }
            else if(data2 > 3750 && data2 <=4500){
                range[5].RangeUpperLimit=4500;
                if (data3 == "MALE")
                    range[5].NumOfMaleAvengers++;
                else
                    range[5].NumOfFemaleAvengers++;
                if (data4 == "YES")
                    range[5].NumOfAvengersThatDied++;
                else
                    range[5].NumOfAvengersAlive++;
            }
        }
    }
}

//******************************************************//
// Displays the data for each element in the data array.//
//******************************************************//
void displayData(AvengersData range[]){
    //Displays the Data
    cout << "\nRange\t\t\tNum Females\tNum Males\tNum Died Once\tNum Never Died Once\n";
    for(int i=0; i<6;i++){
        cout << range[i].RangeNumOfAppearance << "\t\t";
        cout << range[i].NumOfFemaleAvengers<<"\t\t";
        cout << range[i].NumOfMaleAvengers<<"\t\t";
        cout << range[i].NumOfAvengersThatDied<<"\t\t";
        cout << range[i].NumOfAvengersAlive<<"\t\t\n";
    }

}

//*******************************************************************//
// Finds the Range with the largest number of Avengers who have died //
//*******************************************************************//
void rangeDeadAvengers(AvengersData range[]){
    int i, max = 0;
    cout << "The range with the largest number of avengers who have died once is ...\n";
    for(i = 0; i < 6; i++)
        if (range[i].NumOfAvengersThatDied >= range[max].NumOfAvengersThatDied)
            max = i;
    cout << "Range Number of Appearances: ";
    cout << range[max].RangeNumOfAppearance << endl;
}


//********************************************************************//
// Finds Range with the largest percentage of Avengers who are female //
//********************************************************************//
void rangeLargestPercentageFemale(AvengersData range[]){
    cout << "The range with the largest percentage of avengers who are female is ...\n";
    int i, max = 0;
    int percent;

    for(i = 0; i < 6; i++)
    {
        percent = (range[i].NumOfFemaleAvengers*100)/(range[i].NumOfFemaleAvengers+range[i].NumOfMaleAvengers);
        if (percent >= (range[max].NumOfFemaleAvengers*100)/(range[max].NumOfFemaleAvengers+range[max].NumOfMaleAvengers))
            max = i;
    }
    cout << "Range Number of Appearances: "<< range[max].RangeNumOfAppearance << endl;
}

