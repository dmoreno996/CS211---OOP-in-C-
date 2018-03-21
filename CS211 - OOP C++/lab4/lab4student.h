//student.h
#ifndef Student_H
#define Student_H
#include "lab4course.h"
#include <string>

using namespace std;
class Student
{
 private:
  long StNom;
  Course C1;
  Course C2;
  Course C3;
  
 public:
  void printStudent();  
  void SetAStudent(long StNum, long course1num, string course1name, long course2num, string course2name, long course3num, string course3name);

};

#endif

