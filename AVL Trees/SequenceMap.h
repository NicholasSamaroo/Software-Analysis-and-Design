//Nicholas Samaroo

/* This is the class SequenceMap which, when created, is
   stored in the AVL Tree. It has two private variables one 
   which is a string recognition_sequence_ and a vector
   enzyme_acronyms_. The string stores the recognition sequence
   and the vector stores the enzyme acronyms */




#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include <iostream>
#include <string>
#include <vector>

class SequenceMap
{
	public:
		
		//DEFAULT VALUES FOR THE BIG FIVE
		
		~SequenceMap() = default;
    	SequenceMap(const SequenceMap &rhs) = default; 
    	SequenceMap(SequenceMap &&rhs) = default;
    	SequenceMap &operator=(const SequenceMap &rhs) = default;
    	SequenceMap &operator=(SequenceMap &&rhs) = default;
    	
    	SequenceMap(const string &a_rec_seq, const string &an_enz_acro)
    	{
    		recognition_sequence_ = a_rec_seq;
    		enzyme_acronyms_.push_back(an_enz_acro);
    	}
    	
    	bool operator<(const SequenceMap &rhs) const
    	{
    		return recognition_sequence_ < rhs.recognition_sequence_;
    	}
    	
    	friend std::ostream &operator<<(std::ostream &out, const SequenceMap &some_sequence_map)
    	{
    		for(size_t i = 0; i < some_sequence_map.enzyme_acronyms_.size();i++)
    		{
    			out << some_sequence_map.enzyme_acronyms_[i] << " ";
    		}
    		
    		return out;
    	}
    	
    	void Merge(const SequenceMap &other_sequence)
    	{
    		for(size_t i = 0; i < other_sequence.enzyme_acronyms_.size();i++)
    		{
    			enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
    		}
    	}
    	
    private:
    	
    	std::string recognition_sequence_;
    	std::vector<std::string> enzyme_acronyms_;
		
	
};

#endif //SEQUENCE_MAP_H

