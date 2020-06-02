#include <iostream>
using namespace std;


int main()
{

    //creating reference with pointers
    string name = "rifki";
    string &phrase = name;
    
    cout<<name<<endl; //ouput rifki
    cout<<phrase<<endl; //ouput rifki
    return 0;
}
