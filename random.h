#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>
#include <time.h>

using namespace std;

class Random{

public:
    Random()
    {
        srand(time(NULL));
    }
    int GetNext(int low, int high)
    {
        return (rand()%(high-low))+low+1;
    }
};
#endif // RANDOM_H
