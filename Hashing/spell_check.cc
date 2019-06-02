/* This is the main file for PART 3 which consists
   of the spell checker. This task consisted of parsing
   a document file and outputting all of the incorrectly
   spelled words while providing suggestions to those incorrectly
   spelled words 
*/

// Nicholas Samaroo
// File name: spell_check.cpp

#include "linear_probing.h"
#include "quadratic_probing.h"
#include "double_probing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
using namespace std;


/*This function handles certain grammer like hyphens and
  slashes and also handles the case when numbers are involved 
  in the document
*/

template<typename HashTableType>
void caseHyphen(HashTableType & hash_table, string & word, const int & position, bool & slash)
{
  string new_word = word;
  int newPosition = word.rfind('-'); 
  word = word.substr(0,position);
  new_word = new_word.substr(newPosition + 1);

  vector<string> words;
  /* The following checks for numbers in the document
     If there is a number we push word back into the words vector 
  */
  
  if(word.find_first_not_of("0123456789") == string::npos) //using library string functions
  {
    words.push_back(new_word);
  }
  
  if(new_word.find_first_not_of("0123456789") == string::npos) 
  {
    words.push_back(word);
  }
  
  if (new_word.find_first_not_of("0123456789") != string::npos && word.find_first_not_of("0123456789") != string::npos) 
  {
    words.push_back(word);
    words.push_back(new_word);
  }

  for (size_t i = 0; i < words.size(); i++) 
  {
    char character;
    string new_word = "";
    
    for (size_t j = 0; j < words[i].length(); j++)
	{
      character = tolower(words[i][j]);
      
	  if (isalpha(character)) 
	  {
        new_word += character;
      }
      
	  if(character == '\'') //if character is equal to / call the helper function
	  {
        slash = true;
      }
    }
    
	helperFunction(hash_table, new_word,slash);
  }
}

/* This is a helper function to my spell checker function. This handles
   the three cases mentioned in the PDF document
*/

template<typename HashTableType>
void helperFunction(HashTableType & hash_table, string & word, bool & slash)
{
  string new_word = word;
  
  if(word == "i") //THIS LINE ELIMINATES THE SLEW OF i's THAT WERE BEING PRINTED OUT
  {
  	return;
  }
  //CASE A
  if (!hash_table.Contains(word) && !slash) 
  {
    for(size_t i = 0; i < new_word.length() + 1; i++)
	{
      for(char c = 'a'; c <= 'z'; c++) //Comparing ascii values. Exhaustively go through each of the lower case letters
	  {
        new_word.insert(i, 1, c);
        
		if(hash_table.Contains(new_word)) 
		{
          cout << word << "---> " << new_word << endl;
        } new_word = word;
      }
    }
    
    //CASE B
    new_word = word;
    
	for(size_t i = 0; i < word.length(); i++) 
	{
      new_word.erase(i,1);
      if(hash_table.Contains(new_word)) 
	  {
        cout << word << "---> " << new_word << endl;
      } new_word = word;
    }

    //CASE C
    new_word = word;
    
	for(size_t i = 0; i < word.length() - 1; i++) 
	{
      char copy = new_word[i];
      new_word[i] = new_word[i + 1];
      new_word[i + 1] = copy;
      if(hash_table.Contains(new_word)) 
	  {
        cout << word << "---> " << new_word << endl;
      } 
	  new_word = word;
    }
  }
  slash = false;
}

template<typename HashTableType>
void spellChecker(HashTableType &hash_table, const string &document_filename, const string &dictionary_filename) {
  
  hash_table.MakeEmpty();
  hash_table.resetCollisions();

  bool slash = false;

  ifstream dictionary_file_stream;
  dictionary_file_stream.open(dictionary_filename);
  string input_feed;
  
  // We need to store the dictionary into the hash table
  while (getline(dictionary_file_stream, input_feed)) 
  {
    hash_table.Insert(input_feed);
  }
  dictionary_file_stream.close(); // We are done reading wordsEn.txt so close the file stream

  ifstream document_file_stream;
  document_file_stream.open(document_filename);
  
  while(document_file_stream >> input_feed) 
  {
    string word = "";
    char character;
    size_t position = input_feed.find('-');

    if(position != string::npos) //if the position, which should find the hyphen, is not equal to the end of the string, go to the hyphen function
	{ 
      caseHyphen(hash_table, input_feed, position, slash);
    }
    else 
	{
      for (size_t i = 0; i < input_feed.length(); i++) 
	  {
        character = tolower(input_feed[i]); //make character equal to the lower case letter of the input feed

        if(isalpha(character)) //if it is uppercase
		{
          word += character; //concatenate it to character
        }
        
		if(character == '\'') // if the character is equal to a slash set slash to true 
		{
          slash = true;
        }
      }
      
	  if(word.find_first_not_of("0123456789") == string::npos) //IF IT IS NOT A NUMBER THEN CONTINUE ON WITH NORMAL EXECUTION
      {
      	continue;
      }
      
	  helperFunction(hash_table, word, slash);
    }
    slash = false;
  }
  
  document_file_stream.close(); //close the file stream
}


//Main function for the spell checker
int main(int argc, char **argv) 
{
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <documentfilename> <dictionaryfilename>" << endl;
    return 0;
  }
  
  const string document_filename(argv[1]);
  const string dictionary_filename(argv[2]);
  //const string document_filename = "document1_short.txt";
  //const string dictionary_filename = "wordsEn.txt";
  
  //Here is where I pass in the double probing hash table, document name, and the dictionary file to the spell checker function
  HashTableDouble<string> double_probe_table;
  spellChecker(double_probe_table, document_filename, dictionary_filename);
}

