#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

#include <iostream>
using namespace std;
#include "lab4StudentProfile.h"
#include <vector>

class StudentCollection
{
 private:
  vector<StudentProfile>StCollection;
 public:
  void  getInfo();
  void print();
};

#endif
