#include <iostream>
using namespace std;


class Bike
{
    public:
        string name,owner;
        int yearModel;
        Bike(String bikename,string ownername, int bikeyearModel)
        {
            name = bikename;
            owner = ownername;
            yearModel = bikeyearModel;
        }
};

int main()
{
    Bike objBike("brompton", "arfy slowy", 2019);
    Bike objBike2("polygon", "zulkepret", 2005);
    cout<<objBike.name<<" "<<objBike.owner<<" "<<objBike.yearModel<<endl;
    cout<<objBike2.name<<" "<<objBike2.owne<<" "<<objBike2.yearModel<<endl;
      
    return 0;
}
