#include <iostream>
using namespace std;



void printScreenMenu()
{
    cout<<"Simple calculator "<<endl;
    cout<<"1. add"<<endl;
    cout<<"2. subtract "<<endl;
    cout<<"3. multiply"<<endl;
    cout<<"4. deivide"<<endl;
}

int main()
{
    int choice;
    float num1,num2,result;
    
    cout<<"enter choice 1,2,3,4 = "; cin>>choice;
    if(choice == 1)
    {
        cout<<"first number = "; cin>>num1;
        cout<<"second number = "; cin>>num2;
        result = num1 + num2; 
        cout<<num1<<"+"<<num2<<" = "<<result;
    }
    if(choice == 2)
    {
        cout<<"first number = "; cin>>num1;
        cout<<"second number = "; cin>>num2;
        result = num1 - num2; 
        cout<<num1<<"-"<<num2<<" = "<<result; 
    }
    if(choice == 3)
    {
        cout<<"first number = "; cin>>num1;
        cout<<"second number = "; cin>>num2;
        result = num1 * num2; 
        cout<<num1<<"*"<<num2<<" = "<<result;
    }
    if(choice == 4)
    {
        cout<<"first number = "; cin>>num1;
        cout<<"second number = "; cin>>num2;
        result = num1 / num2; 
        cout<<num1<<"/"<<num2<<" = "<<result;
    }

    return 0;
}
