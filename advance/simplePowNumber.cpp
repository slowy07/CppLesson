#include <iostream>
using namespace std;


int getPowNumber(int num1, int num2);
{
  int result=1;
  for(int i=0; i<num2; i++)
  {
    result *= num1;
  }
  return result;
}
int main()
{
  int number1,number2;
  cout<<"input number = "; cin>>number1;
  cout<<"input number 2 = "; cin>>number2;
  cout<<getPowerNumber(number1,number2)<<endl;
  return 0;
}
