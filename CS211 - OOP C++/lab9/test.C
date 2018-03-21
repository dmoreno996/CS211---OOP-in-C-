#include <iostream>
using namespace std;

typedef int* intptr;

int main () {
  intptr ptr1, ptr2;
  ptr1 = new int;
  *ptr1 = 12345;
  delete ptr1; 
  ptr1 = NULL;
  ptr2 = new int;
  ptr1 = new int;
  cout << *ptr1 << endl;
  return 0;
}



























































