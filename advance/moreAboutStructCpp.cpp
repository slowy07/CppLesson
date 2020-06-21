#include <iostream>
using namespace std;

struct locationPerson
{
  char city[30]; 
  char street[30];
};
struct birthday
{
  int day,month,year;
};
struct Person
{
  char name [12];
  locationPerson location;
  birthday birthdayPerson;
};
int main(){
  Person PersonData;
  cout<<"Name     : "; cin>>PersonData.name;
  cout<<"birthday "<<endl;
  cout<<"day    : "; cin>>PersonData.birthdayPerson.day;
  cout<<"month  : "; cin>>PersonData.birthdayPerson.month;
  cout<<"year   : "; cin>>PersonData.birthdayPerson.year;
  cout<<"Live city   : "; cin>>PersonData.location.city;
  cout<<"street      : "; cin>>PersonData.location.street;

  cout<<"name : "<<PersonData.name;
  cout<<"birthday :"<<PersonData.birthdayPerson.day<<"/"<<PersonData.birthdayPerson.month<<"/"<<PersonData.birthdayPerson.year<<endl;
  cout<<"live at "<<PersonData.location.city<<" "<<PersonData.location.street<<endl;
}
