
#ifndef runway_hpp
#define runway_hpp

#include <iostream>
#include "airplane.hpp"
#include "DEQ.hpp"
using namespace std;

template <class T>
class Runway
{
private:
    DEQ<T*> queue;
    bool status;
    int Tservicestart;
    int Tserviceend;
    int Tclock;
    int Tmax;
    int Tlanding;
    int Tdelta;
    float Parrival;
    int Tr;
    int TotalWait = 0;
    int PlaneCount = 1;
    int Planes = 0;
    int Tarrival;
    
public:
    Runway(int max, int service, int delta)
    {
        Tclock = 0;
        set_Tmax(max);
        set_Tlanding(service);
        set_Tdelta(delta);
        set_Parrival(delta);
    }
    int getPlanes()
    {
        return Planes;
    }
    
    void setPlanes(int num)
    {
        Planes = num;
    }
    
    int getservicestart()
    {
        return Tservicestart;
    }
    
    void setservicestart(int start)
    {
        Tservicestart = start;
    }
    
    int getserviceend()
    {
        return Tserviceend;
    }
    
    void setserviceend(int end)
    {
        Tserviceend = end;
    }
    
    int RandomInt(int min, int max)
    {
        return rand() % (max-min + 1) + min;
    }
    
    void set_Tlanding(int service)
    {
        Tlanding = service;
    }
    
    void set_Tclock(int current)
    {
        Tclock = current;
    }
    
    void set_Tdelta(int delta)
    {
        Tdelta = delta;
    }
    
    void set_Parrival(int delta)
    {
        Parrival = 1.0 / float(delta);
    }
    
    void set_Tmax(int max)
    {
        while (max < 0)
        {
            cout << "error: simulation period cannot be negative. please enter a positive integer: " << endl;
            cin >> max;
        }
        
        Tmax = max;
    }
    
    void set_Tarrival(int arrive)
    {
        Tarrival = arrive;
    }
    
    void set_Status(bool stat)
    {
        status = stat;
    }
    
    void set_Tr(int remain)
    {
        Tr = remain;
    }
    
    void set_TotalWait(int wait)
    {
        TotalWait = wait;
    }
    
    void set_PlaneCount(int planes)
    {
        PlaneCount = planes;
    }
    
    DEQ<T>& getQueue()
    {
        return queue;
    }
    
    int getPlaneCount()
    {
        return PlaneCount;
    }
    
    int getTotalWait()
    {
        return TotalWait;
    }
    
    int getClockTime()
    {
        return Tclock;
    }
    
    int get_Tservice()
    {
        return Tlanding;
    }
    
    int get_Tarrival()
    {
        return Tarrival;
    }
    
    float get_Parrival()
    {
        return Parrival;
    }
    
    int get_RemainingTime()
    {
        return Tmax - Tclock;
    }
    
    int get_Tmax()
    {
        return Tmax;
    }
    
    bool RunwayAvailability()
    {
        if (Tr == 0)
        {
            set_Status(true);
            return status;
        }
        else
        {
            set_Status(false);
            return status;
        }
    }
    
    void startSimulation()
    {
        while (Tclock < Tmax)
        {
            int arrival = RandomInt(1, Tdelta);
            Tclock = Tclock + arrival;
            
            if (Tclock <= Tmax)
            {
                T* airplane = new T(getClockTime());
                queue.Add_Rear(airplane);
                cout << "Plane " << PlaneCount << " coming from terminal " << airplane->RandomSource() << " arrived at: " << Tclock << endl;
                PlaneCount++;
            }
            if (!queue.DEQisEmpty())
            {
                T* airplane = queue.View_Front();
                setservicestart(max(airplane->GetAT(), Tclock));
                Planes++;
                queue.Remove_Front();
                setserviceend(getservicestart() + Tlanding);
                set_Tr(getserviceend() - getservicestart());
                cout << "Plane " << PlaneCount - 1 << " service started at: " << getservicestart() << " wait = " << Tr << endl;
                
                TotalWait = TotalWait + Tr;
                Tclock = getserviceend();
                delete airplane;
            }
        }
        cout << "-----------------------------" << endl;
    }
    

    
    int Averagewait()
    {
        if (getPlanes() == 0)
            return 0;
        else
            return (getTotalWait() / getPlanes());
    }
    
    float RandomNum()
    {
        srand(NULL);
        float R = static_cast<float>(rand()) / RAND_MAX;
        return R;
    }
};

#endif /* runway_hpp */
