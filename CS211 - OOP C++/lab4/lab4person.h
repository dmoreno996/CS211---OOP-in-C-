//person.h
#ifndef Person_H
#define Person_H
#include <string>
using namespace std;
#include "lab4student.h"

class Person
{
 private:
  long SSN;
  string Fname;
  string Lname;
  int age;
  char gen;
 public:
  void PrintAPerson();
  void SetAPerson(long SocNum, string FirstName, string LastName, int agenum, char gender);

};

#endif
