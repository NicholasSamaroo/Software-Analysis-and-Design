// NICHOLAS SAMAROO

/*
	The class Points2 essentially stores a sequence of points.
	A point is denoted like this, for example, (6,9) and the
	sequence can be of any size.The private variable sequence 
	holds an array of such points and through the "big five" 
	(i.e copy contructor, move constructor, copy assignment, 
	destructor, and move assignment) we can manipulate these 
	points with the help of some operator overloading.
*/

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
#include <stdlib.h>

namespace teaching_project {
	/* These points are essentially coordinates and through some of the
	functionalities we accomplished here we can manipulate these coordinates
	for some mathematical need or any representation that uses coordinates*/
	
	template<typename Object>
	class Points2 {
	public:
		// Default "big five" -- you have to alter them for your assignment.
		// That means that you will remove the "= default" statement.
		//  and you will provide an implementation.

		// Zero-parameter constructor. 
		// Set size to 0 and also intialize sequence_ to nullptr.
		Points2()
		{
			size_ = 0;
			sequence_ = nullptr;
		}

		// Copy-constructor.
		Points2(const Points2 &rhs)
		{
			size_ = rhs.size();
			sequence_ = new std::array<Object, 2>[size_];
			for (size_t i = 0; i < size_; i++)
			{
				sequence_[i][0] = rhs.sequence_[i][0];
				sequence_[i][1] = rhs.sequence_[i][1];
			}
		}

		// Copy-assignment. If you have already written
		// the copy-constructor and the move-constructor
		// you can just use:
		// {
		// Points2 copy = rhs; 
		// std::swap(*this, copy);
		// return *this;
		// }
		Points2& operator=(const Points2 &rhs)
		{
			Points2 duplicate = rhs;
			std::swap(*this, duplicate);
			return *this;
		}

		// Move-constructor. 
		Points2(Points2 &&rhs)
		{
			size_ = rhs.size();
			sequence_ = rhs.sequence_;

			rhs.sequence_ = nullptr;
			rhs.size_ = 0;
		};

		// Move-assignment.
		// Just use std::swap() for all variables.
		Points2& operator=(Points2 &&rhs)
		{
			std::swap(size_, rhs.size_);
			std::swap(sequence_, rhs.sequence_);

			return *this;
		}

		~Points2()
		{
			delete[] sequence_;
			size_ = 0;
		}

		// End of big-five.

		// One parameter constructor.
		Points2(const std::array<Object, 2>& item)
		{
			size_ = 1; //Equal to one because we are creating a point in the sequence_ array
			sequence_ = new std::array<Object, 2>[size_];

			sequence_[0][0] = item[0];
			sequence_[0][1] = item[1];
		}

		// Read a chain from standard input.
		void ReadPoints2() {

			// Part of code included (without error checking).
			std::string input_line;
			std::getline(std::cin, input_line);
			std::stringstream input_stream(input_line);
			if (input_line.empty()) return;

			// Read size of sequence (an integer).
			int size_of_sequence;
			input_stream >> size_of_sequence;

			// Allocate space for sequence.
			size_ = size_of_sequence;
			sequence_ = new std::array<Object, 2>[size_];

			Object token;
			
			for (size_t i = 0; input_stream >> token; ++i) 
			{
				// Reading the correct coordinates into the right sequence locations
				if ((i % 2) == 1)
				{
					sequence_[(i - 1) / 2][1] = token;
				}
				else
				{
					sequence_[i / 2][0] = token;
				}
				// Filling the sequence
				if (((i + 1) / 2) == size_)
				{
					return;
				}
			}

		}

		size_t size() const 
		{ 
			return size_; 
		}

		//@location: an index to a location in the sequence.
		//@returns the point at @location.
		//const version.
		//abort() if out-of-range.
		std::array<Object, 2>& operator[](size_t location) const 
		{
			if (location >= size_)
			{
				abort(); //C++ defined function
			}
			else
			{
				return sequence_[location];
			}
		}

		// @c1: A sequence.
		// @c2: A second sequence.
		// @return their sum. If the sequences are not of the same size, append the
		// result with the remaining part of the larger sequence.
		const friend Points2 operator+(const Points2 &c1, const Points2 &c2)
		{
			//If c1.size() is greater than c2.size() append the sum to c1
			if (c1.size() > c2.size())
			{
				Points2 copy(c1);
				for (int i = 0; i < int(c2.size()); i++)
				{
					copy[i][0] = c1[i][0] + c2[i][0];
					copy[i][1] = c1[i][1] + c2[i][1];
				}
				return copy;
			}
			else
			{
				Points2 copy(c2);
				for (int i = 0; i < int(c1.size()); i++)
				{
					copy[i][0] = c1[i][0] + c2[i][0];
					copy[i][1] = c1[i][1] + c2[i][1];
				}
				return copy;
			}
		}

		// Overloading the << operator.
		friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) 
		{
			//Handles an empty sequence
			if (some_points2.size() == 0)
			{
				std::cout << "()\n";
			}
			else
			{
				for (size_t i = 0; i < some_points2.size(); i++)
				{
					out << "(" << some_points2[i][0] << ", " << some_points2[i][1] << ") ";
				} 
				std::cout << "\n";
			}
			return out;
		}

	private:
		// Sequence of points. 
		std::array<Object, 2> *sequence_;
		// Size of sequence.
		size_t size_;

	};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_
