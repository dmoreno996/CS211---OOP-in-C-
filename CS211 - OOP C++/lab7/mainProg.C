#include "childAdj.h"
#include "childTen.h"
#include "parentClass.h"
#include <iostream>
using namespace std;

int main()
{
  float salary;

   AdjunctProf Prof1;
  Prof1.getProfInfo();
  Prof1.print();
  salary = Prof1.findSalary();
  cout<<"Their salary is "<<salary<<"."<<endl;

  TenureTrackProf Prof2;
  cin.ignore();
  Prof2.getTenInfo();
  Prof2.print();
  salary = Prof2.findSalary();
  cout<<"Their salary is "<<salary<<"."<<endl;
  return 0;
}





