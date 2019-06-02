#include <iostream>
#include "CreateGraphAndTest.h"

using namespace std;


int main(int argc, const char * argv[])
{
	
    if (argc != 3) 
	{
        std::cout << "Usage: " << argv[0] << " <filename>" << " <starting vertex #>" << std::endl;
        return 1;
    }
    
	string nodes = argv[1];
	string data_file = argv[2];

	Graph graphObject(nodes);
	graphObject.searchData(data_file);

	return 0;
}
