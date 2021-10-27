#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// ****************************
// This code is provided as an *optional* framework to use to 
// write your multi-threaded search code for Assignment 10. 
// 
// Feel free to change anything you want to in this. 
// ****************************


// ===================================================
// Global Variables
// ===================================================

#define MAX_NUM_RESULTS 100 
int num_data_points;
int section_size;

// Array of numbers to search
int* data; 

// Number to be found
int target;

// Array of indices of target number 
int results[MAX_NUM_RESULTS]; 
// Number of results we have so far
int num_results = 0; 


// Used for synchronization. 
// I encourage you to rename this something more meaningful. 
pthread_mutex_t lock;
sem_t semaphore;

// All the threads (an array)
pthread_t* threads; 

// ===================================================
// Functions
// ===================================================

// The function that each thread will run 
// to look for the target value in the array. 
// The argument provided is a pointer to the array
// where this thread should start looking for the target. 
// (This can be either the index OR the address. Your choice.)
// Each thread will look at a max of section_size elements. 
void* DoSearch(void* start_address) {


	return NULL;
}

// Creates all the threads and starts them running. 
// Makes sure the thread IDs are stored in the global threads array. 
void MakeThreads(int num_threads) {


}

// Opens the file called filename. 
// Reads line by line, adding each number to the 
// global data array. 
void ReadFile(char* filename) {


}

// Prints out the results, stored in the 
// global "results" array. 
void PrintResults() {


}


int main(int num_args, char* args[]) {
	// START HERE
	// Read in the arguments and populate global variables. 

	// Create the threads

	// Read the file

	// Wait for threads to finish doing their job

	// Print out the results

	// Clean up everything! 
	// Free everything you malloc'd. 
	// Don't forget to destroy the semaphore and mutex, which 
	// get malloc'd when you create them. 


}