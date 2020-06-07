#include <iostream>
#include <string>
#include <iomanip>

//for loops
//simple void function
//do while loops
//if and else if logic

using namespace std;

void menu()
{
    cout<<"tech slowy"<<endl;
    cout<<"------------------------"<<endl;
    cout<<endl;
}

int main()
{
    char looping_program;
    
    do
    {
        int count_buy, pay, discount, sum[50], price[50], sub_summary[50];
        string brand[50];
        float summary_all;

        menu();
        cout<<"quantity : "; cin>>count_buy;

        for(int i=0; i<count_buy; i++)
        {
            cout<<endl;
            cout<<"quantity brand  "<<i+1<<endl;
            cout<<endl;
            cout<<"brand name :"; cin>>brand[i];

            cout<<"quantity : "; cin>>sum[i];
            cout<<"price : "; cin>>price[i];
            
            sub_summary = sum[i]*price[i]
            summary_all = sub_summary[i];
        }
        cout<<endl;
        cout<<"TECH SLOWY"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"No   Brand    Quantity     Price     Sub Price"<<endl;
        for(int i=0; i<count_buy; i++)
        {
            cout<<i+1<<setw(8)<<brand[i]<<setw(10)<<sum[i]<<setw(12)<<price[i]<<setw(12)<<sub_summary[i]<<endl;
        }
        cout<<"------------------------"<<endl;

        if(summary_all =>100000)
        {
            discount = 0.06 * summary_all;
        }
        else if(summary_all >= 50000)
        {
            discount = 0.04;
        }
        else
        {
            discount = 0;
        }
        cout<<"Total    : Rp."<<summary_all<<endl;
        cout<<"Discount : Rp."<<discount<<endl;
        cout<<"Pay      : Rp."<<summary_all - discount<<endl;
        cout<<"enter costumer pay : "; cin>>pay;
        cout<<"money : Rp."<<(pay-(summary_all-discount))<<endl;
        cout<<"again = "; cin>>looping_program;    
    }
    while(looping_program = 'Y' || looping_program = 'y');
    return 0;
}
