	#include <iostream>
	
/* Steps for program */
/* 1. Input initial weight */
/* 2. Divide initial by 150, find remainder for 150*/
/* Repeat step 2 for 50, 30, 15 ,1 until reminader is 0*/
/* Output the values associated with each weight*/

/*I used the values 10, 170, and 34567 to test the functionality of the program*/
/*The range of values for this program is all integers greater than 0*/
/*Output for 1048 = 6,2,1,1,3 (for 150, 50, 30, 15, 1 respectively)*/

	using namespace std;
	
	int main() {
	
	int weight_input, first_remainder, second_remainder, third_remainder, fourth_remainder;  
	int first_quotient, second_quotient, third_quotient, fourth_quotient, fifth_quotient;   
	
	cout << "Please input a weight in pounds. \n";
	
	cin >> weight_input;
	
	first_quotient = weight_input / 150;
	first_remainder = weight_input % 150;
	second_quotient = first_remainder / 50;
	second_remainder = first_remainder % 50;
	third_quotient = second_remainder / 30;
	third_remainder = second_remainder % 30;
	fourth_quotient = third_remainder / 15;
	fourth_remainder = third_remainder % 15;

	cout << "# of 150 pounds = " << first_quotient << "\n";
	cout << "# of 50 pounds = " << second_quotient << "\n";
	cout << "# of 30 pounds = " << third_quotient << "\n";
	cout << "# of 15 pounds = " << fourth_quotient << "\n";
	cout << "# of 1 pounds = " << fourth_remainder << endl;
	
	return 0;
	}
	
