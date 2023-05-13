
#include "DEQ.hpp"
#include "airplane.hpp"
#include "runway.hpp"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(NULL);
    int Tmax; // fixed maximum simulation time
    // int t; // current clock time
    int Tdelta; // fixed average inter-arrival time
    // int P_arrival; // probability of arrival per unit time
    int Tlanding; // fixed service time
    // int Tr; // time remaining to start service
    // int Tarrival; // random arrival time
    // int Tw; // wait time
    // int planecount; // number of planes serviced
    // int waitTotal; // total wait times of planes
    char answer;
    
    cout << "welcome to the CAIRO airport simulator." << endl;
    cout << "do you wish to begin the simulation with the default clock settings? please enter Y/y for Yes and N/n for no." << endl;
    cin >> answer;
    while (!(answer == 'Y' || answer == 'y' || answer == 'N' || answer == 'n'))
    {
        cout << "invalid character entered please try again." << endl;
        cin >> answer;
    }
    
    if (answer == 'Y' || answer == 'y')
    {
        Tmax = 360;
        Tlanding = 10;
        Tdelta = 6;
    }
    else
    {
        cout << "please customize your simulation settings." << endl;
        cout << "please enter the fixed simultion period:" << endl;
        cin >> Tmax;
        cout << "please enter the service time of each job: " << endl;
        cin >> Tlanding;
        cout << "please enter the average inter-arrival time: " << endl;
        cin >> Tdelta;
    }

    Runway<Airplane> plane(Tmax, Tlanding, Tdelta);
    
    plane.startSimulation();

    cout << "average wait time for each plane: " << plane.Averagewait() << endl;
    
 
}


