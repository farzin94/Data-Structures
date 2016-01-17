/*************************************************************
   Given: Two lists of integers L1 and L2;
   Output: The largest number that occurs in L1 but does not occur in L2, or "None" if there is no such number. 
**************************************************************/

#include <iostream>

#include "maxheap.h"
#include "bst.h"

using namespace std;

int main (void) 
{

	cout << "301243689 farzina Farzin Ahmed\n";

	//variables to hold input data before inserting into DS
	int input_a = 1;
	int input_b = 1;
	int x;
	bool y;

	//data structures to hold the ints while searching for largest number
	Heap L1;
	bst L2;

	
	//Populating the dsts with values from standard input
	/*-----------------------------------------------------------------*/
	while (input_a != 0 && !cin.eof()) {

		cin >> input_a;

		if (input_a == 0) {
			break;
		}

		L1.insert (input_a, input_a);
	}

	while (!cin.eof()) {

		cin >> input_b;

		if (input_b != 0) 
			L2.insert (input_b);
	}


	//Comparing L1 and L2: 
	/*------------------------------------------------------------------*/

	while ( !L1.empty() ) {

		//x holds the largest value in L1 and 
		//y holds true if x was found in L2 or false if x was not found in L2
		x = L1.extractMax();
		y = L2.search(x);

		//if y is not found in L2, x is the largest value in L1 that is not in L2 
		if (y == false) {
			cout << x << endl;
			return 0;
		}
	}

	//if L1 is empty at the end of the loop, all the values have been extracted and therefore,
	//there are no values in L1 that is greater than L2. 
	if (L1.empty()) {
		cout << "NONE" << endl;
		return 1;
	}

	return 0;
}
