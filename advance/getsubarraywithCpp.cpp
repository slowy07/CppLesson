#include<iostream>
using namespace std; 

void printarray(int arr[], int elemen) 

{ 

    for (int i=0; i <elemen; i++) 

    {

        for (int j=i; j<elemen; j++) 

        { 

            for (int k=i; k<=j; k++) 

                cout << arr[k] << " "; 

            cout << endl; 

        } 

    } 

} 
int main() 

{ 

    int arr[] = {2,3,4,5}; 

    int elemen = sizeof(arr)/sizeof(arr[0]); 
    printarray(arr, elemen); 

    return 0; 

} 

