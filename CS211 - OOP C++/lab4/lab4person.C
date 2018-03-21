#include <iostream>
#include "lab4person.h"

void Person:: SetAPerson(long SocNum, string FirstName, string LastName, int agenum, char gender)
{
  SSN = SocNum;
  Fname = FirstName;
  Lname = LastName;
  age = agenum;
  gen = gender;

}

void Person::PrintAPerson()
{
  cout<<"The Persons social security number is: "<<SSN<<endl;
  cout<<"The Persons first name is : "<<Fname<<endl;
  cout<<"The Persons age is : "<<age<<endl;
  cout<<"The Persons gender is: "<<gen<<endl;
}
