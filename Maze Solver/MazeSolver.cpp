#include "MazeSolver.h"
#include <fstream>

using namespace std;

/* 
   Name: Nicholas Samaroo
   File name: MazeSolver.cpp
   CSCI 235, Fall 2018, Project 4
   This is the instantiation file for MazeSolver.h
   which solves a maze given the input file and
   prints a solution, if any, to standard output.
*/

MazeSolver::MazeSolver(std::string input_file) //intializes maze and solution from the given input_file
{
	ifstream in_stream;
	in_stream.open(input_file);
	
	if(in_stream.fail())
	{
		cout << "Cannot read from " << input_file << endl;
	}
	else
	{
		in_stream >> maze_rows_ >> maze_columns_;
		initializeMaze(maze_rows_, maze_columns_);
		fillMaze(in_stream);
		initializeSolution();
		maze_ready = true;
		in_stream.close();
		
	}
}

bool MazeSolver::mazeIsReady() //return is the maze is ready
{
	return maze_ready;
}

bool MazeSolver::solveMaze()
{
	Position current_p;
	current_p.row = 0;
	current_p.column = 0;
	
	current_p = backtrack_stack_.top(); //sets current position to the top of the stack. Should be the position next to [0][0] or below it.
	
	while(!backtrack_stack_.empty())
	{
		if(maze_[current_p.row][current_p.column] == '$')
		{
			std::cout << "Found the exit!!!" << std::endl;
			return true;
		}
		else if(extendPath(current_p))
		{
			solution_[current_p.row][current_p.column] = '>'; 
			current_p = backtrack_stack_.top();
		}
		else
		{
			maze_[current_p.row][current_p.column] = 'X';
			solution_[current_p.row][current_p.column] = '@';
			backtrack_stack_.pop();
			
			if(!backtrack_stack_.empty())
			{
				current_p = backtrack_stack_.top();
			}
			else
			{
				std::cout << "This maze has no solution." << std::endl;
				return false;
			}
		}
		
	}
	return true;	
}

MazeSolver::~MazeSolver()
{
	delete maze_;
	delete solution_;
}

void MazeSolver::initializeMaze(int rows, int columns)
{
	if(rows >= 0 && columns >= 0)
	{
		maze_ = new char*[rows];
		
		for(int i = 0; i < rows; i++)
		{
			maze_[i] = new char[columns];
		}
	}
	else
	{
		cout << "Value for either row or column is not greater than or equal to 0\n";
	}
} 

void MazeSolver::fillMaze(std::ifstream& input_stream)
{
	for(int i = 0;i < maze_rows_;i++)
	{
		for(int j = 0; j < maze_columns_; j++)
		{
			input_stream >> maze_[i][j];
		}
	}
}

void MazeSolver::initializeSolution()
{
	copyMazetoSolution();
	
	Position z;
	z.row = 0;
	z.column = 0;
	
	if(maze_[z.row][z.column] == '_') // sets [0][0] to a path character
	{
		solution_[z.row][z.column] = '>';
		backtrack_stack_.push(z);
	}
	
	Position x;
	x.row = 0;
	x.column = 1;
	
	if(maze_[x.row][x.column] == '_') //sets [0][1] to a path character
	{
		solution_[x.row][x.column] = '>';
		backtrack_stack_.push(x);
	}
	else
	{
		Position y;
		y.row = 1;
		y.column = 0;
		
		solution_[y.row][y.column] = '>'; //if [0][1] is equal to a * set the one below [0][0] to a path character
		backtrack_stack_.push(y);
	}
	
}

void MazeSolver:: copyMazetoSolution() //intializes solution with maze
{
	solution_ = new char*[maze_rows_];
	
	for(int i = 0; i < maze_rows_; i++)
	{
		solution_[i] = new char[maze_columns_];
	}
	
	for(int k = 0; k < maze_rows_ ; k++)
	{
		for(int l = 0; l < maze_columns_ ; l++)
		{
			solution_[k][l] = maze_[k][l];
		}
	}
}

bool MazeSolver::extendPath(Position current_position)
{
	bool extended = false;

	if(isExtensible(current_position,SOUTH)) // if extensible SOUTH, get the new position SOUTH of the current position and push it on the stack;
	{
		backtrack_stack_.push(getNewPosition(current_position,SOUTH));
		extended = true;
	}
	
	if(isExtensible(current_position,EAST)) //if extensible EAST, get the new position extending EAST and push it on the stack.
	{
		backtrack_stack_.push(getNewPosition(current_position,EAST));
		extended = true;
	}
	
	return extended;
}

Position MazeSolver::getNewPosition(Position old_position, direction dir)
{
	if(dir == SOUTH) //if the direction is SOUTH, set p to the values of the southern position and return p
	{
		Position south_p;
		
		south_p.row = 0;
		south_p.column = 0;
		old_position.row = old_position.row + 1; //increments the row value of the old position to the new southern position
		
		south_p.row = old_position.row;      //new row
		south_p.column = old_position.column; //same column because we want to move SOUTH

		return south_p;
	}
	else // if the position is EAST; set p to the values of the eastern position and return p
	{
		Position east_p;
		east_p.row = 0;
		east_p.column = 0;
		
		old_position.column = old_position.column + 1; 
		east_p.row = old_position.row;
		east_p.column = old_position.column;
		return east_p;
	}
	
}

bool MazeSolver::isExtensible(Position current_position, direction dir)
{
	if(dir == SOUTH) //if the direction is SOUTH;to look SOUTH is to look one row below you so increment the row and look at that position with the same column
	{
		current_position.row = current_position.row + 1;
		
		if(current_position.row > (maze_rows_ - 1))
		{
			return false;
		}
		else if(maze_[current_position.row][current_position.column] == '_' || maze_[current_position.row][current_position.column] == '$')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else //else, the direction must be EAST; to look EAST is the look one column ahead in the same row so increment column and look at the position
	{
		current_position.column = current_position.column + 1;
		
		if(current_position.column > (maze_columns_ - 1))
		{
			return false;
		}
		else if(maze_[current_position.row][current_position.column] == '_' || maze_[current_position.row][current_position.column] == '$')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
}

void MazeSolver::printSolution() //prints the solution to standard output
{
	std::cout << "The solution to this maze is: " << std::endl;
	
	for(int k = 0; k < maze_rows_ ; k++)
	{
		std::cout << endl;
		
		for(int l = 0; l < maze_columns_ ; l++)
		{
			cout << solution_[k][l] << " ";
			
			
		}
	}
	std::cout << endl;
	
}





