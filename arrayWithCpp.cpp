#include <iostream>
using namespace std;


int main()
{

    string cars[4] = {
        "mercedes benz",
        "volvo",
        "BMW",
        "mazda"
    };
    string country[3] = {
        "indonesia",
        "united kingdom",
        "ghana"
    };

    //array start from 0 = mercedes benz
    cout<<cars<<endl;

    //for make spesification output
    cout<<cars[0]<<endl; //output mercedes benz

    //change array element
    country[1] = "united states"; //united kingdom change to united states
    cout<<country<<endl; 
    return 0;

}
