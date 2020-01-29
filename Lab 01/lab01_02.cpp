#include <iostream>
#include <cmath>

/* I used the test values given to test the program logic*/
/*This program will function for any x values greater or equal to 2000*/
/*Values for 2018, 2025, 2050, 2100 are approx. 8.6, 9.9, 16.3, 44.3 in billions respectively*/

using namespace std;

int main() {
	
	int input_year;
	double population;
	
	cout << "Please input a year of 2000 or more recent to find the estimated population at the time \n";
	
	cin >> input_year;
	
	population = 6*pow(M_E,0.02*(input_year - 2000));
	
	cout << "The estimated population at the year " << input_year << " is " << population << " billion.";
	
	return 0;
}


