#ifndef CHILD_H
#define CHILD_H
#include <string>
#include "Person.h"
#include "Wife.h"
using namespace std;

class Child;
typedef Child* ChildPtr;

class Child: public Person
{
  friend class Family;
 private:
  ChildPtr mySibling;
 public:
  Child(long id,string lname, string fname){SSN = id;lName=lname;fName=fname;mySibling = NULL;}
};
#endif
/************************************
Date Written: 12/4/2015
Purpose: This Child class shares objects with its parent class which is the Person class. It contains each of those attribute and a Child type pointer which is used to point to the next child in the linked list. In case the child has siblings it is used if not the default constructor sets it to NULL.
*************************************/
