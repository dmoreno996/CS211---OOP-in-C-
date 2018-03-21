#include <iostream>
using namespace std;

bool checkFibonacci(int num);
int fibonacci(int n);

int main()
{
  int num;
  cout<<"Enter a number(enter a negative number to quit): ";
  cin>>num;
  while(num>=0)
    {
      if(checkFibonacci(num))
	cout<<"You got it "<<num<<" is a Fibonacci number."<<endl;
      else
	cout<<"!!!! Sorrry "<<num<<" is not a Fibonacci number."<<endl;
       cout<<"Enter a number(enter a negative number to quit): ";
       cin>>num;
    }
  cout<<"(*Thanks - Have a good Day*)"<<endl;
  return 0;
}

bool checkFibonacci(int num)
{
  int n = 0;
  while(true)
    {
      int fib = fibonacci(n);
      if(fib == num)
	return  true;
      else if(fib>num)
	return false;
      else n++;
    }
}

int fibonacci(int n)
{
  if(n == 0)
    return 0;
  if(n ==1)
    return 1;
  else
    {
      return (fibonacci(n-1)+ fibonacci(n-2));
    }
}
