#include <iostream>
using namespace std;

int gcd( int n1, int n2 );

int main() 
{
  int num1, num2;
  cout << "Enter first number: ";
  cin >> num1;
  cout << "Enter second number: ";
  cin >> num2;

  cout << "Greatest Common Divisor: " << gcd(num1,num2) << endl;
  return 0;
}

int gcd( int n1, int n2 )
{
  if(n2 == 0)
    return n1;

  int f = n1 % n2;
  if( f == 0 )
    return n2;
  else
    return gcd( n2, f );
}


