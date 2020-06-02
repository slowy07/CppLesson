#include <iostream>
using namespace std;

class car
{
    public:
        int sumCar;
        string nameCar;
};

int main()
{
    //create object
    car objCar;
    
    //create value of class 
    objCar.sumCar = 1;
    objCar.nameCar = "ferrari";


    //output attribute
    cout<<objCar.sumCar<<endl;
    cout<<objCar.nameCar<<endl;
    
    return 0;
}
