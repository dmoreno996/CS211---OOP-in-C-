#include "childTen.h"
#include <iostream>
using namespace std;

TenureTrackProf::TenureTrackProf()
{
  rank = 'A';
  YearOfExp = 0;
}

void TenureTrackProf::getTenInfo()
{
  CompSciProfessor::getInfo();
  char rank;
  int YearOfExp;
  cout<<"Enter the professor's rank: ";
  cin>>rank;
  cout<<"Enter the professor's years of experience: ";
  cin>>YearOfExp;
  setTenInfo(rank, YearOfExp);

}
void TenureTrackProf:: setTenInfo(char r, int years)
{
  rank = r;
  YearOfExp = years;
}

float TenureTrackProf:: findSalary() 
{
  float salary;

  if(rank == 'A')
    salary = 65000 + (YearOfExp *1500);
  else if(rank == 'S')
    salary = 80000 + (YearOfExp *1500);
  else if(rank == 'F')
     salary = 90000 + (YearOfExp *1500);

  return salary;
}

void TenureTrackProf:: print() const
{
  CompSciProfessor::print();
  cout<<"The professor's rank is "<<rank<<endl;
  cout<<"They have taught for "<<YearOfExp<<" years."<<endl;
}
