#include "parentClass.h"
#include <iostream>
#include <string>

CompSciProfessor::CompSciProfessor()
{
  profName = "Unknown";
  email = "unknown@unknown.edu";
  facultyId = 0;
}
void CompSciProfessor::getInfo()
{
  string profName;
  string email;
  long facultyId;

  cout<<"Enter professor's name: ";
  getline(cin,profName);
  //  cin.ignore();
  cout<<"Enter professor's email: ";
  cin>>email;
  cout<<"Enter Faculty ID: ";
  cin>>facultyId;
 
  setInfo(profName, email, facultyId);
}

void CompSciProfessor::setInfo(string name, string em, long fac)
{
  profName = name;
  email = em;
  facultyId = fac;
}

void CompSciProfessor::print() const
{
  cout<<"The professor's name is: "<<profName<<endl;
  cout<<"The professor's email is: "<<email<<endl;
  cout<<"The professor's ID is: "<<facultyId<<endl;
}
