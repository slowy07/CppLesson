#include <iostream>
#include <cmath>
using namespace std;


void displayMenu()
{
  cout<<"+ = add"<<endl;
  cout<<"- = minus"<<endl;
  cout<<"* = multiple"<<endl;
  cout<<"/ = divide"<<endl;
  cout<<"^ = exponent"<<endl;
}

void sumAddnumber(double num1, double num2)
{
  return num1+num2;
}
void sumMinusnumber(double num1, double num2)
{
  return num1-num2;
}
void sumMultiplenumber(double num1, double num2)
{
  return num1*num2;
}
void sumDividenumber(double num1, double num2)
{
  return num1/num2;
}
void sumExponentnumber(double num1, double num2)
{
  return pow(num1,num2);
}
