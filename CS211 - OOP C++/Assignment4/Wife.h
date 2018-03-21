#ifndef WIFE__H
#define WIFE__H
#include <string>
#include "Person.h"
#include "Child.h"
#include "Husband.h"
using namespace std;

class Child;
typedef Child* ChildPtr;

class Wife: public Person
{
  friend class Family;
 private:
  ChildPtr myChildren;
 public:
  Wife(long id,string lname, string fname){SSN = id;lName=lname;fName=fname;myChildren = NULL;}
};
#endif
/**********************************
Date Written: 12/4/2015
Purpose: This Wife class shares the same attributes of its parent class which is the Person class. It has its own myChildren pointer which is a Child type pointer. It establishes a link with her children. 
***********************************/
