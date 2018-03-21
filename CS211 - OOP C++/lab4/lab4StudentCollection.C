#include <iostream>
#include <vector>
#include "lab4StudentCollection.h"
#include <fstream>
using namespace std;

void StudentCollection::getInfo()
{
  long SocNum;
  string FirstName;
  string LastName;
  int agenum;
  char gender;
  long StNum; 
  long course1num;
  string course1name;
  long course2num;
  string course2name;
  long course3num;
  string course3name;
  StudentProfile new_entry;


  ifstream fin;
  fin.open ("data3.dat");
  fin>>SocNum>>FirstName>>LastName>>agenum>>gender>>StNum>>course1num>>course1name>>course2num>>course2name>>course3num>>course3name;

  while(fin)
    {

      new_entry.SetAStudentProfile(SocNum, FirstName, LastName, agenum, gender, StNum, course1num, course1name,course2num, course2name, course3num, course3name);
      
      StCollection.push_back(new_entry);
      
      fin>>SocNum>>FirstName>>LastName>>agenum>>gender>>StNum>>course1num>>course1name>>course2num>>course2name>>course3num>>course3name;

    }

  fin.close();

}
void StudentCollection::print()
{
  for(int i = 0; i< StCollection.size();i++)
    {
      StCollection[i].PrintAStudentProfile();
      cout<<endl;
    }
}
