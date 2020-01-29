/*Bryan Yam
20828243
September 25, 2019
SYDE 121
A. Chung
CPH 1346
Lab 02, 02*/	
/*The purpose of this program is to calculate the time, distance, and interval distance of a ball falling from the sky to the ground in 1 sec and 0.1 sec intervals*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	double time = 0;
	double distance; 
	double int_distance;
	const double GRAVITY = 9.80665;
	const double GROUND = 15000;
	
	cout.setf(ios::fixed); /*sets the decimal precision to 3 decimal points; always shows decimal*/
	cout.setf(ios::showpoint);
	cout.precision(3);
	
	cout << "\tTime(in secs) \t" /*different headers*/
	"Distance during interval (in m) \t"
	"Total distance (in m) \n";
	
	while (distance < 14832.558) { /*finds all values of distance in respect to time when distance is less than 14832.558 
	(last integer second interval before distance is greater than 15000)*/
		time += 1;
		
		int_distance = (0.5)*GRAVITY*pow(time,2) - (0.5)*GRAVITY*pow((time - 1),2); /*equation for interval distance*/
		
		distance = (0.5)*GRAVITY*pow(time,2); /* equation for the total distance*/
		
		cout << "\t" << time << "\t \t" /*outputs the values of time, interval distance, and total distance*/
		<< int_distance << "\t \t \t \t \t" 
		<< distance << "\n";	/*continues loop on next line to creat chart*/
	}
	while (14832.558 <= distance && distance <= GROUND)  { /* continues loop at an invertal of 0.1 seconds*/
		
		time += 0.1;
				
		int_distance = (0.5)*GRAVITY*pow(time,2) - (0.5)*GRAVITY*pow((time - 0.1),2); /*equation for interval distance*/
		
		distance = (0.5)*GRAVITY*pow(time,2); /* equation for the total distance*/
		
		cout << "\t" << time << "\t \t" /*outputs the values of time, interval distance, and total distance*/
		<< int_distance << "\t \t \t \t \t" 
		<< distance << "\n";	/*continues loop on next line to creat chart*/
		}
	} 	


 
