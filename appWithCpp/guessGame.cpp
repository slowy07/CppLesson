#include <iostream>
using namespace std;

int main()
{
  int live = 3, number_gues=0, secret_gues_number=100;
  int guess;
  bool  winorlose = false;
  while(secret_gues_number != guess && !winorlose )
  {
    if(number_gues < live )
    {
      cout<<"secret number  :"; cin>>guess;
      number_gues++;
    }
    else
    {
      winorlose = true;
    } 
  }
  if(winorlose)
  {
    cout<<"lose";
  }
  else
  {
    cout<<"win";
  }

  return 0;
}
