#include <iostream>
using namespace std;

struct Rumah
{
  int houseCode;
  char houseName[100]; //length
};

int main() {
  Rumah rumah; //declaration struct Rumah
  cout<<"houseCode :"; cin>>rumah.houseCode;
  cout<<"houseName :"; cin>>rumah.houseName;

  //create ouput
  cout<<"data created  "<<endl;
  cout<<"house Name : "<<rumah.houseName<<endl;
  cout<<"house Code : "<<rumah.houseCode<<endl;
}
