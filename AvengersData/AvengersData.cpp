/* Name: Claudio Florio
Date: 05/1/2022
Section:
Assignment: Module 10 Avengers Data Program
Due Date: 05/3/2022
About this project: Program that reads through the file above and based upon the option selected computed and display
Assumptions: N/A.
All work below was performed by Claudio Florio */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void ReadData(vector<string> &name,vector<string> &appearance,vector<int> &gender,vector<string> &died);
void displayCountNameOfAvenger(vector<string> &name,vector<int> &gender,vector<string> &died);
void displayAvgOfDeadGender(vector<string> &appearance,vector<int> &gender,vector<string> &died);

int main() {

    vector<string> name;
    vector<string> appearance;
    vector<int> gender;
    vector<string> died;

    //Char for the choice user will make
    char choice;

    ReadData(name,appearance,gender,died);

    //welcome message
    cout << "Avengers Data\n";

    //Displays menu options
    cout << "A) Display count and names of the Avengers who who have died at least once\n";
    cout << "B) Display average number of appearances of Avengers who have never Died by gender\n";

    //Prompt for user to select choices between A-B
    cout << "Please select options (A-B): ";
    cin >> choice;

    //If statement to call each function to the correct choice
    if(choice == 'A'||choice == 'a')
        displayCountNameOfAvenger(name,gender,died);
    else if (choice == 'B' || choice == 'b')
        displayAvgOfDeadGender(appearance,gender,died);
    else
        cout << "Invalid option entered\n";


    return 0;
}

//Function to read and register the data from the text file
void ReadData(vector<string> &name,vector<string> &appearance,vector<int> &gender,vector<string> &died){

    ifstream DataFile;

    DataFile.open("AvengersData.txt");
    if (DataFile)
    {
        string data1,data2,data3,data4;
        while(DataFile>>data1>>data2>>data3>>data4)
        {
            name.push_back(data1);
            appearance.push_back(data2);
            if (data3 == "MALE")
                gender.push_back(1);
            else
                gender.push_back(2);
            died.push_back(data4);
        }
    }
    DataFile.close();
}

void displayCountNameOfAvenger(vector<string> &name,vector<int> &gender,vector<string> &died) {

    //Menu option welcome message
    cout << "Display name and count of Avengers who have died at least once\n";
    cout << "The following Avengers have died at least once...\n";

    long count=0;

    for (int i = 0; i < (died.size() - 1); i++){
        if(died[i]=="YES"){
            cout << name[i] << endl;
            count++;
        }
    }
    cout<<"The number of Avengers have died at least once = " << count << endl;
    cout<<fixed<<setprecision(4)<<"percentage = "<<static_cast<double>(count)/name.size()*100<<endl;


}




void displayAvgOfDeadGender(vector<string> &appearance,vector<int> &gender,vector<string> &died){

    //Menu option welcome message
    cout << "Display count of Avengers who have never Died by gender...\n";
    cout << "The average number of appearances of Avengers who have never Died \n";

    int male=0, female=0, summ =0 ,sumf=0;

    for (int i = 0; i < (died.size() - 1); i++){
        if(died[i]=="NO"){
            if(gender[i]==1){
                summ+=stoi(appearance[i]);
                male++;
            }
            else{
                sumf+=stoi(appearance[i]);
                female++;
            }
        }
    }
    double avg = double(summ)/double(male), avgf = double(sumf)/double(female);
    cout<< showpoint<<setprecision(7) << "Male = " << avg << endl;
    cout<<showpoint<< setprecision(7) << "Female = " << avgf << endl;
}