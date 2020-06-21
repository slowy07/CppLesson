#include <iostream>
#include <stdio.h>
#define maksmimalstack 5
using namespace std;
struct Stack
{
  int top;
  float data_stack[4];
};
float dta;

struct Stack newStack;

//get bool if stack empty ya jol
bool isEmpty()
{
  if(newStack.top == -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isFull()
{
  if(newStack.top == maksmimalstack) //kalo dia ud terpenuhi
  {
    return true;
  }
  else
  {
    return false;
  }
}
//masukkin datanya jo
void pushData(float dta)
{
  if(isFull() == true)
  {
    cout<<"data full jol"<<endl;
  }
  else
  {
    newStack.top++;
    newStack.data_stack[newStack.top]=dta;
    
  }
}
//fungsi pop jol
void getData()
{
  if(isEmpty() == true)
  {
    cout<<"data telah kosong "<<endl;
  }
  else
  {
    cout<<"data yang terambil "<<newStack.data_stack[newStack.top]<<endl;
    newStack.top--;
  }
}
void printedData()
{
  cout<<"data yang terdapat pada stack "<<endl;
  for(int i=0; i<=newStack.top; i++)
  {
    cout<<newStack.data_stack[i]<<"   ";
  }
}
int main()
{
  newStack.top = -1;
  char menu,looping;
  do
  {
    cout<<"1. pop stack "<<endl;
    cout<<"2. push stack"<<endl;
    cout<<"3. print stack"<<endl;
    cout<<"choice : "; cin>>menu;
    
    switch(menu)
    {
      case '1':
        getData();
        break;
      case '2':
        cout<<"push data"<<endl;
        cout<<"data yng ingin disimpan di stack :"; cin>>dta;
        pushData(dta);
        break;
        looping ='y';
      
      case '3':
       cout<<"print stack "<<endl;
       printedData();
       cout<<"mengulang program ? "; cin>>looping;
      break;

      default:
        exit(0);
      break;
    }

  }
  while(looping == 'Y' || looping == 'y');

}
