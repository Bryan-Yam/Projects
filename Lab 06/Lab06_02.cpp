/*Bryan Yam
20828243
November 12, 2019
SYDE 121
A. Chung
CPH 1346
Lab 06, 02*/	
/*The purpose of this program is to check whether a main string contains a substring using recursion.*/
/*I used different input values to test that the program caught any substrings within the main string*/
#include <iostream>

using namespace std;

bool check(string main, string sub_main);
/*checks if substring matches any part of the main string
inputs the main and sub strings
outputs true or false depending on whether string contains substring*/
int main() 
{	
	string main;
	string sub_main;
	
	cout << "Enter main string. \n";
	getline(cin, main);
	
	do //asks for substring until valid response is entered
	{
		cout << "Enter string to look for. String cannot be larger than main string.\n";
		getline(cin, sub_main);
	} while (sub_main.empty() || main.length() < sub_main.length()); //makes sure substring is not empty and that substring is less than string in length
	if (check(main, sub_main))
	   cout << "It's in there!";
	else 
	   cout << "It's not there.";   
	return 0;
}

bool check(string main, string sub_main)
{
	bool test = true; //assume substring is contained within string
	
	if (main.length() == sub_main.length()) //base case, if lengths are the same strings must be the same for main string to contain sub string
	return main == sub_main;
	else //recursive case
	{
		for (int i = 0; i < sub_main.length(); i++) //checks every position in string for matches in substring
		{
			if (main[i] != sub_main[i])
   			   test = false; //substring is not in this part of string
		}
		if (test) //substring matches first part of string
		   return true;
		else { //erase first letter and repeat recursively
			main.erase(0 , 1);
			return check(main, sub_main);
		}
		
	}
}
