#include <iostream>
using namespace std;

int main()
{
  try
  {
    int length,width,sum;
    if(!(cin>>length))
      throw length;
    cout<<"length = "; cin>>length;
    if(!(cin>>width))
      throw width;
    cout<<"width = "; cin>>width;
    sum = length * width;
    cout<<"sum = "<<sum<<endl;
  }
  catch(int error)
  {
    cout<<"input eror ! number allowed !"<<endl;
  }
  return 0;
}
