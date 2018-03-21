#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void ProcessARow(int A1, int A2, int A3, int& min, int& max, double& avg);

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
      while(fin)
        {
          line++;
	  ProcessARow(A1, A2, A3, min, max, avg);
	  cout <<id<<setw(10)<<A1<<setw(10)<<A2<<setw(10)<<A3<<setw(10)<<min<<setw(10)<<max<<setw(10)<<fixed<<setprecision(1)<<avg<<endl;
	  A1, A2, A3 = 0;
	  fin >> id >> A1 >> A2 >> A3;
     
        }

      fin.close();
    }

  return 0;
}

void ProcessARow(int A1, int A2, int A3, int& min, int& max, double& avg)
{
  int numbers[3];
  double total = 0.0;
  double num =0;

  min= A1;
  max= A1;
  avg= 0;
  numbers[0] = A1;
  numbers[1] = A2;
  numbers[2] = A3;
  for(int i=0; i<3; i++)
    {
      if(numbers[i]>max)
	max = numbers[i];
    }

  for(int l=0; l<3; l++)
    {
      if(numbers[l]<min)
	min = numbers[l];
    } 
  for(int m =0; m<3; m++)
    {
      total += numbers[m];
      num++;
    }
  avg = total/num;
  
}
