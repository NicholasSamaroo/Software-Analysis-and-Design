#include "SortingTests.hpp"
#include <iostream>

using namespace std;

int main() {
    
    const size_t SMALL_ARRAY_SIZE = 100;
    const size_t MEDIUM_ARRAY_SIZE = 1000;
    const size_t LARGE_ARRAY_SIZE = 10000;
    //const size_t HUGE_ARRAY_SIZE = 100000;
    
    int values[SMALL_ARRAY_SIZE];
    
    //*** FIRST TEST RANDOM VALUES ON SMALL_ARRAY_SIZE ***//
    
    generateRandomArray(values, SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a random array of size " << SMALL_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values, SMALL_ARRAY_SIZE) << " microseconds" << endl;
   
    generateRandomArray(values, SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a random array of size " << SMALL_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values, SMALL_ARRAY_SIZE) << " microseconds" << endl;
    
    generateRandomArray(values, SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a random array of size " << SMALL_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values, SMALL_ARRAY_SIZE)<< " microseconds\n\n";
    
    
    //*** SECOND TEST SORTED VALUES ON SMALL_ARRAY_SIZE ***//
    
    generateAscendingArray(values, SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for an ascending array of size " << SMALL_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values, SMALL_ARRAY_SIZE) << " microseconds" << endl;
    
    generateAscendingArray(values, SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for an ascending array of size " << SMALL_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values, SMALL_ARRAY_SIZE) << " microseconds" << endl;
    
    generateAscendingArray(values, SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for an ascending array of size " << SMALL_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values, SMALL_ARRAY_SIZE) << " microseconds\n\n";
    
    //*** THIRD ARRAY TYPE ON SMALL_ARRAY_SIZE ***//
    
    generateDescendingArray(values,SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a descending array of size " << SMALL_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values, SMALL_ARRAY_SIZE) << " microseconds" << endl;
    
    generateDescendingArray(values,SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a descending array of size " << SMALL_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values, SMALL_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateDescendingArray(values,SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a descending array of size " << SMALL_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values, SMALL_ARRAY_SIZE) << " microseconds\n\n";
    
    //*** FOURTH ARRAY TYPE ON SMALL_ARRAY_SIZE ***//
    
    generateLastTenRandomArray(values,SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a last ten random array of size " << SMALL_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values, SMALL_ARRAY_SIZE) << " microseconds" << endl;
    
    generateLastTenRandomArray(values,SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a last ten random array of size " << SMALL_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values, SMALL_ARRAY_SIZE)<< " microseconds" << endl;
    
	generateLastTenRandomArray(values,SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a last ten random array of size " << SMALL_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values, SMALL_ARRAY_SIZE) << " microseconds\n\n";
    
    //*** FIFTH ARRAY TYPE ON SMALL_ARRAY_SIZE ***//
    
    generateFewRandomArray(values, SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a few random array of size " << SMALL_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values, SMALL_ARRAY_SIZE) << " microseconds" << endl;
    
    generateFewRandomArray(values, SMALL_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a few random array of size " << SMALL_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values, SMALL_ARRAY_SIZE)<< " microseconds" << endl;
    
	generateFewRandomArray(values, SMALL_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a few random array of size " << SMALL_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values, SMALL_ARRAY_SIZE) << " microseconds\n\n";
    
    int values2[MEDIUM_ARRAY_SIZE];
    
    //*** FIRST ARRAY TYPE ON ARRAY OF SIZE MEDIUM_ARRAY_SIZE ***///
    
	generateRandomArray(values2,MEDIUM_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a random array of size " << MEDIUM_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values2, MEDIUM_ARRAY_SIZE) << " microseconds" << endl;
	
    generateRandomArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a random array of size " << MEDIUM_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values2, MEDIUM_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateRandomArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a random array of size " << MEDIUM_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values2, MEDIUM_ARRAY_SIZE) << " microseconds\n\n";
    
    //*** SECOND ARRAY TYPE ON ARRAY OF SIZE MEDIUM_SIZE ***///
    generateAscendingArray(values2,MEDIUM_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a ascending array of size " << MEDIUM_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values2, MEDIUM_ARRAY_SIZE) << " microseconds" << endl;
	
    generateAscendingArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a ascending array of size " << MEDIUM_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values2, MEDIUM_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateAscendingArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a ascending array of size " << MEDIUM_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values2, MEDIUM_ARRAY_SIZE) << " microseconds\n\n";
    
    
    //*** THIRD ARRAY TYPE ON ARRAY SIZE MEDIUM_SIZE ***///
    
    generateDescendingArray(values2,MEDIUM_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a descending array of size " << MEDIUM_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values2, MEDIUM_ARRAY_SIZE) << " microseconds" << endl;
	
    generateDescendingArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a descending array of size " << MEDIUM_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values2, MEDIUM_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateDescendingArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a descending array of size " << MEDIUM_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values2, MEDIUM_ARRAY_SIZE) << " microseconds\n\n";
    
    
    
    //*** FOURTH ARRAY TYPE ON ARRAY SIZE MEDIUM_SIZE ***///
    
    generateLastTenRandomArray(values2,MEDIUM_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a last ten random array of size " << MEDIUM_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values2, MEDIUM_ARRAY_SIZE) << " microseconds" << endl;
	
    generateLastTenRandomArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a last ten random array of size " << MEDIUM_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values2, MEDIUM_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateLastTenRandomArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a last ten random array of size " << MEDIUM_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values2, MEDIUM_ARRAY_SIZE) << " microseconds\n\n";
    
    
    //*** FIFTH ARRAY TYPE ON ARRAY SIZE MEDIUM_SIZE ***///
    
    generateFewRandomArray(values2,MEDIUM_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a few random array of size " << MEDIUM_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values2, MEDIUM_ARRAY_SIZE) << " microseconds" << endl;
	
    generateFewRandomArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a few random array of size " << MEDIUM_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values2, MEDIUM_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateFewRandomArray(values2,MEDIUM_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a few random array of size " << MEDIUM_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values2, MEDIUM_ARRAY_SIZE) << " microseconds\n\n";
    
    int values3[LARGE_ARRAY_SIZE];
    
     //*** FIRST ARRAY TYPE ON ARRAY OF SIZE MEDIUM_ARRAY_SIZE ***///
    
	generateRandomArray(values3,LARGE_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a random array of size " << LARGE_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values3, LARGE_ARRAY_SIZE) << " microseconds" << endl;
	
    generateRandomArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a random array of size " << LARGE_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values3, LARGE_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateRandomArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a random array of size " << LARGE_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values3, LARGE_ARRAY_SIZE) << " microseconds\n\n";
    
    //*** SECOND ARRAY TYPE ON ARRAY OF SIZE MEDIUM_SIZE ***///
    generateAscendingArray(values3,LARGE_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a ascending array of size " << LARGE_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values3, LARGE_ARRAY_SIZE) << " microseconds" << endl;
	
    generateAscendingArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a ascending array of size " << LARGE_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values3, LARGE_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateAscendingArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a ascending array of size " << LARGE_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values3, LARGE_ARRAY_SIZE) << " microseconds\n\n";
    
    
    //*** THIRD ARRAY TYPE ON ARRAY SIZE MEDIUM_SIZE ***///
    
    generateDescendingArray(values3,LARGE_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a descending array of size " << LARGE_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values3, LARGE_ARRAY_SIZE) << " microseconds" << endl;
	
    generateDescendingArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a descending array of size " << LARGE_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values3, LARGE_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateDescendingArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a descending array of size " << LARGE_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values3, LARGE_ARRAY_SIZE) << " microseconds\n\n";
    
    
    
    //*** FOURTH ARRAY TYPE ON ARRAY SIZE MEDIUM_SIZE ***///
    
    generateLastTenRandomArray(values3,LARGE_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a last ten random array of size " << LARGE_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values3, LARGE_ARRAY_SIZE) << " microseconds" << endl;
	
    generateLastTenRandomArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a last ten random array of size " << LARGE_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values3, LARGE_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateLastTenRandomArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a last ten random array of size " << LARGE_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values3, LARGE_ARRAY_SIZE) << " microseconds\n\n";
    
    
    //*** FIFTH ARRAY TYPE ON ARRAY SIZE MEDIUM_SIZE ***///
    
    generateFewRandomArray(values3,LARGE_ARRAY_SIZE);
	cout << "Elapsed time over 10 runs for a few random array of size " << LARGE_ARRAY_SIZE << " for selection sort is: " << sortTest(&selectionSort, values3, LARGE_ARRAY_SIZE) << " microseconds" << endl;
	
    generateFewRandomArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a few random array of size " << LARGE_ARRAY_SIZE << " for insertion sort is: " << sortTest(&insertionSort, values3, LARGE_ARRAY_SIZE)<< " microseconds" << endl;
    
    generateFewRandomArray(values3,LARGE_ARRAY_SIZE);
    cout << "Elapsed time over 10 runs for a few random array of size " << LARGE_ARRAY_SIZE << " for merge sort is: " << mergeSortTest(values3, LARGE_ARRAY_SIZE) << " microseconds\n\n";
    
    
    return 0;
}
