#include "childAdj.h"
#include <iostream>
#include <string>
using namespace std;

AdjunctProf::AdjunctProf()
{
  degree = 'B';
  NoOfTA = 0;
  NoOfCourses = 0;
}

void AdjunctProf::getProfInfo()
{
  CompSciProfessor::getInfo();
  char degree;
  int NoOfTA;
  int NoOfCourses;
  cout<<"Enter the degree level of the professor: ";
  cin>>degree;
  cout<<"Enter the number of courses they TA: ";
  cin>>NoOfTA;
  cout<<"Enter the number of courses they teach: ";
  cin>>NoOfCourses;

  setInfo(degree, NoOfTA, NoOfCourses);
}


void AdjunctProf::setInfo(char deg, int num, int courses)
{
  degree = deg;
  NoOfTA = num;
  NoOfCourses = courses;
}

float AdjunctProf::findSalary()
{
  float salary;
  float TAsalary;
  float CoursesSalary;
  if(degree == 'B')
  {
     TAsalary = NoOfTA * 1500;
    CoursesSalary = NoOfCourses * 3000;
    salary = TAsalary + CoursesSalary;
  }
  else if(degree == 'M')
  {
    TAsalary = NoOfTA * 2000;
    CoursesSalary = NoOfCourses * 4000;
    salary = TAsalary + CoursesSalary;
  }
  else if(degree == 'P')
  {
    TAsalary = NoOfTA * 2500;
    CoursesSalary = NoOfCourses * 5000;
    salary = TAsalary + CoursesSalary;
  }
  return salary;
}

void AdjunctProf::print() const
{
  CompSciProfessor::print();
  cout<<"The professor's degree: "<<degree<<endl;
  cout<<"They are doing "<<NoOfTA<<" class as TA's."<<endl;
  cout<<"They are teaching "<<NoOfCourses<<" classes."<<endl;
}
