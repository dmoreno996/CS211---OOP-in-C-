//********************************************************************************************
// CS 211 - Lab 10
// Complete the program Lab10(Program).cpp and implement the routines that are not implemented
//********************************************************************************************
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Node;
typedef Node* NodePtr;

class CircularDLL;
class Node 
{
  friend class CircularDLL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr next;
  NodePtr prev;
};

class CircularDLL
{
private:
  NodePtr  top;
  void destroy (NodePtr&);

public:
  CircularDLL();
  CircularDLL(const CircularDLL& source);
  ~CircularDLL();
  void insertDataFromFile();
  void print ();
  bool search (int);
  void insertAfterFirst (int id, string name, string email, int age);
  void insertBeforeFirst (int id, string name, string email, int age);
  void insertAfterLast (int id, string name, string email, int age);
  void insertBeforeLast (int id, string name, string email, int age);
  void remove (int);
  void copy (NodePtr top1, NodePtr& top2);
};

// the default constructor
CircularDLL::CircularDLL()
{
  top = NULL;
}
// the copy constructor
CircularDLL::CircularDLL(const CircularDLL& source)
{
  top = NULL;
  copy(source.top, top);
}

// the destructor
CircularDLL::~CircularDLL()
{

}

//--------------------------------------------
void CircularDLL::insertDataFromFile()
{
  ifstream fin;
  int id;
  string name;
  string email;
  int age;
  fin.open("transF.dat");
  if(!fin)
    cout<<"File could not be opened."<<endl;
  else
    {
      fin>>id>>name>>email>>age;
      while(fin)
        {
          insertBeforeFirst(id,  name, email, age);
          fin>> id;
          fin>>name;
          fin>>email;
          fin>>age;
        }
    }
}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void CircularDLL::print ()
{
  cout<<"********************************************************"<<endl;
  cout<<endl;
  NodePtr temp = top;
  if(top == NULL)
    cout<<"List empty."<<endl;
  else{
  do{
    cout<<temp->stId<<"\t"
	<<temp->stName<<"\t"
	<<temp->stEmail<<"\t"
	<<temp->stAge<<endl;
    temp = temp->next;
  }while(temp != top);
  cout<<endl;}
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool CircularDLL::search (int id)
{
  return true;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 10 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertAfterFirst (int id, string name, string email, int age)
{

}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 10 <--> 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 10)

void CircularDLL::insertBeforeFirst (int id, string name, string email, int age)
{

 Node* temp = new Node;
  temp->stId = id;
  temp->stName = name;
  temp->stEmail = email;
  temp->stAge = age;

  temp->next = top;
  temp->prev = top->prev;
  top = temp;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> 10 <-->(links to the first node which is 1)

void CircularDLL::insertAfterLast (int id, string name, string email, int age)
{
  if(top == NULL){
    insertBeforeFirst(id, name, email, age);}
  else{
    Node* prev;
    Node* temp = new Node;
    temp->stId = id;
    temp->stName = name;
    temp->stEmail = email;
    temp->stAge = age;
    temp = top;
    prev= temp;
    do{
      prev = temp;
      temp = temp->next;
    }while(temp!= top);

    temp->prev->next = temp;
    temp->next = top;
  }
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 10 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertBeforeLast (int id, string name, string email, int age)
{
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void CircularDLL::remove (int id)
{
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void CircularDLL::copy (NodePtr atop, NodePtr& btop)
{

}       
//--------------------------------------------
// deallocate the nodes in a linked list
void CircularDLL::destroy(NodePtr& top) 
{

}

//--------------------------------------------

int main () 
{
  CircularDLL list1;
  list1.insertDataFromFile();
  list1.print();
  //  list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
  //list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
  //list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
  //list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
  //list1.print();
  // bool  found = list1.search (12321);
  //if (found)
  // cout << "the record was found" << endl;
  //else
  // cout << "the record was not found" << endl;
  //list1.remove (54321);
  // list1.print();
   
  //CircularDLL list2(list1);
  //list2.print();
  return 0;
}
//--------------------------------------------
