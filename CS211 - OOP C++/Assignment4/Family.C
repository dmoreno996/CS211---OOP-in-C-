/*********************************************
David Moreno
Assignment 4
CS 211
**********************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Family.h"
using namespace std;

Family::Family()
{
  top = NULL;
}
/********************************************
Date Written: 12/4/2015
Purpose: This routine initializes the list and creates Husband class pointer that is initiliazed to NULL.
*********************************************/
HusbandPtr Family::SearchHusband(long hSSN)
{
  HusbandPtr temp = top;
  while(temp != NULL)//Continue going through the linked list untill you reach the end
    {
      if(temp->SSN == hSSN)//if the SSN passed matches one inside the linked list then the routine is ended and the temp pointer is returned which points to that node
	return temp;
      else
	temp = temp->nextFamily;//if SSN is not in that node you move on to the next one
    }
  return NULL;//if the program is not returned before it reaches this line it  means the SSN was not found in that list 
}
/********************************************
Date Written: 12/4/2015
Purpose: This routine uses the passed id and searches for it within the linked list, it the id is found within the list then the function returns a Husband type pointer which points to the element in the list with that id.
Parameter: long hSSN(husband id that is searched for.)
Variables: HusbandPtr Temp(pointer which is returned pointing to element in list or NULL if it not found.
 ********************************************/
void Family::AddHusband(long SSN, string Fname, string Lname)
{
  if(SearchHusband(SSN) != NULL)//before you add a husband you must make sure that husband is not in the list already so you call a function which searches for it
    {
      cout<<"Another Husband Already Exist."<<endl;
      return ;
    }
  else//if the husband SSN is not in the list you can continue on with adding it
    {
      HusbandPtr temp = new Husband(SSN,Lname,Fname);//create a new Husband node pointer which calls the default constructor
      temp->nextFamily = top;//that node points to the next element in the list
      top = temp;//the new husband is now the top, making ti the first in the list, pushing back the others in the same list
    }
}
/********************************************
Date Written: 12/4/2015
Purpose: This routine first searches if the SSN passed is already in the linked list of Husbands. If it is then it cannot be added. If it is not the SearchHusband function returns NULL and a new Husband can be added to the beginning of the list.
Paramters: long SSN, string Fname, string Lname(all used to create the newc Husband Node)
Variables: A new husband node is created and is called temp that temp pointer is placed at the beginning of the list.
*********************************************/
void Family::RemoveHusband(long SSN)
{
}
/********************************************
 ********************************************/
void Family::AddWife(long SSN, string Fname, string Lname, long husbandSSN)
{
  HusbandPtr temp = SearchHusband(husbandSSN);//makes sure the husband is in the list,if he is then the pointer returned will point to where we need to add that wife
  if(temp == NULL)
    cout<<"Husband not in system."<<endl;
  else{
    temp -> myWife = new Wife(SSN,Lname,Fname);//wife is added to husband
  }
}
/********************************************
Date Written: 12/4/2015
Purpose: This routine adds a wife to an existing husband. In order to do that it must first make sure the husband is in the list, if it not then it cannot add the wife. 
Paramters: long SSN, string Fname, string Lname(used to create new wife node), long husbandSS(used to check husband in linked list)
Variables: HusbandPtr temp, new Wife
*********************************************/
void Family::RemoveWife(long husbandSSN)
{
}
//*********************************************
void Family::AddChild(long SSN, string Fname, string Lname, long fatherSSN)
{
  bool childCheck;
    HusbandPtr temp = SearchHusband(fatherSSN);//finds position in linked list if husband exist
  if(temp == NULL)
    cout<<"Father does not exist."<<endl;
  else if(temp->myWife == NULL)
    cout<<"Child could no be added because Husband has no wife."<<endl;//if husband exist but no wife then the child cannot be added
  else
    {
      if(temp->myWife->myChildren == NULL)//if the wife has no previous children then a new child is added
	{
	  temp -> myWife -> myChildren = new Child(SSN,Lname, Fname);
	}
      else
	{	
	  ChildPtr temp2 = new Child(SSN, Lname, Fname);//if the wife already exist then the new child is added at the beginning of the list and that child is
	  if(temp->myWife->myChildren->mySibling==NULL){
	  temp2 -> mySibling = temp-> myWife -> myChildren;//connected via mySibling child pointer
	  temp -> myWife -> myChildren = temp2;}
	  else if(temp->myWife->myChildren->mySibling != NULL)
	    {
	      childCheck = checkChild(SSN, fatherSSN);
	      if(childCheck == true){
		temp2->mySibling = temp->myWife->myChildren->mySibling;
		temp->myWife->myChildren = temp2;}
	      else
		cout<<"Child with that SSN already exist."<<endl;
	    }
	}
    }
}
/********************************************
Date Written: 12/4/2015
Purpose: This routine adds a child to the wife which is linked to the husband. In order to add the child first we must find the father in the linked list which is one of the paramters passed and we search using their SSN. Once the father is found if he exist in the linked list then we check if they have a wife. If they do not the child cannot be added, but if he does have a wife the child is added and linked to the wife. The child is added to the beginning of the list via the wifes myChildren child pointer.
Parameters: long SSN, string Fname, string Lname,(used to create the new child node) long FatherSSN (used to search the linked list of husbands)
*********************************************/
bool Family::checkChild(long SSN, long fatherSSN)
{
  bool check = true;
  HusbandPtr temp = SearchHusband(fatherSSN);
  ChildPtr Current = temp->myWife->myChildren;
  while(Current != NULL){
    if(Current->SSN == SSN)
      return false;
    else
      Current = Current->mySibling;
  }
  return check;
}
/********************************
Date Written: 12/9/2015
Purpose: This function searches the id of the child if it does not exist it returns true, else it returns false as the child exist in the system.
Parameters:long SSn, fatherSSN
Variables: bool check, HusbandPtr temp, ChildPtr Current
********************************/
void Family::RemoveChild(long fatherSSN, long childSSN)
{
  ChildPtr prev, temp;
  HusbandPtr Current = SearchHusband(fatherSSN);
  if(SearchHusband(fatherSSN) == NULL)
    cout<<"Husband does not exist."<<endl;
  else if(Current->myWife == NULL)
    cout<<"Husband does not have a wife."<<endl;
  else if(Current->myWife->myChildren == NULL)
    cout<<"That couple do not have any children."<<endl;
  else
    {
      temp = Current->myWife->myChildren;
      prev = temp;
      while(temp != NULL){
	  if(temp->SSN == childSSN)
	    {
	      prev->mySibling = temp->mySibling;//prev will skip over the child that needs deletion
	      delete temp;//this deletes the node to prevent a memory leak
	      return;
	    }
	  else
	    {
	      cout<<temp->SSN<<endl;
	      prev = temp;
	      temp = temp->mySibling;	     
	    }
      }
    }
}

/********************************************
Date Written: 12/9/2015
Purpose: This function gets the fatherSSN to find the husband that has thhose children nodes connected via the wife node. If it is found, it goes to the wife and checks her children if she has any. If the child is found it is deleted.
Parameters: fatherSSN is used to find the father that holds the children through the wife. And childSSN is used to know which child is to be deleted.
Variables: ChildPtr prev, and temp(temp is the one to be deleted and prev reconnects the remainding nodes to the link list so they are not lost) Current is a Husband type pointer in order to know in which husband you can find the children.
*********************************************/
void Family::PrintAFamily(long fatherSSN)
{
  HusbandPtr Family = SearchHusband(fatherSSN);//search if the family exist based on husband in the linked list 
  if(Family == NULL)
    cout<<"Family does not exist."<<endl;
  else
    {  
      cout<<Family->lName<<"\tFamily"<<":\n"//print out each attribute of the husband

	  <<Family->fName<<"\t"
	  <<Family->lName<<"\t"
	  <<Family->SSN<<endl;
      if(Family -> myWife != NULL)//if he has a wife then print out her stats if not then the printing ends here
	{
	  cout<<"Wife Info:\n"//prints out each attribute of the wife
	    
	      <<Family->myWife->fName<<"\t"
	      <<Family->myWife->lName<<"\t"
	      <<Family->myWife->SSN<<endl;
	  if(Family -> myWife -> myChildren != NULL)//as long as they have children print them out if not end the printing here
	    {
	      ChildPtr Children = Family -> myWife -> myChildren;//child pointer is made to increment throughout the linked list, in case there are more than one child
	     do
	       {
		 cout<<"Child:\n"//print out each member of one child
		     <<Children->fName<<"\t"
		     <<Children->lName<<"\t"
		     <<Children->SSN<<endl;
		 Children = Children->mySibling;
	       }while(Children != NULL);//move to next child as long as one exist and print out their stats

	     Children = NULL;
	    }
	}
    }
  cout<<endl;
}
/********************************************
Date Written: 12/4/2015
Purpose: This routine prints out one specific fammily, that family is determined based on the fatherSSN that is passed. That SSN is checked to make sure it is in the linked list if not it cannot be printed out. After it confirms and gets the position of that husband it prints out their SSN and full name. If they have a wife then it goes on to print out the Wife's information. Then it goes on to do the same with their children.
Paramters: long fatherSSN(used to find the position of where the family is
Variables: HusbandPtr Family is used to find position of husband in the linked list. ChildPtr Children is used to move through the children in the linked list.
*********************************************/
void Family::PrintAllFamilies()
{
  HusbandPtr Current = top;//creates access to the linked list
  cout<<"*****************All Families*****************"<<endl;
  while(Current != NULL)//go through the linked list
    {
      PrintAFamily(Current->SSN);//call the functions that prints that specific family(does it for each famimly)
      Current = Current->nextFamily;//mone unto the next family in the linked lsit
    }
  cout<<"**********************************************"<<endl;
}
/********************************************
Date Written: 12/4/2015
Purpose: This routine prints out the entire list of families. It reads through the linked list and passes each husband's SSN to the routine that ptrints a single family, it prints out tha husband's fmaily. It does this for each member in the linked list.
Parameters: none
Variables: HusbandPtr Current is used to move through the linked list and get each of the husband's SSN which is passed to the single family print routine
*********************************************/
void Family::ReadTransactionFile()
{
  string cmd;
  long id;
  string first;
  string last;
  long husid;
  fstream fin;

  fin.open("TransF.dat");//opens the transaction file
  if(!fin)//it that transaction file does not exist then there is an error
    cout<<"The file could not be opened."<<endl;
  else//if it is succesfully opened then you read the command
    {
      fin>>cmd;//read the first command of the transaction, the next step varies based on what the command is
      while(fin)
	{
	  if(cmd == "AddHusband")//if command is to add husband then you read the husband to be added's info and pass it to the AddHusband function
	    {
	      fin>>id>>first>>last;
	      AddHusband(id,first,last);
	    }
	  else if(cmd == "RemoveHusband")//if the command is to remove a function then it reads the SSN of that husband and calls the RemoveHusband function
	    {
	      fin>>id;
	      RemoveHusband(id);
	    }
          else if(cmd == "AddWife")//if the commmand is to add a wife then it reads the Wifes info and their husband's SSN and calls the AddWife function
            {
	      fin>>id>>first>>last>>husid;
	      AddWife(id,first,last,husid);
            }
          else if(cmd == "RemoveWife")//if the command is to remove a wife then then it reads husbands id and calls the RemoveWife function
            {
	      fin>>husid;
	      RemoveWife(husid);
            }
          else if(cmd == "AddAchild")//if the command is to add a child then it reads the hilds info and the husbands id and calls the AddChild function
            {
	      fin>>id>>first>>last>>husid;
	      AddChild(id,first,last,husid);
            }
          else if(cmd == "RemoveAchild")//if the command is to remove a child it gets the husbands id and childs id and calls the RemoveChild function
            {
	      fin>>husid>>id;
	      RemoveChild(husid,id);
            }
          else if(cmd == "PrintAFamily")//if the command is to print a fmaily it takes the husbands SSN and uses that to print out his  family
            {
	      fin>>id;
	      PrintAFamily(id);
            }
          else if(cmd == "PrintAllFamilies")//if the command is to print all families then the function PrintAllFamilies is called to print out all the fammilies
            {
	      PrintAllFamilies();
            }
	  fin>>cmd;
	}
    }
}
/********************************************
Date Written: 12/4//2015
Purpose:This routine reads the transaction file and acts accordingly to the action specified in the transaction file. Each different command calls a different function and completes a different action.
Parameters:none
Variables: string smc(reads first command and is used to determine the function called) fstream fin (used to open and read the file), long id, string first, string last(used to read the information of the new wife/child/husband that will be added to list), long husid(used in case you only need remove a child/wife/husband)
*********************************************/
