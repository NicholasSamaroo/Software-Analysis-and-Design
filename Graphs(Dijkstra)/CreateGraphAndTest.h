//Nicholas Samaroo

/* 	This program takes in a file called AdjencyQueries
	which is read by my functions to determine whether or not
	certain nodes are connected. The graph is created via an adjency list
	of which I implemented by having an array of pointers which at each
	index create a linked list of structs. */ 

#ifndef CREATE_GRAPH_AND_TEST_H
#define CREATE_GRAPH_AND_TEST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


class Graph
{

public:
	
	//SINGLE PARAMETER CONSTRUCTOR
	//@file_name --> Takes in the Graph file name and calls intialize which begins the process of creating the graph
	Graph(string &file_name)
	{
		initialize(file_name);
	};

	//This function is setting up the adjacency list via an array of pointers
	//Each indexes pointers are intialized to nullptr and then when they start to get
	//filled with structs each respective index is going to form a linked list
	void adjacencyList(int size)
	{
		adjacency_list = new adjacency_node*[size];
		
		for (int i = 0; i < size; i++)
		{
			adjacency_list[i] = nullptr;
		}
	}
	
	/*This function actually adds the nodes into the graph
	  via pointers.
	  @vertex --> Node
	  @weight --> Weight between connected nodes
	  @index --> helper variable for indexing */
	void addEdge(int index, int vertex, double weight)
	{
		adjacency_node *helper = adjacency_list[index];
		
		if (helper == nullptr)
		{
			adjacency_list[index] = new adjacency_node;
			adjacency_list[index]->vertex = vertex;
			adjacency_list[index]->weight = weight;
			adjacency_list[index]->next = nullptr;
		}
		else
		{
			while (helper->next != nullptr)
			{
				helper = helper->next;
			}
			
			helper->next = new adjacency_node;
			helper->next->vertex = vertex;
			helper->next->weight = weight;
			helper->next->next = nullptr;
		}
	}

	void initialize(string &file_name)
	{
		int index = 0;
		int vertex = 0;
		float weight = 0.0;

		ifstream input_data(file_name);
		input_data >> graphSize;
		graphSize++;
		
		adjacencyList(graphSize);

		string input_line;
		
		while (getline(input_data, input_line))
		{
			stringstream linestream(input_line);
			linestream >> index;
				
			while (linestream >> vertex >> weight)
			{
				addEdge(index, vertex, weight);
					
			}
				
		}
	}

	void printGraph()
	{
		for (int i = 1; i < graphSize; i++)
		{
			cout << i << ": ";
			adjacency_node *helper = adjacency_list[i];
			
			while (helper != nullptr)
			{
				cout << helper->vertex << " " << helper->weight << " ";
				helper = helper->next;
			}
			cout << endl;
		}
	}
	
	//This function actually traverses the desired index's linked list to 
	//see if the two nodes are connected or not. n1 represents the first node
	//while n2 represents the second node
	double connected(int n1, int n2)
	{
		bool search_n2 = false;
		adjacency_node *helper = adjacency_list[n1];
		
		if (helper == nullptr)
		{
			return 0.0;
		}
		else
		{
			while (!search_n2)
			{
				if (helper->vertex == n2)
				{
					return helper->weight;
				}
				else if (helper->next != nullptr)
				{
					helper = helper->next;
				}
				else
				{
					return 0.0;
				}
			}
		}
		return 0.0;
	}
	
	//This is the gateway function for seeing if the two nodes are connected
	//The function connected sees if the nodes are connected via traversal of the 
	//desired index's linked list
	void searchData(string &filename)
	{
		int node1{0}, node2{0};

		ifstream input_data(filename);
		string input_line;
		
		while (getline(input_data, input_line))
		{
			stringstream linestream(input_line);
			
			while (linestream >> node1 >> node2)
			{
				float val = connected(node1, node2);
				
				if (val == 0.0)
				{
					cout << node1 << " " << node2 << ":Not connected\n";
				}
				else
				{
					cout << node1 << " " << node2 << ":Connected, weight of edge is " << val << endl;
				}
			}
		}
	}

private:
	
	struct adjacency_node
	{
		int vertex = 0;
		double weight = 0.0;
		adjacency_node * next = nullptr;
	};
	
	int graphSize = 0;
	adjacency_node **adjacency_list;

};

#endif //CREATE_GRAPH_AND_TEST_H


