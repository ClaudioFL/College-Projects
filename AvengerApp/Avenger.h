//
// Created by Claudio Florio on 4/17/22.
//
#ifndef AVENGERAPP_AVENGER_H
#define AVENGERAPP_AVENGER_H
#include <string>
using namespace std;

class Avenger {
private:
    string Name;
    int appearances;
    string Gender;
    bool Died;
public:
    //Constructor 1
    Avenger();

    //Constructor 2
    Avenger(string name);
    
    //Accessor 1
    string getName();

    //Accessor 2
    int getAppearances();

    //Accessor 3
    string getGender();

    //Accessor 4
    bool ifDied();

    //Mutator function 1
    void setName(string n);

    //Mutator function 2
    void setAppearances(int p);

    //Mutator function 3
    void setGender(string g);

    //Mutator function 4
    void setDead(bool d);

    //Member Function
    string computeNumberOfAppearancesRange();
};


#endif //AVENGERAPP_AVENGER_H
