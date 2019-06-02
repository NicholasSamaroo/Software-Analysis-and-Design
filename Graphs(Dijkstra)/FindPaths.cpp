//Nicholas Samaroo

/* This file use's Dijkstra's algorithm to find the shortest path
	from a start node. I implemented it using a priority queue and 
	I differentiated between the different vertexs and weights by
	using pair which creates a pair of two items.
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include <fstream>
#include <sstream>


#define linked_pair pair<int,int>

using namespace std;

//This struct compares two pairs to see if the weight of one is greater than the other
struct pairs
	{
    	int operator() (const pair<int,int>&p1,const pair<int,int>&p2)
    	{
    		
        	return p1.second > p2.second; 
    	}
	};



void startDijkstra(const string file_name, const int source)
{
	//Create a priority queue of linked pairs
	//The comparator for the queue is in the struct pairs
	//which see's if the weight of tghe first pair is
	//greater than the weight of the second pair
	priority_queue<linked_pair,vector<linked_pair>,pairs> pq;
    
    //The following variable definitions are needed to set up Dijkstra's algorithm
    int num_nodes;
    int u;
    int v;
    int edge_iterator = 0;
    int edges;
    int start = source;
    float weight;
    
    ifstream input_data(file_name);
    string input_line;
    input_data >> num_nodes;
    
    //This vector is going to hold the vertexes
    //and their respective weights
	vector<linked_pair> links[num_nodes + 1];
    
    if(file_name == "Graph2.txt")
    {
    	edges = 12;
    }
    else if(file_name == "Graph1.txt")
    {
    	edges = 8;
    }
    else
    {
    	edges = 12;
    }
    
    while(getline(input_data,input_line) && edge_iterator < edges)
    {
    	stringstream linestream(input_line);
        linestream >> u;
        
        while(linestream >> v >> weight)
        {
        	links[u].push_back(linked_pair(v,weight));
        	links[v].push_back(linked_pair(u,weight));
        }
        
		edge_iterator++;
    }
	
    int distance[num_nodes + 1];
    
    /* Intializing every distance as 1000 represents intializing it to INFINITY
		We do this because intially we don't know how far a certain node is from the 
		source node */
	for(int i = 1;i <= num_nodes;i++)
	{
		distance[i] = 1000;
	}
        
	distance[start] = 0; //The distance from the source node is 0 because it costs 0 to get where we already are
    
	pq.push(linked_pair(start,distance[start])); //Push this into the priority queue
    
    while(!pq.empty())
    {
        u = pq.top().first;
        pq.pop();
        
		int size = links[u].size();
        
		for(int j = 0;j < size;j++)
        {
            v = links[u][j].first;
            weight = links[u][j].second;
            
            
			if(distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                pq.push(linked_pair(v,distance[v]));
            }
        }
    }
    
    cout << "The starting node is " << source << endl;
    cout << "The following shows the shortest paths from the source node " << source << endl << endl;
    
    for(int i = 1; i <= num_nodes; i++)
    {
    	cout << i << ": Cost: " << distance[i];
    	cout << endl;
    }
}
    

int main(int argc, const char * argv[])
{
    if (argc != 3) 
	{
        std::cout << "Usage: " << argv[0] << " <filename>" << " <starting vertex #>" << std::endl;
        return 1;
    }
    
    string file_name = argv[1];
    int source = (atoi(argv[2]));
    
    startDijkstra(file_name,source);
    
	return 0;
}
    
