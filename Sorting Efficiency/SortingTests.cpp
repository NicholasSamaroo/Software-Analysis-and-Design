#include "SortingTests.hpp" 
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
using namespace std::chrono;

/*
   Name: Nicholas Samaroo
   File name: SortingTest.cpp
   CSCI 235, Fall 2018, Project 5
   This is the implementation file for SortingTests.h which measures
   the average run time of three sorting algorithms agaisnt various
   types of populated arrays. Run time is measured using the library
   chrono.
*/
void selectionSort(int a[], size_t size)
{
	int holder;
	
	for(int i = 0; i < (size - 1); i++)
	{
		int position = i; // This is the divider between the sorted and unsorted array
		
		for(int j = i + 1; j < size ; j++)
		{
			if(a[j] < a[position]) //This is what actually checks the entire array for the lowest value and sets the index to the position of that value
			{
				position = j;
			}
		} // Closing braces here ensures that it checks the end untill it reaches this bottom if
	
		if(position != i)
		{
			holder = a[i];
			a[i] = a[position];
			a[position] = holder;
		}
	}	
}

void insertionSort(int a[], size_t size) 
{
		for (int i = 1; i < size; i++) 
		{
			int j = i;

            while (j > 0 && a[j - 1] > a[j]) 
			{

                  int temp = a[j];
				  a[j] = a[j - 1];
				  a[j - 1] = temp;
				  j--;

            }

      }

}
    

void merge(int a[], int low, int mid, int high) 
{
	int *temp = new int[high - low + 1];
	int i = low;
	int k = 0;
	int j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
  


void mergeSort(int a[], int from, int to)   
{
	if (from < to) 
    { 
        int m = from + (to - from) / 2; 
  
        // Sort first and second halves 
        mergeSort(a, from, m); 
        mergeSort(a, m + 1, to); 
  		merge(a, from, m, to); 
    } 
} 

void generateRandomArray(int values[], size_t size) //Random array
{
	int stepper = 0;
	
	srand(static_cast<unsigned>(time(0)));

	while(stepper < size)
	{
		values[stepper] = rand() % size;
		stepper++;
	}

}

void generateAscendingArray(int values[], size_t size) //Ascending array
{
	for(int i = 0; i < size; i++)
	{
		values[i] = i;
	}
  	
}

void generateDescendingArray(int values[], size_t size) //Descending array
{
	for(int k = size - 1; k >= 0; k--)
	{
		values[k] = k;
	}
}

void generateLastTenRandomArray(int values[], size_t size) //Last ten random array
{
	int i = 0;
	int last_ten = size - 10;
	
	while(i < last_ten)
	{
		values[i] = i;
		i++;
	}
	
	srand(static_cast<unsigned>(time(0)));

	while(last_ten < size)
	{
		values[last_ten] = rand() % size;
		last_ten++;
	}
}
void generateFewRandomArray(int values[], size_t size) //Few random array
{
	int counter = 0;
	
	srand(static_cast<unsigned>(time(0)));

	while(counter < size)
	{
		values[counter] = rand() % (size/10);
		counter++;
	}
}

double sortTest(void (*sortingFunction)(int a[], size_t size), int values[], size_t size) //Testing function for selection and insertion sort
{
	double runtime_sum = 0;
	
	for(int j = 0; j < 10; j++)
	{
		int *copy = new int[size];
		
		for(int i = 0; i < size;i++)
		{
			copy[i] = values[i];
		}
		
		auto start_time = high_resolution_clock().now();
		
		sortingFunction(copy,size);
		
		auto end_time = high_resolution_clock().now();
		
		duration<float, micro> runt_time = duration_cast<microseconds>(end_time - start_time);
		runtime_sum += runt_time.count();
	}
	double actual_runtime = runtime_sum / 10;
	return actual_runtime;
}

double mergeSortTest(int values[], size_t size) //Testing function for merge sort
{
	double runtime_sum2 = 0;
	
	for(int j = 0; j < 10; j++)
	{
		int *copy_m = new int[size];
		
		for(int i = 0;i < size;i++)
		{
			copy_m[i] = values[i];
		}
		auto start_time = high_resolution_clock().now();
		
		mergeSort(copy_m,0,size);
		
		auto end_time = high_resolution_clock().now();
		
		duration<float, micro> runt_time = duration_cast<microseconds>(end_time - start_time);
		runtime_sum2 += runt_time.count();
		
	}
	double actual_runtime2 = runtime_sum2 / 10;
	return actual_runtime2;
}




