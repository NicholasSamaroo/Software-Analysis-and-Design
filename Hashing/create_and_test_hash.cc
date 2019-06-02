// Nicholas Samaroo

/* This is the main function for testing the three probing techniques */

#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_probing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
  hash_table.MakeEmpty();
  hash_table.resetCollisions();
  
  ifstream words_file;
  words_file.open(words_filename);
  
  if(words_file.fail())
  {
  	std::cout << "There was an error in opening the words.txt file ";
	return;	
  }
  
    string input_line;
    
    while(words_file.peek() != EOF) //THIS LINE CHECKS TO SEE THAT I HAVE NOT REACHED THE END OF THE DOCUMENT
	{
      getline(words_file, input_line);
      hash_table.Insert(input_line);
      //std::cout << input_line << std::endl;

    }
  //..Insert your own code
  cout << "Number of items: " << hash_table.returnNumElements() << endl;
  cout << "Size of hash table: " << hash_table.returnSize() << endl;
  cout << "Load factor: " << (hash_table.returnNumElements()) / ((double)hash_table.returnSize()) << endl;
  cout << "Collisions: " << hash_table.returnCollisions() << endl;
  cout << "Avg. number of collisions: " << (hash_table.returnCollisions()) / ((double)hash_table.returnNumElements()) << endl << endl;
  
  words_file.close();
  
  ifstream query_words_file;
  query_words_file.open(query_filename);
  
  if(query_words_file.fail())
  {
  	std::cout << "There was an error in opening the query_words.txt file ";
  	return;
  }
  
  hash_table.resetCollisions();
  std::cout << "Beginning search for query words" << endl;
  
  while(query_words_file.peek() != EOF) 
  {
      getline(query_words_file, input_line);
      
      if(hash_table.Contains(input_line)) 
	  {
        cout << input_line << ": Found in " << hash_table.returnCollisions() + 1 << " probes "<< endl;
        hash_table.resetCollisions();
      } 
	  else 
	  {
        std::cout << input_line << ": Not Found in " << hash_table.returnCollisions() + 1 << " probes " << endl;
        hash_table.resetCollisions();
      }
  }
  query_words_file.close();

}

// Sample main for program create_and_test_hash
int
main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  const string param_flag(argv[3]);
  
  //const string param_flag = "double";
  //const string words_filename = "words.txt";
  //const string query_filename = "query_words.txt";

  if(param_flag == "linear") 
  {
     HashTableLinear<string> linear_probing_table;
     TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    
  } 
  else if(param_flag == "quadratic") 
  {
    HashTable<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } 
  else if(param_flag == "double") 
  {
     HashTableDouble<string> double_probing_table;
     TestFunctionForHashTable(double_probing_table, words_filename, query_filename);    
  } 
  else 
  {
    cout << "Unknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}
