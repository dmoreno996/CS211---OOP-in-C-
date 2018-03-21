#include "lab4StudentProfile.h"
#include <iostream>

void StudentProfile:: SetAStudentProfile(long SocNum, string FirstName, string LastName, int agenum, char gender,long StNum, long course1num, string course1name, long course2num, string course2name, long course3num, string course3name)
{
  PersonalInfo.SetAPerson(SocNum,FirstName,LastName,agenum,gender);
  StdInfo.SetAStudent(StNum, course1num, course1name, course2num, course2name,course3num,course3name);

}
void StudentProfile::PrintAStudentProfile()
{
  PersonalInfo.PrintAPerson();
  StdInfo.printStudent();
}
