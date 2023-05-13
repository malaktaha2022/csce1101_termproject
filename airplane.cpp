
#include "airplane.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

Airplane :: Airplane()
{
    Tarrival = 0;
    id = RandomID();
    source = RandomSource();
}

Airplane :: Airplane(int arrival)
{
    Tarrival = arrival;
    id = RandomID();
    source = RandomSource();
}

void Airplane :: SetArrivalT(int arrival)
{
    Tarrival = arrival;
}

int Airplane :: GetID()
{
    return id;
}

int Airplane :: GetAT()
{
    return Tarrival;
}

void Airplane :: SetWT(int wait)
{
    Twait = wait;
}

void Airplane :: increment_WT()
{
    Twait++;
}

int Airplane :: GetWT()
{
    return Twait;
}

string Airplane :: getSource()
{
    return source;
}

int Airplane :: RandomID()
{
    srand(NULL);
    int R;
    R = (rand() % 9999) + 1000;
    return R;
}

string Airplane :: RandomSource()
{
    int i = rand() % 10;
    string airports[] = {"CAI", "DXB", "JFK", "LHR", "HKG", "CDG", "ICN", "BKK", "MUC", "SYD"};
    return airports[i];
}
