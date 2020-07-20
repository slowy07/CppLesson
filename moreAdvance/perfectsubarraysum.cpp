#include <bits/stdc++.h>
using namespace std;

void getsumset(vector<int> set, int n, int sumtar)
{
  int x[set.size()];
  int j = set.size() - 1;

  while(n >0)
  {
    x[j] = n %2;
    n = n /2;
    j--;
  }
  int sum = 0;
  for(int i=0; i<set.size(); i++)
  {
    if(x[i] == 1)
      sum = sum + set[i];
  }

  if(sum == sumtar)
  {
    cout<< ("{ ");
    for(int i= 0; i<set.size(); i++)
      if(x[i] == 1)
        cout<<set[i]<<", ";
    cout<<("} ");
  }

}
void findsubset(vector<int> arr, int k)
{
  int x = pow(2, arr.size());
  for(int i=1; i<x; i++)
    getsumset(arr,i,k);
  
}
int main()
{
  vector<int> arr = {5,5,3,29,1,2};
  int k = 30;
  findsubset(arr,k);
  

  return 0;
}
