#include <iostream>

#include "lab4student.h"
using namespace std;

void   Student:: SetAStudent(long StNum, long course1num, string course1name, long course2num, string course2name, long course3num, string course3name)
{
  StNom = StNum;
  C1.SetACourse(course1num, course1name);
  C2.SetACourse(course2num, course2name);
  C3.SetACourse(course3num, course3name);

}


void Student:: printStudent()
{
  cout<<"\tStudent's Number:\t"<<StNom<<endl;
  cout<<"\tCourse 1:\n";
  C1.PrintACourse();
  cout<<"\tCourse 2:\n";
  C2.PrintACourse();
  cout<<"\tCourse 3:\n";
  C3.PrintACourse();
  
}



