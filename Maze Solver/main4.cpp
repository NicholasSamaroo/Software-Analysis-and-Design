#include <iostream>
#include "MazeSolver.h"

int main() {

 MazeSolver solver("inputD.txt");

 if(solver.mazeIsReady())
 {
 	solver.solveMaze();

 	solver.printSolution();
 }

 return 0;
 
}
