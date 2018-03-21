#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Course
{
public:
  long CourseNum;
  string CourseName;
};
class Student
{
public:
  long StNo;
  Course Course1;
  Course Course2;
  Course Course3;
};
class Person
{
public:
  long SSN;
  string Fname;
  string Lname;
  int age;
  char gen;
};
class StudentProfile
{
public:
  Person PersonalInfo;
  Student StdInfo;
};

void getInfo(vector<StudentProfile>&students);
void printInfo(const vector<StudentProfile>&students);

int main()
{
  vector<StudentProfile>students;
  getInfo(students);
  printInfo(students);
  
  return 0;
}

void getInfo(vector<StudentProfile>&students)
{
  StudentProfile new_entry;
  ifstream infile;
  infile.open("data3.dat");
  if(!infile)
    cout<<" The file does not exist. "<<endl;
  else
    {
      infile>>new_entry.PersonalInfo.SSN>>new_entry.PersonalInfo.Fname>>new_entry.PersonalInfo.Lname>>new_entry.PersonalInfo.age>>new_entry.PersonalInfo.gen>>new_entry.StdInfo.StNo>>new_entry.StdInfo.Course1.CourseName>>new_entry.StdInfo.Course1.CourseNum>>new_entry.StdInfo.Course2.CourseName>>new_entry.StdInfo.Course2.CourseNum>>new_entry.StdInfo.Course3.CourseName>>new_entry.StdInfo.Course3.CourseNum;

      //      students[0]=new_entry;

      while(infile)
	{
	  students.push_back(new_entry); 

	  infile>>new_entry.PersonalInfo.SSN>>new_entry.PersonalInfo.Fname>>new_entry.PersonalInfo.Lname>>new_entry.PersonalInfo.age>>new_entry.PersonalInfo.gen>>new_entry.StdInfo.StNo>>new_entry.StdInfo.Course1.CourseName>>new_entry.StdInfo.Course1.CourseNum>>new_entry.StdInfo.Course2.CourseName>>new_entry.StdInfo.Course2.CourseNum>>new_entry.StdInfo.Course3.CourseName>>new_entry.StdInfo.Course3.CourseNum;


	}
    }
  infile.close();
 }
void printInfo(const vector<StudentProfile>&students)
{
  for(int i = 0; i < students.size(); i++)
    {
      cout<<students[i].PersonalInfo.SSN<<"\t"<<students[i].PersonalInfo.Fname<<"\t"<<students[i].PersonalInfo.Lname<<"\t"<<students[i].PersonalInfo.age<<"\t"<<students[i].PersonalInfo.gen<<"\t"<<students[i].StdInfo.StNo<<"\t"<<students[i].StdInfo.Course1.CourseName<<"\t"<<students[i].StdInfo.Course1.CourseNum<<"\t"<<students[i].StdInfo.Course2.CourseName<<"\t"<<students[i].StdInfo.Course2.CourseNum<<"\t"<<students[i].StdInfo.Course3.CourseName<<"\t"<<students[i].StdInfo.Course3.CourseNum<<endl;
    }
}


