#include <iostream>
using namespace std;



//create function
void sayName()
{
    cout<<"hello arfy slowy"<<endl;
}

void sayNameAgain(string name)
{
    cout<<"hello "<<name<<endl;
}
int main()
{
    //call the function
    sayName();


    //call the function with parameters
    sayNameAgain("zulkepret");
}
