#include <iostream>
#include <iomanip>
using namespace std;

//majusee zulkepret :v
//auhasdhurbhasdtrasdhub jo 
//asdbyrashduasdjnkasd 

int main()
{
    int numberPoint = 200;
    float getPoint = 12.5*4.3;


    cout<<"sum f point "<<getPoint<<endl;
    cout<<"using setw"<<endl;
    cout<<setw(15)<<numberPoint<<endl;
    cout<<"point :"<<setw(15)<<numberPoint<<endl;
    cout<<"f point :"<<setw(3)<<getPoint<<endl;
    
    cout<<endl;
    cout<<"using ends "<<endl;
    cout<<"i got "<<numberPoint<<ends<<ends<<"."<<endl;

    cout<<endl;
    cout<<"using setprecision"<<endl;
    cout<<"setw(1) :"<<setprecision(1)<<getPoint<<endl;
    cout<<"setw(2) :"<<setprecision(2)<<getPoint<<endl;
    cout<<"setw(3) :"<<setprecision(3)<<getPoint<<endl;
    
    cout<<endl;
    cout<<"octal , decimal, hexadecimal"<<endl;
    cout<<"decimal : "<<dec<<numberPoint<<endl;
    cout<<"octal : "<<oct<<numberPoint<<endl;
    cout<<"hexadecimal : "<<hex<<numberPoint<<endl;
    return 0;
}
