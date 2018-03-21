
#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>

using namespace std;

class Node;
typedef Node* NodePtr;

class LL;
class Node 
{
  friend class LL;
private:
  int stId;//
  string stName;//
  string stEmail;//
  int stAge;//data part of the node

  NodePtr next;//creates a pointer named next that points to next member in the list
};

class LL
{
private:
  NodePtr  top;//will hold the address of the first node in a way the name of the linked list
  void destroy (NodePtr&);

public:
  LL();
  LL(const LL& source);
  ~LL();
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

LL::LL()
{
  top  = NULL;
}

LL::LL(const LL& source)
{
  top = NULL;
  copy(source.top, top);  
}

LL::~LL()
{

  destroy(top);

}

void LL::insertDataFromFile()
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
	  insertAfterLast(id,  name, email, age);
	  fin>> id;
	  fin>>name;
	  fin>>email;
	  fin>>age;
	}
    }
}

void LL::print ()
{
  cout<<"********************************************************"<<endl;
  cout<<endl; 
  Node* temp = top;
  while(temp != NULL)
    {
      cout<<temp->stId<<"\t"
	  <<temp->stName<<"\t"
	  <<temp->stEmail<<"\t"
	  <<temp->stAge<<endl;
      temp = temp->next;
    }
  cout<<endl;  
}

bool LL::search (int id)
{
  Node* temp = top;
  while(temp!= NULL)
    {
      if(temp->stId == id)
	return true;
      else
	temp = temp -> next;
    }
  return false;
}

void LL::insertAfterFirst (int id, string name, string email, int age)
{
  //  int pos= 0;
  Node* temp1 = new Node;
  temp1 -> stId = id;
  temp1 -> stName = name;
  temp1 -> stEmail = email;
  temp1 -> stAge = age;
  temp1 ->next = top->next;
  top->next = temp1;
  /******************
  if(top == NULL)
    {
      temp1 ->next = top;
      top = temp1;
    }
  else
    {
      while(pos != 1)
	{
	  temp1 -> next = temp2->next; 
	  pos ++;
	}
      top->next = temp1;
    }
  **********************/
}
void LL::insertBeforeFirst (int id, string name, string email, int age)
{
  Node* temp = new Node;
  temp -> stId = id;
  temp -> stName = name;
  temp -> stEmail = email;
  temp -> stAge = age;
  temp -> next = top;
  top = temp;
}

void LL::insertAfterLast (int id, string name, string email, int age)
{
  if(top == NULL)
    insertBeforeFirst(id, name, email, age);
  else
    {
      
      Node* temp = new Node;//creates new node
      temp -> stId = id;
      temp -> stName = name;
      temp -> stEmail = email;
      temp -> stAge = age;
      temp -> next = NULL;//since it will be last its pointer should be NULL
      
      Node* templast = top;//create pointer that will go down the list and link the new Node to the end
      while(templast->next != NULL)//as long as you are not at the end continue moving down the list
	{
	  templast = templast ->next;//templast->next will move on and templast will point to the next node 
	}  
      templast ->next  = temp;  //make the last pointer point to the pointer temp which is pointing at a new node 
    }
}

void LL::insertBeforeLast (int id, string name, string email, int age)
{
  Node* temp = new Node;//creates new node
  temp -> stId = id;
  temp -> stName = name;
  temp -> stEmail = email;
  temp -> stAge = age;

  Node* temp2 = top;
  Node* prev = NULL;
  while(temp2 -> next != NULL)
    {
      prev = temp2;
      temp2 = temp2->next;           

    }
  prev->next = temp;
  temp->next = temp2;
 

}

void LL::remove (int id)
{
  Node* temp = top;
  Node* prev ;
  while(temp ->next != NULL)
    {
      prev = temp;
      temp = temp->next;     
      if(temp->stId == id)
	{
	  prev->next = temp->next;
	  delete temp;
	  return;
	}	
    }
}

void LL::copy (NodePtr atop, NodePtr& btop)
{
  NodePtr acurr, bcurr;
  destroy(btop);
 
 
  btop = new Node;
  btop -> stId = atop -> stId;
  btop -> stName = atop -> stName;
  btop -> stEmail = atop -> stEmail;
  btop -> stAge = atop -> stAge;
  
  bcurr = btop; 
  acurr = atop; 
  while(acurr->next != NULL)
    {
      bcurr->next = new Node;
      acurr = acurr->next;
      bcurr = bcurr ->next;    
      bcurr -> stId = acurr -> stId;
      bcurr -> stName = acurr -> stName;
      bcurr -> stEmail = acurr -> stEmail;
      bcurr -> stAge = acurr -> stAge;

  
    }
  bcurr ->next = NULL;
}       

void LL::destroy(NodePtr& top) 
{
  if(top == NULL)
    delete top;
  else
    {
      NodePtr p = top;
      while(top->next  != NULL)
	{
	  p = p->next;
	  delete top;
	  top = p;
	}
      p = NULL;
      delete p;
    }
}

//----------------------------------------------------------------------
int main () 
{
  LL list1;
  list1.insertDataFromFile();
  list1.print();
  list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
  list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
  //  list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();
  /*******************************
  list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
  list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
  list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();
  bool  found = list1.search (12321);
  if (found)
    cout << "That ID is in our records." << endl;
  else
    cout << "Unfortunately, that ID is not in our records." << endl;
  list1.remove (54321);
  list1.print();
   
  LL list2(list1);
  list2.print();
  *********************************/
  return 0;
}

