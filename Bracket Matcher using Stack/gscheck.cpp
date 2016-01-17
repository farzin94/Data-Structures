/*Write a program that takes a text file from standard input and checks that all occurences of the grouping symbols 
are correctly matched and nested. If there is any incorrect matching or nesting, the program prints out a message, 
giving the line where the first error was found and the nature of the error. Otherwise it prints a line containing
only the string "No Errors Found".*/

#include <iostream>
#include <stdio.h>
#include <string>

#include "char_stack.h"

using namespace std;

//Post: Prints out the array (returns nothing)
//Parameters: char A[] is the array to be printed and int len is the length of that array
void print (char A[], int len, int error)
{
	int flag = 0;
	int prev_len = 0;

	for (int i=0; i<len; i++)
	{
		//if a tab character is found then raise the flag
		if (A[i] == '\t')
		{
			flag = 1;
		}


		cout << A[i];
		//incrementing prev_len to keep track of the number of characters in the line
		prev_len++;

		//if the error symbol is found then:
		if (i == error)
		{
			cout << endl;

			//if flag is raised, print a tab
			if (flag == 1)
			{
				cout << '\t';
			}

			//print space chars the number of times of the chars in the previous line 
			if (flag == 1)
			{
				for (int j=1; j< prev_len; j++) 
				{
					cout << " ";
				}
			}
			
			else 
			{
				for (int j=0; j< prev_len; j++) 
				{
					cout << " ";
				}	
			}	
			
		}
	}
	cout << endl;
}

//Post: Checks whether all grouping symbols are correctly matched and returns the error if found. 
//Parameters: None (takes in a text file from terminal)
int main (void)
{
	char_stack s; //stack
	int i = 0;
	char o; //holing open symbols
	char c; //holding closed symbols
	int line=0; //line count
	int len=0;
	int prev_len=0;

	char A[250]; //array to hold the lines
	//string symbols;
	//s = cin.peek();

 	//gets each line
	while (cin.peek() != EOF && line <= 1000)  {

		//getline (cin, symbols);
		cin.getline( A, 250);

		//taking the length of line to iterate over 
		len = cin.gcount();
		
		//iterating line for error checking 
		line++;

		//traversing the array holding the line
		for (i = 0; i < len; i++) {
			o = A[i];
			//when open bracket, push into stack
			if (o == '(' || o == '[' || o == '{') {
				s.push (o);
			}

			//pop the bracket from the stack if its matching closed symbol is found
			else if (o == ')' || o == ']' || o == '}') {
				//if stack is empty and a closed bracket is read, then error 
				if (s.empty()) {
					cout << endl << "Error on line " << line << " Too many " << o << endl;
					print (A, len, i);
					return 1; 
				}
				//popping
				c = s.pop();
			
				//if the open and closed brackets don't match, then error 
				if ( ! ( (c=='('&& o==')') || (c=='{' && o=='}') || (c=='[' && o==']') ) ) {
					cout << "Error on Line " << line << ". Read " << o << " expected " << c << endl;
					print (A, len, i);
					return 1;
				}
			}

		
		}

		//prev_len = len;
	}
	//if there are any leftover brackets brackets in the stack after the loop then error
	if (!s.empty()) {
		o = s.pop();
		cout << "Error on line " << line << ": Too many " << o << endl;
		print (A, len, i);
				//cout << symbols << endl;
		return 1;
	}

	//cout << c << endl << endl << endl;
	cout << "No Errors Found" << endl;

	return 0;
}

//I only want to compare with the value I pushed in and not the other values being iterated over


//Store the cin.gcount of the previous line in another var and put that in as a param in my print function
//Then print ' ' * cin.gcount of that previous line before the next line is printed
// find a tab and print spaces 
