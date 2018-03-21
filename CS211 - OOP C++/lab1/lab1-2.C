#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int CalculateMax(int A1, int A2, int A3);
int CalculateMin(int A1, int A2, int A3);
double CalculateAvg(int A1, int A2, int A3);

int main()
{
  int id, A1=0, A2=0, A3=0;
  int max, min;
  double avg;
  int line = 0; //line number

  ifstream fin;
  fin.open("data.dat");

  if(!fin)
    cout << "The input file doesn't exist" << endl;
  else //The input file exists
    {
      //read the first line (each line has 2 numbers)
      fin >> id >> A1 >> A2 >> A3;
      //first line telling what each number means
      cout<<"Std-Id"<<setw(10)<<"A1"<<setw(10)<<"A2"<<setw(10)<<"A3"<<setw(10)<<"Min"<<setw(10)<<"Max"<<setw(10)<<"Average"<<endl;//space out the words
      cout<<"------------------------------------------------------------------"<<endl;
      //Read each line until the end of the file    
      while(fin)
        {
          line++; //update the line number
	  max = CalculateMax(A1, A2, A3);
	  min = CalculateMin(A1, A2, A3);
	  avg = CalculateAvg(A1, A2, A3);
	  cout <<id<<setw(10)<<A1<<setw(10)<<A2<<setw(10)<<A3<<setw(10)<<min<<setw(10)<<max<<setw(10)<<fixed<<setprecision(1)<<avg<<endl;
	  A1, A2, A3 = 0;

          //Read the next line
    	  fin >> id >> A1 >> A2 >> A3;
        }

      fin.close(); //close the input file when done
    }

  return 0;
}

//calculate maximum for each line
int CalculateMax(int A1, int A2, int A3)
{
  int numbers[3];
  numbers[0] = A1;
  numbers[1] = A2;
  numbers[2] = A3;
  int MAX = -99999;
  for(int i=0; i<3; i++)
    {
      if(numbers[i]>MAX)
	MAX = numbers[i];
    }
  return MAX;
}
//calculate minimum for each line
int CalculateMin(int A1, int A2, int A3)
{
  int MIN = 9999;
  int numbers[3];
  numbers[0] = A1;
  numbers[1] = A2;
  numbers[2] = A3;
  for(int i=0; i<3; i++)
    {
      if(numbers[i]<MIN)
	MIN = numbers[i];
    } 
  return MIN;
}

double CalculateAvg(int A1, int A2, int A3)
{
  double total = 0.0;
  double num=0;
  double AVG;
  int numbers[3];
  numbers[0] = A1;
  numbers[1] = A2;
  numbers[2] = A3;
  for(int i =0; i<3; i++)
    {
      total += numbers[i];
      num++;
    }
  AVG = total/num;
  
  return AVG;
}
