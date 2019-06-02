/*

Name: Nicholas Samaroo
File name: optimal_multiplications.cpp

This file handles the optimal multiplications and the optimal ordering
for the dimensions_file.txt. First we intialize our vector of Matrix instances 
by reading in the dimensions in the dimensions file. multiplyMatrix is then
called which calculates the optimal number of multiplications which in turn calls ordering
which returns the optimal ordering
*/

#include <iostream>
#include "optimal_multiplications.h"
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

const int INFINITY = std::numeric_limits<int>::max(); 

//This functions handles the printing of the optimal ordering 
void ordering(int i, int j, int size, int array[], char &name) 
{
  if (i == j) 
  {
    cout << name++;
  }
  else 
  {
    cout << "(";
    ordering(i, *((array + i * size) + j), size, array, name);
    ordering( *((array + i * size) + j ) + 1, j, size, array, name);
    cout << ")";
  }
}

//This function handles the calculation and printing of the optimal number of multiplications
//It takes in a vector of Matrix instances, in this case ints.
int multiplyMatrix(vector <Matrix<int>> &vector_matrix) 
{
  int size = vector_matrix.size() + 1;
  int m[size][size];
  int print_array[size][size];
  int j;
  int smallest;

  for (int i = 1; i < size; i++) //Multiplying a matrix by itself costs nothing so intially we start with 0
  {
    m[i][i] = 0;
  }

  for (int length_of_chain = 2; length_of_chain < size ; length_of_chain++) 
  {
    for (int i = 1; i < size - length_of_chain + 1; i++) 
	{
      j = length_of_chain + i - 1;
      m[i][j] = INFINITY;
      for (int k = i; k <= j - 1; k++) 
	  {
        smallest = m[i][k] + m[k + 1][j] + vector_matrix[i - 1].getRows() * vector_matrix[k].getRows()  * vector_matrix[j - 1].getColumns();
        
        if (smallest < m[i][j]) 
		{
          m[i][j] = smallest;
          print_array[i][j] = k;
        }
      }
    }
  }
  
  char name = 'A'; //intially print A and then from this point on print the other letters
  ordering(1, size - 1, size, (int *)print_array, name);
  cout << endl;
  return m[1][size - 1];
}

//This funtion intializes vector_matrix via the inputs from the dimension file
void intialize(const string & file_name, vector <Matrix<int>> &vector_matrix) 
{
	
  ifstream file_stream(file_name);
  int a;
  int b;
  int c;
  bool c_occupied = false;

  while (file_stream >> a) 
  {
    if (c == b && c_occupied == true) 
	{
      Matrix<int> object(c,a);
      vector_matrix.push_back(object);
    }
    
    if (file_stream >> b) 
	{
      Matrix<int> object(a,b);
      vector_matrix.push_back(object);
    }
    
    c = b;
    c_occupied = true;
  }
  
  file_stream.close();
}

int main(int argc, char **argv) 
{
  if (argc != 2) 
  {
    cout << "Usage: " << argv[0] << " <dimensions_file>" << endl;
    return 0;
  }
  
  vector<Matrix<int> > vector_matrix;
  const string input_file = argv[1];
  //const string input_file = "dimensions_file.txt";

  intialize(input_file, vector_matrix);
  
  cout << endl << "Optimal ordering for " << input_file << ": ";
  int output = multiplyMatrix(vector_matrix);
  cout << "Optimal number of multiplications for " << input_file << ": " << output << endl << endl;
}



