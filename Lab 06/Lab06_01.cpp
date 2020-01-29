/*Bryan Yam
20828243
November 12, 2019
SYDE 121
A. Chung
CPH 1346
Lab 06, 01*/	
/*The purpose of this program is to create a diamond using recursion.*/
/*I used different input values to test that the program outputted the diamond with a proper size and spacing*/
#include <iostream>

using namespace std;

void print_dia(int input, int max);
/* prints top half of diamond
inputs the input as the starting value and max size
outputs the top half of the diamond*/
void print_rev(int input, int max);
/* prints bottom half of diamond
inputs the input as the starting value and the max size
outputs the bottom half of the diamond*/
void print_space(int input);
/* prints spaces for each row according to the row number
inputs the size of the diamond
outputs spaces*/
void rev_space(int input, int max);
/* prints spaces for each row according to the row number
inputs the size of the diamond
outputs spaces*/
void print_star(int input);
/* prints stars for each row according to the row number
inputs the size of the diamond
outputs stars*/

int main()
{
	bool correct = false;
	int input = 0;
	do //receives input from user
	{
		cout << "Please enter a value greater than or equal to 0. \n";
		cin >> input;
		if (input < 0) //confirms if input is valid, asks again if not
		   correct = false;
		else 
	 	   correct = true;   
	} while(!correct);
	print_dia(input, input);
	print_rev(input, input);
	return 0;
}

void print_dia(int input, int max) //prints the top half of the diamond layer by layer
{
	if (input == 0) //base case
	   return;
    print_space(input); //recursive case
    print_star(max - input + 1);
    cout << endl;
    print_dia(input - 1, max); //recursively moves on to the next line
 
}

void print_space(int input) //prints a space according to the row (for top half)
{
	if (input == 0) //base case
	   return;
	cout << " "; //recursive case
	print_space(input - 1);
}

void print_star(int input) //prints a star according to the row
{
	if (input == 0) //base case
	return;
	cout << "* "; //recursive case
	print_star(input - 1);
}

void print_rev(int input, int max) //prints the bottom of the diamond
{
	if (input == 0) //base case
	   return;
	rev_space(input - 2, max); //recursive case
	print_star(input - 1);
	cout << endl;
	print_rev(input - 1, max); //recursively moves on to the next line
}

void rev_space(int input, int max) //prints a space according to the row (for bottom half)
{
	if (input == max) //base case
	   return;
	cout << " "; //recursive case
	rev_space(input + 1, max);
}
