#ifndef StudentProfile_H
#define StudentProfile_H

#include <string>
using namespace std;
#include "lab4person.h"
#include "lab4student.h"

class StudentProfile
{
 private:
  Person PersonalInfo;
  Student StdInfo;
 public:
  void PrintAStudentProfile();
  void SetAStudentProfile(long SocNum, string FirstName, string LastName, int agenum, char gender,long StNum, long course1num, string course1name, long course2num, string course2name, long course3num, string course3name);

};
#endif
