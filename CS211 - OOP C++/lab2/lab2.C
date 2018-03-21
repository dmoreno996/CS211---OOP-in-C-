#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void insertCommand(vector<string>&V, string word, int pos);
void DeleteCommand(vector<string>&V,int pos);
void printCommand(const vector<string>&V);


int main()
{
  vector<string>V;
  string command;
  string word;
  int pos;
  ifstream fin;
  fin.open("data.txt");
  if(!fin)
    cout<<" The input file does not exist. "<<endl;
  else
    {
      fin>>command;
      while(fin)
	{
	  if(command == "Insert")
	    {
	      fin>>word;
	      fin>>pos;//prepare to do the command
	      insertCommand(V, word, pos);
	    }
	  if(command == "Delete")
	    {
	      fin>>pos;
	      DeleteCommand(V,pos);
	    }
	  if(command == "Print")
	    {
	      printCommand(V);
		}
	  fin>>command;
	}
      fin.close();
    }
  
  return 0;
}
void insertCommand(vector<string>&V, string word, int pos)
{
  //first check if command is possible
  if(pos > V.size())
    cout<<" Error inserting at "<<pos<<endl;
  else
    V.insert(V.begin()+pos,word);
}
void DeleteCommand(vector<string>&V,int pos)
{
  //first check if command is possible
  if(pos>=(V.size()))
    cout<<" Error deleting at "<<pos<<endl;
  else
    V.erase(V.begin()+pos);
}
void printCommand(const vector<string>&V)
{
  //print out everything
  for(int i =0; i<V.size(); i++)
    cout<<setw(10)<<V[i];
  cout<<endl;
}
