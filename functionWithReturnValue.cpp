#include <iostream>
using namespace std;


int addNumber(int firstNumber, int secondNumber)
{
    return firstNumber + secondNumber;
    //firstnumber + second number
}
double addfloatingPoint(double firstnumber, double secondnumber)
{
    return firstnumber + secondnumber;
}

int main()
{
    int firstsum = addNumber(3,5); //first number 3, second number 5   
    double secondsum = addfloatingPoint(3.42, 4.50);
    
    cout<<firstsum<<endl;
    cout<<secondsum<<endl;
    return 0;
}
