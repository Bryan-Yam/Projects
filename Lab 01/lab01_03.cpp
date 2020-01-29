#include <iostream>
#include <cmath>

/*The test values were used to determine the logic of the program*/
/*The program will work for all x integers*/
/*Values for 1-100, 1-3000, and 5-10000 are 5050, 4501500, 50004990 (assuming common difference is 1)*/

using namespace std;

int main() {
	
	int start_val, com_diff, end_val, sum, num_integers;
	
	cout << "Please input a starting value \n";
	
	cin >> start_val;
	
	cout << "Please input the common difference \n";
	
	cin >> com_diff;
	
	cout << "Please input the end value \n";
	
	cin >> end_val;
	
	num_integers = (end_val - start_val) + 1;
	
	sum = (num_integers/2)*(2*start_val + (num_integers - 1)*com_diff);
	
	cout << "The sum of integers from " << start_val << " to " << end_val << " is " << sum << ".";
	
	return 0;
}
