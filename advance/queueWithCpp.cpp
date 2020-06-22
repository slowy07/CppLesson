#include <iostream>
#include <stdlib.h>
#include <stdio.h> //for exit program
#define maxantrian 20
using namespace std;

/**
  tanpa struct queue
  kalo pake struct nanti kesusahan kau jo :v
  **/

int dataAntrian[maxantrian];
int head = -1;
int tail = -1;


bool isEmpty()
{
  if(tail == -1)
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
  if(tail == maxantrian -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
//antrian masuk jo
void antrianGoIn(int nomor)
{
  if(isEmpty())
  {
    head = tail = 0;
  }
  else
  {
    tail++;
  }
  dataAntrian[tail] = nomor;
}

void antrianGoOut()
{
  if(isEmpty())
  {
    cout<<"antrian sudah kosong";
  }
  else{
    for(int i=head; i<tail; i++)
    {
      dataAntrian[i] = dataAntrian[i+1];
    }
    tail--;
    if(tail == -1)
    {
      head = -1;
    }
  }
}
//clear data jo
void clearSemuaAntrian()
{
  head=tail=-1;
}
//view data ni jo
void printedData()
{
  if(isEmpty())
  {
    cout<<"antrian kosong"<<endl;
  }
  else
  {
    for(int a=head; a<tail; a++)
    {
      cout<<"antrian : "<<dataAntrian[a]<<endl;
    }
  }
}

int main()
{
  //kali ini do while ak pake int jo
  int choose, p=1, urutan;
  do
  {
    cout<<"1. tambah antrian "<<endl;
    cout<<"2. panggil antrian"<<endl;
    cout<<"3. print antrian "<<endl;
    cout<<"4. bershikan antrian"<<endl;
    cout<<"5. exit"<<endl;
    cout<<"choice : "; cin>>choose;  
    if(choose ==1)
    {
      if(isFull())
      {
        cout<<"antrian sudah penuh ";
      }
      else
      {
        urutan = p;
        antrianGoIn(urutan);
        cout<<"Antrian Ke : "<<p<<endl;
        cout<<"Antrian : "<<tail<<endl; 
      }
    }
    if(choose == 2)
    {
      cout<<dataAntrian[head]<<endl;
      antrianGoOut();
      cout<<endl;
      cout<<"antrian selanjutnya "<<endl;
    }
    if(choose == 3)
    {
      printedData();
    }
    if(choose == 4)
    {
      clearSemuaAntrian();
    }
    if(choose == 5)
    {
      exit(0);
    }    
  }
  while(choose != 5);
}
