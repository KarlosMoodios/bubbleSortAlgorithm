// Bubble sorting algorithm.
// Karl Moody 2019
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

#define SIZE 10 // Define the size of the data file here to avoid having to change all the code loads of times

void printit(void); // Function to print to the screen

int a[SIZE]; // Create integer array to hold the data

main(){

	FILE* f1;					// Create file pointer
	int x, i, j;				// Create variables
	DWORD starttime, endtime;	// Variables to store start and end times
	float totaltime;			// Variable for the total time

	// Open file for reading only
	if (SIZE == 10) 	fopen_s(&f1, "10.dat", "r");
	if (SIZE == 100) 	fopen_s(&f1, "100.dat", "r");
	if (SIZE == 1000) 	fopen_s(&f1, "1000.dat", "r");
	if (SIZE == 10000) 	fopen_s(&f1, "10000.dat", "r");

	// Save file to array
	for (i = 0; i < SIZE; i++) 
	{
		fscanf_s(f1, "%d\n", &x);
		a[i] = x; 
	} 
	// Close the file
	fclose(f1);

	// Print raw data
	printit();

	cout << "Press any key to begin sorting...\n";
	_getch();

	starttime = GetTickCount();/* Get the start time from just
	before the sorting of the data takes place. */
	
	// Bubble sort
	for (i = 0; i < SIZE - 1; i++)
	{

		for (j = 0; j < SIZE - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				int temp = a[j]; // Create a temp slot to store the highest
				a[j] = a[j + 1]; // Swap the lowest number into this array slot
				a[j + 1] = temp; // Save the temp value back into the unsorted array array
			}
		cout << "I = " << i << endl;  // Print key to screen to show which number everything is shifted around
		printit();
	}
	// Get finish time
	endtime = GetTickCount();

	// Calculate time
	totaltime = ((float)endtime - (float)starttime) / 1000.0; // calc total time in secs
	cout << "Total time taken to sort the data = " << totaltime << " sec\n";

	_getch();

}// End of main


// Print function to display the array in the console
void printit(void) 
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Array slot[" << i+1 << "]=" << a[i] << endl;
	}
	cout << endl;
}
