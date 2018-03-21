#ifndef HUSBAND_H
#define HUSBAND_H
#include <string>
#include "Person.h"
#include "Wife.h"
using namespace std;

class Wife;
typedef Wife* WifePtr;
class Husband;
typedef Husband* HusbandPtr;

class Husband: public Person
{
  friend class Family;
 private:
  HusbandPtr nextFamily;
  WifePtr myWife;
 public:
  Husband(long id,string lname, string fname){SSN = id;lName=lname;fName=fname;nextFamily=NULL;myWife=NULL;}
};
#endif
/***************************************
Date Written: 12/4/2015
Purpose: This Husband class shares attributes with its parent class which is the person class. It has two pointers which are both set to NULL in the default constructor. This class has two pointers, one points to the next husband in the singular linked list and the other points to his wife which is connected to their children which creates the family.
***************************************/
