#include <iostream>
using namespace std;

class Vehicle
{
    public:
        string modelName = "gallardo";
        void honk()
        {
            cout<<"biiiiim...."<<endl;
        }
};

class Car: public Vehicle
{
    public:
        String brand = "lamborghini";
};


int main()
{
    Car MyCar;
    MyCar.honk(); //output biiiiiim.....
    cout<<MyCar.brand + " " +MyCar.modelName<<endl;
    //output lamborghini gallardo 
    return 0;

}
