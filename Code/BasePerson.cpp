#include<cstring>
#include<iostream>
using namespace std;

class PersonClass
{
public:
  char name[20];
  char email[30];
  PersonClass(char* name, char* email)
  {
    strcpy(this->name,name);
    strcpy(this->email,email);
  }
  PersonClass(){}
  void printPersonDetails(){
    cout<<"\n\t\t\t\t\t\tName : "<<name<<endl;
    cout<<"\n\t\t\t\t\t\tEmail : "<<email<<endl;

  }
  char* getname();
  char* getemail();
};

char* PersonClass::getname()
{
  return name;
}

char* PersonClass::getemail()
{
  return email;
}
