/**
* Solution to the interview problem 
* Developed by Olexiy Prokhvatylo for Analyze Re
*/

#include <iostream>
#include <iomanip>

#define NUM_VALUES 100			// Expected number of values.

using namespace std;

/**
 * Prints a double with a minimum precision of 1 
 * and a maximum of 10 decimal points.
 *
 * @param val double to print.
 */
void printVal(double val) {
	// Backup current cout precision, restore it later.
	auto precisionBackup = cout.precision();
	
	// Set precision to 10 decimal places. 
	// Using Log10 + 1 to find length of integer part of a double.
	cout << setprecision(trunc(log10(val)) + 11);
	
	// If value is an integer, append .0
	if (trunc(val) == val)
		cout << val << ".0" << endl;
	
	else
		cout << val << endl;
	
	cout << setprecision(precisionBackup);
}

int main(int argc, char *argv[]) {
	// Show error if not given enough arguments
	if (argc < 3) {
		cerr << "Not enough arguments.\n Usage: ./compute [threshold] [limit]";
		return -3;
	}
	
	double treshold = strtod(argv[1], NULL);
	double limit = strtod(argv[2], NULL);
	double sum = 0;
	double values [NUM_VALUES];
	
	// Load values into array
	for (int i=0; i<NUM_VALUES; i++)
		cin >> values[i]; 
	
	cout << endl;
	
	// Process values inside the array
	for (int i=0; i<NUM_VALUES; i++) {
		// Calculate value after threshold rule
		if (values[i] > treshold) 
			values[i] -= treshold;
		
		else values[i] = 0;
		
		// Calculate value after limit rule
		if (sum + values[i] > limit)
			values[i] = limit;
		
		limit -= values[i];
		sum += values[i];
		
		printVal(values[i]);
	}
	
	printVal(sum);
}