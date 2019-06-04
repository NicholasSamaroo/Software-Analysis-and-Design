i. I only completed Part 1 (Graph Representation) and Part 2 (Dijkstra’s Algorithm Implementation 1)

ii. There are no bugs with my program.
Throughout the course of me programming
the project I had some errors with seg faults
but other than that it was allright.

iii. FIRST make clean and then make all

     You can run PART 1 like this for example
     ./CreateGraphAndTest Graph1.txt AdjacencyQueries.txt

     You can run PART 2 like this for example
     ./FindPaths Graph2.txt 1

iv. All input files are provided with the code
-----------------------------------------------------------
PROGRAM INSTRUCTIONS

Represent a graph using an adjacency list. In order to test your implementation you will also read a
second text file (let us call it AdjacencyQueries.txt) that will contain a set of pair of vertices. Your
program (name it CreateGraphAndTest) will have to first create the graph by reading it from text
file Graph1.txt. It will then open the file AdjacenyQueries.txt and for each pair of vertices in it you
will cout whether the vertices are adjacent or not, and if they are you will cout the weight of the
edge that connects them.
For example if the file AdjanceQueries.txt contains
4 1
3 4
1 5
5 1
1 3
Then the output should be
4 1: Not connected
3 4: Connected, weight of edge is 50.2
1 5: Connected, weight of edge is 0.5
5 1: Not connected
1 3: Not connected

So, your program can be called for example as:
./CreateGraphAndTest Graph1.txt AdjacencyQueries.txt

Dijkstra’s Algorithm Implementation 1
Implement Dijkstra’s Algorithm, using a priority queue (i.e. heap).
Write a program that runs as follows:
./FindPaths <GRAPH_FILE> <STARTING_VERTEX>

This program should use Dijkstra’s Algorithm to find the shortest paths from a given starting vertex to all
vertices in the graph file. The program should output all paths in the form:
Destination: Start, V1, V2, … , Destination, Total cost: X
You should print out the paths to every destination.
For example if you run the program having as input Graph2.txt (provided) starting from vertex 1, i.e.
./FindPaths Graph2.txt 1

Then the output should be
1: 1, Cost: 0.0.
2: 1, 2, Cost: 2.0.
3: 1, 4, 3, Cost: 3.0.
4: 1, Cost: 1.0.
5: 1, 4, 5, Cost: 3.0.
6: 1, 4, 7, 6, Cost: 6.0.
7: 1, 4, 7, Cost: 5.0.


