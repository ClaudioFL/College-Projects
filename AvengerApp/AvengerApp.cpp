/* Name: Claudio Florio
Date: 04/14/2022
Section:
Assignment: Module 12: Avengers Data Using a Class Program & Unix Makefile
Due Date: 04/17/2022
About this project: Avenger App.
Assumptions: N/A.
All work below was performed by Claudio Florio */

#include <iostream>
#include <iomanip>
#include "Avenger.h"
#include <string>

using namespace std;

void DisplayAvenger(Avenger num);

int main() {
    Avenger one;
    one.setName("Luke Cage");
    one.setAppearances(886);
    one.setGender("MALE");
    one.setDead(0);

    Avenger two;
    two.setName("Steven Rogers");
    two.setAppearances(3458);
    two.setGender("MALE");
    two.setDead(1);

    Avenger three;
    three.setName("Wanda Maximoff");
    three.setAppearances(1214);
    three.setGender("FEMALE");
    three.setDead(1);

    Avenger four;
    four.setName("Reed Richards");
    four.setAppearances(2125);
    four.setGender("MALE");
    four.setDead(0);

    DisplayAvenger(one);
    cout<<"\n";
    DisplayAvenger(two);
    cout<<"\n";
    DisplayAvenger(three);
    cout<<"\n";
    DisplayAvenger(four);
    cout<<"\n";

}

void DisplayAvenger(Avenger num){
    cout<<"Name:"<<num.getName()<<endl;
    cout<<"Number Of Appearances:"<<num.getAppearances()<<endl;
    cout<<"Gender:"<<num.getGender()<<endl;
    cout<<"Died At Least Once:"<<num.ifDied()<<endl;
    cout<<"Number Of Appearances Range:"<<num.computeNumberOfAppearancesRange()<<endl;
}