/*Bryan Yam
20828243
September 25, 2019
SYDE 121
A. Chung
CPH 1346
Lab 02, 01*/	
/*The purpose of this program is to find all prime numbers less than or equal to n, state any palindromic primes, and any values where the sum of digits in odd*/

#include <iostream>
#include <bits/stdc++.h> 

/*The program will function for all x values between 0 < x < approx. 500000*/
/*I used small primes numbers such as 7,11,23 to test the sum of digits and palindromic function of the program*/

using namespace std;
    
int main() {
	
	double input = 0; /*Declaring global variables*/
	bool correct;
	int check;
	int test;
    
	while (!correct) { 
	
	/*performs loop while correct is false*/
		
		cout << "Enter an integer greater than 1. \n";
		
		cin >> input;
		
		if (floor(input) != input || cin.fail() || input <= 1) { 
		
		/*Restrictions to obtain only integers > 1*/
			
		   cin.clear(); /* clears cin and restarts loop*/
		   while (cin.get() != '\n'); /* prevents an infinite loop by skipping to the next line*/
		   correct = false;
   		   
        } else {
        	
  			 cin.ignore();
  			 correct = true; /* exits loop*/
  			 
   			 }
    }	
    
    int int_input = floor(input);
    int list_of_primes[int_input - 1] = {};
    int a = 0; 
    
    for (; int_input > 1; int_input --) {
    	
	    int check = pow(int_input, 0.5); /*takes sqaure root of value*/
	    int sol = 0;
    	
   	    for (; check > 1; check --) { 
		   /*takes increments of check to check all values up to 1*/
   	   		
   	   		if(int_input % check == 0) { 
		  /* remainder 0 means it is a divisor, adds to solution so it is not considered a prime*/
   				sol ++;
   			}
   		}
		
		if (sol == 0) {	 /*if solutions is 0 therefore no divisors other than itself and 1*/
				list_of_primes[a] = int_input; /*adds number to array*/
				a++;	/*continues for next value*/
			}		
    } 
 
   for (int b=0; b < a; b++) { 
   	    
   	    int sum = 0; /*resets sum value for sum of digits check*/ 
   	    
   	    test = list_of_primes[b]; /*sets test value to the next term within array*/
   	    
   	    
   	    cout << list_of_primes[b] << "\n"; /*outputs all values within array*/
   	   	
   	   	if(list_of_primes[b] <= 10000) { 
	  
	  	/*check for palindromic primes*/
   	   	
   	   	int power = log10 (list_of_primes[b]); /*takes log of the number*/
   	   	int num1 = 0;
   	   	int val = list_of_primes[b];
   	   	
   	   	for(int i; power > 0; i++) { 
			  /* when the log of the number is greater than 0 ... */
   	   		
   	   		int test2 = val % 10; /*modulus of value*/
   	   		test2 = test2 * pow(10,power); /*takes value times 10^log value */
   	   		num1 = num1 + test2; /*increments the values created by log tests*/
	  		power --; /*increments for all values of power before 0*/
	  		
	  		val = val / 10; /*divide val until it's less than 10*/
	  		
	  		if(val < 10) {
	  			
				  test2 = val * pow(10,power); 
				  num1 = num1 + test2; /*takes previous values and determines number backwards*/
				  
			  }
	    }
   	   	
	   	if(list_of_primes[b] == num1) /*if numbers are the same*/
			cout << "This is a palindromic prime. \n";
		
	  }
   	    if(list_of_primes[b] <= 100000 && list_of_primes[b] >= 10) { 
		   /*check for sum is odd*/
 		
		    test = list_of_primes[b];
		  
		    while (test != 0) {
        	sum = sum + test % 10; /*takes remainder and adds to sum*/
        	test = test / 10; /* divide by 10 and repeat remainder equation*/
    		}		
    if (sum % 2 != 0) /*if the sum is even, remiander will be 0, therefore !0*/
	cout << "Sum is odd \n";
        }
    }
return 0; 
}
