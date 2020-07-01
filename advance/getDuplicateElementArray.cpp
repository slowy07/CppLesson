#include <iostream>
#include <bits/stdc++.h> 
using namespace std;


void getDuplicateElement(int arr[],int size)
{
    int zol,sayuti;
    cout<<"duplicate element :"<<endl;
    for(zol=0; zol<size; zol++)
    {
        for(sayuti=zol+1; sayuti<size; sayuti++)
        {
            if(arr[zol] == arr[sayuti])
            {
                cout<<arr[zol]<<endl; 
            }
        }
    }
}

int main()
{
    int arr[] = {2,1,5,3,2,5,4};
    //mengetahui ukuran array nich 
    cout<<"array is"<< endl ;
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    for(int i =0; i<arr_size; i++)
    {
      cout<<arr[i];
    }
    cout<<endl;
    getDuplicateElement(arr, arr_size);
    return 0;
}
