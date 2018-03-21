#include "parentClass.h"
#ifndef TENUREPROF_H
#define TENUREPROF_H
using namespace std;

class TenureTrackProf : public CompSciProfessor
{
 private:
  char rank;//"A"- Assistant "S"- Associate "F"-Full Professor
  int YearOfExp;

 public:
  TenureTrackProf();
  void  getTenInfo();
  void setTenInfo(char r, int years);
  float findSalary();
  void print() const;
};
#endif
