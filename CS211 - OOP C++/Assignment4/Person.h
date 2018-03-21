#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
 protected:
  long SSN;
  string fName;
  string lName;
 public:
  Person(){SSN = 0; fName="Unknown";lName="Name";}
};
#endif 
/****************************************
Date Written: 12/4/2015
Purpose:This is the parent class, since the Wife, Husband, and Child classes all contain similar objects a parent class was made.
*****************************************/
