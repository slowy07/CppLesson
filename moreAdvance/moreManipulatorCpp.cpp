#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int myPoint = 2000, m=15, d=12;
    float getMyPoint = 20.5;

    cout<<"decimal octal hexadecimal"<<endl;
    int getIndexTable;
    for(getIndexTable = 1; getIndexTable <= 15; getIndexTable++)
    {
        cout<<setbase(10)<<getIndexTable<<"         ";
        cout<<setbase(8)<<getIndexTable<<"          ";
        cout<<setbase(16)<<getIndexTable<<endl;
    }


    cout<<endl;
    cout<<"using setfill() "<<endl;

    for(int i=1; i<=5; i++)
    {
        cout<<setfill('-');
        cout<<setw(i)<<i<<endl;
    }
}
