/*Bryan Yam
20828243
October 21, 2019
SYDE 121
A. Chung
CPH 1346
Lab 04, 02*/	
/*The purpose of this program is allow users to input a maximum of 20 values in order to find the min, max, mean, and standard deviation.*/

/*I used cout to test that the array was storing the strings as doubles, and used an online calculator to check if my program outputted the same values*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>

using namespace std;

void input(double data[20], int& data_size);
/*takes user input and places it in the array*/
/*inputs are the numbers from the user*/
/*no outputs*/
void output(double data[20], int& data_size);
/*displays the different averages and values for the array*/
/*takes inputs from array*/
/*outputs the different values*/
void change(double data[20], int& data_size);
/* allows the user to change any previous values*/
/*takes inputs from array*/
/*no outputs*/

int main() /*Runs the different functions using the main array and size*/
{
	double data[20] = {};
	int num_data = 0; /*keeps track of the number of data points*/
	input(data, num_data);
	output(data, num_data);
	change(data, num_data);
	output(data, num_data);
	return 0;
}

void input(double data[20], int& data_size)
{
	bool correct = false;
	string input = "";
	cout << "Please enter 20 values. Enter done or d to continue. \n";
	cin >> input;
	while (!correct) /*keeps saving values until array is filled*/
	{
		if (data_size < 20) /* converts string into double*/
		{
			data[data_size] = atof(input.c_str());
		}
		data_size++;
		cin >> input;
		if (input == "done" || input == "d") /*exits loops when user is done*/
		correct = true;
	}	
}

void change(double data[20], int& data_size)
{
	bool correct = false;
	string pos = "";
	string num = "";
	int num2 = 0;
	do
	{
		cout << "Please enter which location you would like to change between 1 - " << (data_size) << ". Enter q or quit to continue. \n";
		cin >> pos;
		if (pos != "quit" && pos != "q")
		{
			stringstream val(pos); /*changes string to int*/
			val >> num2;
			if (num2 >= 0 && num2 < data_size) /* checks if point entered is within array*/
			{ 
			   cout << "What would you like to change it to? \n";
			   cin >> num;
			   data[num2] = atof(num.c_str()); /*changes the string to a double*/
		    } else {
		    	cout << "Location does not exist. \n";
		    	
			}	   
		}	
		if (pos == "quit" || pos == "q")
		correct = true;
	} while (!correct); /*continues loop until user is complete*/
}

void output(double data[20], int& data_size) {
	double min = data[0];
	double max = data[0];
	double mean = 0;
	double pop_st = 0;
	double top_st = 0;
	for (int i = 0; i < data_size; i++) /*cycles through all array slots to find lowest number*/
	{
		if (data[i] < min)
		min = data[i];
	}
	for (int j = 0; j < data_size; j++) /*cycles through all array slots to find greastest number*/
	{
		if (data[j] > max)
		max = data[j];
	}
	for (int k = 0; k < data_size; k++) /*adds all numbers in array*/
	{
		mean += data[k];
	}
	mean = mean / data_size; /*divides added number in array by the number of values*/
	for (int l = 0; l < data_size; l++) /*calculated population standard deviation*/
	{
	top_st += pow((data[l] - mean), 2);
	}
	pop_st = sqrt(top_st / (data_size - 1));
	
	cout << "Min = " << min << endl; /*outputs all values*/
	cout << "Max = " << max << endl;
	cout << "Mean = " << mean << endl;
	cout << "Population Standard Deviation = " << pop_st << endl;
}
