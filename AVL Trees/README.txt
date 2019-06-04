

You can compile everything by typing 

make clean
make all

You can compile one program individually by just typing make <Program Name>, for example make query_tree

By typing make clean
You delete all .o files and executables.

--Note that file avl_tree_modified.h is not provided.

i. I COMPLETED ALL PARTS OF THE ASSIGNMENT EXCEPT FOR PART 2C
ii. Some bugs I encountered throughout programming this were some bug issues
iii. Compile this program as stated in the PDF for the assignment

----------------------------------------------------------------------------------
Program instructions

PART 1
First, create a class object named SequenceMap that has as private data members the
following two:
string recognition_sequence_ ;
vector<string> enzyme_acronyms_;

Other than the big-five (note that you can use the defaults for all of them), you have to add
the following:
a) A constructor SequenceMap(const string &a_rec_seq, const
string &an_enz_acro),that constructs a SequenceMap from two strings
(note that now the vector enzyme_acronyms_ will contain just one element,
the an_enz_acro).
b) bool operator<(const SequenceMap &rhs) const, that operates
based on the regular string comparison between the
recognition_sequence_ strings (this will be a one line function).
c) Overload the operator<< for SequenceMap.
d) void Merge(const SequenceMap &other_sequence). This function
assumes that the object’s recognition_sequence_ and
other_sequence.recognition_sequence_ are equal to each other. The
function Merge() merges the other_sequence.enzyme_acronym_ with
the object’s enzyme_acronym_. The other_sequence object will not be
affected.

PART 2

a)You will create a parser to read in this database and construct an AVL tree. For each line of
the database and for each recognition sequence in that line, you will create a new
SequenceMap object that contains the recognition sequence as its
recognition_sequence_ and the enzyme acronym as the only string of its
enzyme_acronyms_, and you will insert this object into the tree

./query_tree rebase210.txt
./query_trees rebase210.txt < input_part2a.txt

b) Next, create a test routine named test_tree that does the following in the sequence
described below: Parses the database and construct a search tree (this is the same as in Part2(a)).
2. Prints the number of nodes in your tree 𝑛.
3. Computes the average depth of your search tree, i.e. the internal path length
divided by 𝑛.
  a. Prints the average depth.
  b. Prints the ratio of the average depth to log% 𝑛. E.g., if average depth is 6.9
     and log2 𝑛 = 5.0, then you should print 6.9 / 5.0 = 1.38
4. Searches (find()) the tree for each string in the sequences.txt file and counts
   the total number of recursive calls for all executions of find().
  a. Prints the total number of successful queries (number of strings found).
  b. Prints the average number of recursion calls, i.e. #total number of
     recursion calls / number of queries.
5. Removes every other sequence in sequences.txt from the tree and counts the
   total number of recursion calls for all executions of remove().
  a. Prints the total number successful removes.
  b. Prints the average number of recursion calls, i.e. #total number of
     recursion calls / number of remove calls.
6. Redo steps 2 and 3:
  a. Prints number of nodes in your tree.
  b. Prints the average depth.
  c. Prints the ratio of the average depth to log2 𝑛
  
  ./test_tree rebase210.txt sequences.txt

c)You will use the avl_tree.h code you have written for Part2(b) and you will modify it in
order to implement double rotations directly instead of calling the two single rotations.
Name your modified implementation avl_tree_modified.h. Run the exact same routines as
in Part2(b), but now with your modified Avl implementation. The executable should be
named test_tree_mod. The results should be the same as in Part2(b).

./test_tree_mod rebase210.txt sequences.txt




