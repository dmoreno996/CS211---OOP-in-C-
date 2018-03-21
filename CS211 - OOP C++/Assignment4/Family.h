#ifndef FAMILY_H
#define FAMILY_H
#include "Husband.h"
#include "Wife.h"
#include "Child.h"
using namespace std;

class Family
{
 protected:
  HusbandPtr top;
 public:
  Family();
  HusbandPtr SearchHusband(long hSSN);
  void AddHusband(long SSN, string Fname, string Lname);
  void RemoveHusband(long SSN);
  void AddWife(long SSN, string Fname, string Lname, long husbandSSN);
  void RemoveWife(long husbandSSN);
  void AddChild(long SSN, string Fname, string Lname, long fatherSSN);
  bool checkChild(long SSN, long fatherSSN);
  void RemoveChild(long fatherSSN, long childSSN);
  void PrintAFamily(long fatherSSN);
  void PrintAllFamilies();
  void ReadTransactionFile();
};
#endif
