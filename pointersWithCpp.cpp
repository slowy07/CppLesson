#include <iostream>
using namespace std;


int main()
{
    string name = "arfy slowy";
    string otherName = "zulfikri";
    string* pointerReference = &otherName;
    
    cout<<name<<endl; //output will show name
    cout<<&name<<endl; //output with the address of memory



    cout<<pointerReference<<endl; //output will show name 
    cout<&otherName<<endl; //output will show address of memory

    return 0;
}
