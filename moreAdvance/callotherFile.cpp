#include <iostream>
#include <cmath>
#include secondCallotherFile.cpp
using namespace std;


int main()
{
  char operation;
  double number1,number2;
  displayMenu();
  
  cout<<"input number:" ; cin>>number1;
  cout<<"input number2:" ; cin>>number2;
  cout<<"operation = "; cin>>operation;
  
  switch(operation)
  {
    case '+':
      cout<<"Sum :"<<sumAddnumber(number1, number2)<<endl;
     break;
    case '-':
      cout<<"Sum :"<<sumMinusnumber(number1, number2)<<endl;
      break;
    case '*':
      cout<<"Sum :"<<sumMultiplenumber(number1, number2)<<endl;
      break;
    case '/':
      cout<<"Sum :"<<sumAddnumber(number1, number2)<<endl;
      break;
    case '^':
      cout<<"Sum :"<<sumExponentnumber(number1, number2)<<endl;
      break;
    default:
      cout<<"invalid operation !"<<endl;
      break;
  }
  
  return 0;
}
