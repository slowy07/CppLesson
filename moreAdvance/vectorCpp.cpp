#include <bits/stdc++.h> 
using namespace std;


int main()
{
  int arr[] = {2,3,4,7,8};
  vector<int> vectorData(arr, arr+ sizeof(arr)/ sizeof(int));
  
  for(int i=0; i<vectorData.size(); i++)
  {
    cout<<vectorData[i]<<" ";
  }
  cout<<endl;
  cout<<"size "<<vectorData.size()<<endl;
  cout<<"first elemen "<<vectorData.front()<<endl;
  cout<<"last elemen "<<vectorData.back()<<endl;
  cout<<"third elemen "<<vectorData.at(2)<<endl;
  
  return 0;
}
