#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int num = 10;


void readFile(int ar[]);
void copyArray(const int ar[], int arrayB[]);
void printArrayA(const int ar[]);
void printArrayB(const int arrayB[]);
int numbersbetween(const int ar[]);
int numbersdivisible(const int ar[]);
void printIndex(const int ar[]);
double findMean(const int ar[]);
int findMin(const int ar[]);
bool searchKey(const int ar[], int key);

int main()
{
  int ar[num];
  int arrayB[num];
  int numbet;
  int numdiv;  
  double mean;
  int min;
  int key;
  bool check;

  readFile(ar);
  copyArray(ar, arrayB);
  printArrayA(ar);
  printArrayB(arrayB);
  numbet = numbersbetween(ar);
  cout<<"The number of elements between 80 and 100 are : "<<numbet<<endl;
  numdiv = numbersdivisible(ar); 
  cout<<"The number of elemnts divisible by 5 are : "<<numdiv<<endl;
  printIndex(ar);
  mean = findMean(ar);
  cout<<"The average is : "<<mean<<endl; 
  min = findMin(ar);
  cout<<"The minimum value is : "<<min<<endl;
  cout<<"Enter a key to search for : ";
  cin>>key;
  check = searchKey(ar, key);
  if(check == true)
    cout<<"The key was found. "<<endl;
  else
    cout<<"The key was not found. "<<endl;
 return 0;
}

void readFile(int ar[])
{
  ifstream fin;
  fin.open("data2.txt");
  if(!fin)
    cout<<" The input file does not exist."<<endl;
  else
    {
      for(int i = 0 ; i<num ; i++)
	fin >> ar[i];
      fin.close();
    }
}
void copyArray(const int ar[], int arrayB[])
{
  for(int i = 0 , h = num-1; i<num ;i++,h--)
      arrayB[h] = ar[i];
}
void printArrayA(const int ar[])
{
  for(int i = 0; i<num; i++)
    cout<<setw(5)<<ar[i];
  cout<<endl;
}
void printArrayB(const int arrayB[])
{
  for(int i = 0; i<num; i++)
    cout<<setw(5)<<arrayB[i];
  cout<<endl;
}
int numbersbetween(const int ar[])
{
  int yes = 0;
  for(int i = 0; i<num; i++)
    if(ar[i]>=80 && ar[i]<=100)
      yes = yes + 1;
  return yes;
}
int numbersdivisible(const int ar[])
{
  int div = 0;
  for(int i = 0; i<num; i++)
    if(ar[i]%5 == 0)
      div = div + 1;
  return div;
}
void printIndex(const int ar[])
{
  int div = 0;
  cout<<"Numbers divisible by 5 are found at index : ";
  for(int i =0; i<num; i++)
    if(ar[i]%5 == 0)
      cout<<setw(5)<<i;
  cout<<endl;
}
double findMean(const int ar[])
{
  double total = 0;
  int i= 0;  
  for(i ; i<num; i++)
    total = total + ar[i];

  return total/i;
}
int findMin(const int ar[])
{
  int MIN = 9999;
  for(int i = 0; i<num; i++)
    if(ar[i]<MIN)
      MIN = ar[i];

  return MIN;
}
bool searchKey(const int ar[], int key)
{
  bool ch=false;
  for(int i = 0; i<num; i++)
    {
      if(ar[i] == key)
	ch = true;
    }
  return ch;
}
