
#ifndef airplane_hpp
#define airplane_hpp

#include "runway.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

class Airplane
{
private:
   
    int id;
    int Tarrival;
    int Twait;
    int Tlanding;
    string source;
    
public:
    Airplane();
    Airplane(int arrival);
    void SetArrivalT(int arrival);
    int GetID();
    int GetAT();
    void SetWT(int wait);
    void increment_WT();
    int  GetWT();
    string getSource();
    // void setLandingT(int LandingT1);
    // int getLandingT();
    
    //Genreates random 4 digit plane id
    int RandomID();
    //Chooese a random source for the flight form an array of predefined sources
    string RandomSource();
};



#endif /* airplane_hpp */
