// Nicholas Samaroo

/* In this test tree file we run a series of test on the avl tree 
   which include getting the number of nodes in the tree, getting
   the average depth, getting the number of recursive calls for executions
   of find() and removing every other sequence in the sequences file */

#include "avl_tree.h"
#include "SequenceMap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

namespace 
{

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

/* This function is called from the main function and is integral
   in doing the computations involved in part 2c of the assignment
*/
template <typename TreeType>
void TestTree(const string &db_filename,const string &seq_filename, TreeType &a_tree)
{
  string db_line;
  ifstream file_stream(db_filename);
  
  /* This is essentially the same parser from the earlier part of the assignment
  	  but now in the test_tree file we are doing a series of tests
  	  involving the avl tree */
  	  
  while (getline(file_stream, db_line)) 
  {
    if(db_line.back() == '/')
	{
      string an_enz_acro = db_line.substr(0,db_line.find('/'));
      string a_reco_seq;
      string new_db_line = db_line.substr(db_line.find('/') + 1);
      while (GetNextRecognitionSequence(new_db_line, a_reco_seq)) 
	  {
        SequenceMap new_sequence_map(a_reco_seq, an_enz_acro);
        a_tree.insert(new_sequence_map);
      }
      
      SequenceMap new_sequence_map(a_reco_seq, an_enz_acro);
      a_tree.insert(new_sequence_map);
    }
  }
  file_stream.close();

  cout << a_tree.NumberOfNodes() << endl;
  
  float path_length = a_tree.Depth() / a_tree.NumberOfNodes(); 
  cout << path_length << endl;

  float depth_ratio = path_length / log2(a_tree.NumberOfNodes());
  cout << depth_ratio << endl;

  ifstream sequence_stream(seq_filename);

  string sequence;
  int total_num_queries = 0;
  float recursive_calls = 0;

  while (getline(sequence_stream,sequence)) 
  {
  	SequenceMap query(sequence,"");
    if (a_tree.find(query,recursive_calls)) 
	{
      total_num_queries += 1;
    }
  }
  
  sequence_stream.close();

  cout << total_num_queries << endl;
  
  float avg_recursion_calls = recursive_calls / total_num_queries;
  cout << avg_recursion_calls << endl;


  // Part 2b 5
  sequence_stream.open(seq_filename);

  string seq;
  int c = 0;
  int remove_calls = 0;
  recursive_calls = 0;
  avg_recursion_calls = 0;

  while (getline(sequence_stream, seq )) 
  {
    if (c % 2 == 0)
	{
	  bool node_removed = false;
      SequenceMap query(seq,"");
      if (a_tree.contains(query))
	  {
        a_tree.remove(query,recursive_calls,node_removed);
        
		if (node_removed)
		{
          remove_calls++;
        }
      }
      
	  c++;
    }
    else 
	{
      c++;
      continue;
    }
  }
  
  sequence_stream.close();

  
  avg_recursion_calls = recursive_calls / remove_calls; 
  cout << remove_calls << endl;
  cout << avg_recursion_calls << endl;

  cout << a_tree.NumberOfNodes() << endl;

  path_length = 0;
  depth_ratio = 0;
  
  path_length = a_tree.Depth() / a_tree.NumberOfNodes(); 
  cout << path_length << endl;

  depth_ratio = path_length / log2(a_tree.NumberOfNodes());
  cout << depth_ratio << endl;

}

}  // namespace

//MAIN FUNCTION PROVIDED WITH CODE;
int main(int argc, char **argv) 
{
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  TestTree(db_filename, seq_filename, a_tree);

  return 0;
}
