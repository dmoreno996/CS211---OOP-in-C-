#include "parentClass.h"

#ifndef CHILDADJ_H
#define CHILDADJ_H

class AdjunctProf: public CompSciProfessor
{
 private:
  char degree;//"B" - Bachelor "M"- MAster "P" - PhD
  int NoOfTA;
  int NoOfCourses;

 public:
  AdjunctProf();
  void getProfInfo();
  void setInfo(char deg, int num, int courses);
  float findSalary();
  void print() const;

};

#endif
