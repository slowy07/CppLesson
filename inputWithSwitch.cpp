#include <iostream>

using namespace std;

int main()
{
  char huruf;
  cout<<"masukkan huruf: "; cin>>huruf;
  switch(huruf)
  {
    case 'a': 
    //jika user menginput huruf a
      cout<<"anda mengimput huruf a";
    break;
    
    default:
    //jika user mengimput huruf lain
      cout<<"anda mengimput huruf "<<huruf;
    break;
   }
   return 0;
}
