// Nicholas Samaroo

/* In this file I created a parser which parses the rebase file and creates
   SequenceMap objects which is then put into a tree. The user will input some 
   recognition sequences and the program will give the corresponding enzyme acronyms
   or if not found, print that it was not found */

#include "avl_tree.h"
#include "SequenceMap.h" 

#include <iostream>
#include <string>
#include <fstream>

using namespace std; 
namespace {

//Helper function for parser
bool GetNextRecognitionSequence(string &db_line, string &a_reco_seq)
{
  if (db_line.substr(db_line.find('/')) == "//" ) 
  {
    a_reco_seq = db_line.substr(0, db_line.find('/'));
    return false;
  }
  else 
  {
    a_reco_seq = db_line.substr(0, db_line.find('/'));
    db_line = db_line.substr(a_reco_seq.length() + 1);
    return true;
  }
}

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree)
{
  string db_line;
  ifstream file_stream;
  file_stream.open(db_filename);
  
  while (getline(file_stream, db_line)) 
  {
    if (db_line.back() == '/')
	{
      string an_enz_acro = db_line.substr(0,db_line.find('/'));
      string a_reco_seq;
      string new_db_line = db_line.substr(db_line.find('/') + 1);
      
	  while(GetNextRecognitionSequence(new_db_line, a_reco_seq)) 
	  {
        SequenceMap new_sequence_map(a_reco_seq, an_enz_acro);
        a_tree.insert(new_sequence_map);
      }
      
      SequenceMap new_sequence_map(a_reco_seq, an_enz_acro);
      a_tree.insert(new_sequence_map);
    }
  }
  
file_stream.close(); 
  
  /* The following code is for the part in part 2a
  	 where the user enters three recognition sequences
  	 and the program has to print out the associate enzyme 
  	 acronyms. It displays the acronym if found and prints
  	 not found if it does not find the corresponding sequence */

  string input_seq;
  
  while (getline(cin, input_seq)) 
  {
    SequenceMap user_seq(input_seq, ""); //Enzyme acronym is intialized to an empty string since we need to find the SEQUENCE associated with the acronym
    
	if (a_tree.contains(user_seq))
	{
      a_tree.PrintUserValue(user_seq);
    }
    else 
	{
      cout << "Not Found" << endl;
    }
  } 
}


}  // namespace

//MAIN FUNCTION PROVIDED WITH THE CODE

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  cout << "Input filename is " << db_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  QueryTree(db_filename, a_tree);
  
  return 0;
}
