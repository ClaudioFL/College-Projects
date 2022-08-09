//
// Created by Claudio Florio on 4/17/22.
//

#include "Avenger.h"
#include <string>

//Constructor 1
Avenger::Avenger()
{
    Name = "";
    appearances = 0; // name
}

//Constructor 2
Avenger::Avenger(string name)
{
Name = name;
appearances = 0;
}

//Accessor 1
string Avenger::getName()
{
    return Name;
}

//Accessor 2
int Avenger::getAppearances()
{
    return appearances;
}

//Accessor 3
string Avenger::getGender()
{
    return Gender;
}

//Accessor 4
bool Avenger::ifDied()
{
    return Died;
}

//Mutator function 1
void Avenger::setName(string n)
{
    Name=n;
}

//Mutator function 2
void Avenger::setAppearances(int p)
{
    appearances=p;
}

//Mutator function 3
void Avenger::setGender(string g)
{
    Gender=g;
}

//Mutator function 4
void Avenger::setDead(bool d)
{
    Died=d;
}

string Avenger::computeNumberOfAppearancesRange(){
    string range;
    if(appearances <= 750)
    {
        range = "<=750";
    }
    else if(appearances <= 1500)
    {
        range = "> 750 and <=1500";
    }
    else if(appearances <= 2250)
    {
        range = "> 1500 and <=2250";
    }
    else if(appearances <= 3000)
    {
        range = "> 2250 and <=3000";
    }
    else if(appearances <= 3750)
    {
        range = "> 3000 and <=3750";
    }
    else if(appearances <= 4500)
    {
        range = "> 3750 and <=4500";
    }
    return range;
}
