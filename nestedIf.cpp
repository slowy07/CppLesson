#include <iostream>
using namespace std;

int main()
{
  int tinggi = 160;
  int umur = 25;
  
  if(tinggi >= 160)
  {
    cout<<"kamu tingginya 160"<<endl;
    if(umur <= 20)
    {
      cout<<"kamu lolos tes karena umur kamu adalah "<<umur<<" tahun"<<endl;
     }
     else
     {
      cout<<"kamu tidak lolos karena umur kamu "<<umur<<" tahun"<<endl;
     }
  else
  {
    cout<<"kamu terlalu pendek"<<endl;
  }
  
  return 0;
}
