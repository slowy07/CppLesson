#include <iostream>
using namespace std;

class Bike
{
    public:
        int speed(int currentspeed); 

}

int Bike::speed(int currentspeed)
{
    return currentspeed;
}


int main()
{
    //create object
    Bike objBike;
    
    //create ouput with value
    cout<<"current bike speed "<<objBike.speed(20)<<"km/h"<<endl;
    return 0;
}
