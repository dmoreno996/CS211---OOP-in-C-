#ifndef PARENTCLASS_H
#define PARENTCLASS_H

#include <string>
using namespace std;

class CompSciProfessor
{
 protected:
  string profName;
  string email;
  long facultyId;

 public:
  CompSciProfessor();
  void getInfo();
  void setInfo(string name, string em, long fac);
  void print() const;

};
#endif
