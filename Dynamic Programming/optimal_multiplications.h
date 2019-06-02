/*

Name: Nicholas Samaroo
File name: optimal_multiplication.h

This is the .h file for optimal_multiplications.cpp
It contains a private variable which is a vector of vectors
which is primarly used for the matrix manipulations.
getRows and getColumns do as mentioned and the [] is overloaded 
for when we access the rows of the array

*/

#ifndef OPTIMAL_MULTIPLICATIONS_H
#define OPTIMAL_MULTIPLICATIONS_H

#include <vector>
using namespace std;

template <typename Object>
class Matrix 
{
 public:
    //Constructor for the Matrix class
    //Takes in the rows and the columns and intializes the private variable array_ to rows
    //We need to be able to resize the columns depending on the input so we resize it in the constructor
	Matrix(int rows, int colm): array_(rows) 
	{
      for (auto & row : array_) 
	  {
       row.resize(colm);
      }
    }
	
	///This is read only which is indicated by the const function
    const vector<Object> & operator[](int row) const 
	{ 
      return array_[row];
    }
	
	//This function is write only which is indicated by the lack of const
    vector<Object> & operator[](int row) 
	{ 
      return array_[row];
    }

    int getRows() const 
	{
      return array_.size();
    }
    
	int getColumns() const 
	{
      return getRows() ? array_[0].size() : 0;
    }
  
  private: 
    vector<vector<Object> > array_; //A vector of vectors which holds type object
};


#endif // OPTIMAL_MULTIPLICATIONS_H
