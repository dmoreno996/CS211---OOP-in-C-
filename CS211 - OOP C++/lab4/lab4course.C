#include <iostream>
#include <string>
#include "lab4course.h"
using namespace std;

void Course:: SetACourse(long num, string name)
{
  Course_num = num;
  Course_name = name;

}

void Course:: PrintACourse()
{
  cout<<Course_name<<"\t"<<Course_num<<endl;

}

