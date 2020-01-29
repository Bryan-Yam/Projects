/*Bryan Yam
20828243
September 25, 2019
SYDE 121
A. Chung
CPH 1346
Lab 02, 03*/	
/*The purpose of this program is to take the user's birth date and display their horoscope and elemental sign*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double birth_month; /*Assigning variables*/
	double birth_day;
	bool correct;
	bool correct_two;
	double test;
	
	while (!correct) {
		
		cout << "Please enter your birth month. (1-12) \n";
		
		cin >> birth_month;
		
		test = floor(birth_month);	
		
		if (test != birth_month || cin.fail() || 12 < birth_month || birth_month < 1) { /*restrictions for birth year*/
			
			cin.clear(); /*clears cin and skips line to avoid infinite loop*/
			while (cin.get() != '\n');
			correct = false;
			
		} else {
			
			cin.ignore(); /*breaks loop when correct input is inputted*/
			correct = true;
		}
	}	

if (birth_month == 7 || birth_month == 1 || birth_month == 3 || birth_month == 5 || birth_month == 8 || birth_month == 10 || birth_month == 12) { /*all months with 31 days*/
	while (!correct_two) {
		cout << "Please enter your birth day. (1-31) \n";
		cin >> birth_day;
			if (birth_day < 1 || cin.fail() | birth_day > 31 || floor(birth_day) != birth_day) { /*restrictions for days*/
					
				cin.clear();
				while (cin.get() != '\n');
				correct_two = false;
			} else {
				cin.ignore();
				correct_two = true;
			}
		} /*logic statements for all the different signs and horoscopes*/
				if (birth_month == 7 && birth_day > 22 ) {
					cout << "You are a Leo and a Fire Sign. \n"
					<< "People born under the sign of Leo are natural born leaders. \n"
					<< "Fire signs truly uplift the strength of the Sun. \n"
					<< "You are most compatible with Aquarius and Gemini.";
					return 0;
			} else if (birth_month == 7 && birth_day <= 22 ) {
				cout << "You are a Cancer and a Water Sign. \n"
				<< "Cancers are very emotional and sensitive, and care deeply about matters of the family and their home. \n"
				<< "Water signs are highly intuitive and they can be as mysterious as the ocean itself. \n"
				<< "You are most compatible with Capricorn and Taurus.";
				return 0;
			} else if (birth_month == 1 && birth_day < 20 ) {
				cout << "You are a Capricorn and a Earth sign. \n"
				<< "Capricorn is a sign that represents time and responsibility, \n"
				<< "and its representatives are traditional and often very serious by nature. \n"
				<< "Earth signs value material things, work hard, and know how to make a plan and put it to action. \n"
				<< "You are most compatible with Taurus and Cancer.";
				return 0;
			} else if (birth_month == 1 && birth_day >= 20 ) {
				cout << "You are an Aquarius an an Air sign. \n"
				<< "Aquarius-born are shy and quiet , but on the other hand they can be eccentric and energetic. \n"
				<< "Air signs' main goal in life is often just to stop pleasing others and worrying about their opinions, \n"
				<< "so they can be able to follow their brightest and most liberating ideas. \n"
				<< "You are most compatible with Leo and Sagittarius.";
				return 0;
			} else if (birth_month == 3 && birth_day <= 20 ) {
				cout << "You are a Pisces and a Water sign. \n"
				<< "Pisces are very friendly, so they often find themselves in a company of very different people. \n"
				<< "Pisces are selfless, they are always willing to help others, without hoping to get anything back. \n"
				<< "Water signs are highly intuitive and they can be as mysterious as the ocean itself. \n"
				<< "You are most compatible with  Virgo and Taurus.";
				return 0;
			} else if (birth_month == 3 && birth_day > 20 ) {
				cout << "You are an Aries and a Fire sign. \n"
				<< "They are continuously looking for dynamic, speed and competition, \n"
				<< "always being the first in everything - from work to social gatherings. \n"
				<< "Fire signs truly uplift the strength of the Sun. \n"
				<< "You are most compatible with Libra and Leo.";
				return 0;
			} else if (birth_month == 5 && birth_day <= 20 ) {	
				cout << "You are a Taurus and an Earth sign. \n"
				<< "Taurus' feel the need to always be surrounded by love and beauty, \n"
				<< "turned to the material world, hedonism, and physical pleasures. \n"
				<< "Earth signs value material things, work hard, and know how to make a plan and put it to action. \n"
				<< "You are most compatible with Scorpio and Cancer.";
				return 0;
			} else if (birth_month == 5 && birth_day > 20 ) {
				cout << "You are a Gemini and an Air sign. \n"
				<< "Gemini are sociable, communicative and ready for fun, with a tendency to suddenly get serious, thoughtful and restless. \n"
				<< "Air signs' main goal in life is often just to stop pleasing others and worrying about their opinions, \n"
				<< "so they can be able to follow their brightest and most liberating ideas. \n"
				<< "You are most compatible with Sagittarius and Aquarius.";
				return 0;
			} else if (birth_month == 8 && birth_day < 23 ) {	
				cout << "You are a Leo and a Fire Sign. \n"
				<< "People born under the sign of Leo are natural born leaders. \n"
				<< "Fire signs truly uplift the strength of the Sun. \n"
				<< "You are most compatible with Aquarius and Gemini.";
				return 0;
			} else if (birth_month == 8 && birth_day >= 23 ) {
				cout << "You are a Virgo and an Earth sign. \n"
				<< "Virgos' methodical approach to life ensures that nothing is left to chance, \n"
				<< "and although they are often tender, their heart might be closed for the outer world. \n"
				<< "Earth signs value material things, work hard, and know how to make a plan and put it to action. \n"
				<< "You are most compatible with Pisces and Cancer.";
				return 0; 
			} else if (birth_month == 10 && birth_day <= 22 ) {	
				cout << "You are a Libra and an Air sign. \n"
				<< "People born under the sign of Libra are peaceful, fair, and they hate being alone. \n"
				<< "Air signs' main goal in life is often just to stop pleasing others and worrying about their opinions, \n"
				<< "so they can be able to follow their brightest and most liberating ideas. \n"
				<< "You are most compatible with Aries and Sagittarius.";
				return 0;
			} else if (birth_month == 10 && birth_day > 22 ) {
				cout << "You are a Scorpio and a Water sign. \n"
				<< "Scorpios are determined and decisive, and will research until they find out the truth. \n"
				<< "Water signs are highly intuitive and they can be as mysterious as the ocean itself. \n"
				<< "You are most compatible with Taurus and Cancer.";
				return 0;
			} else if (birth_month == 12 && birth_day <= 21 ) {	
				cout << "You are a Sagittarius and a Fire sign. \n"
				<< "Sagittarius' open mind and philosophical view motivates them to wander around the world in search of the meaning of life. \n"
				<< "Fire signs truly uplift the strength of the Sun. \n"
				<< "You are most compatible with Gemini and Aries.";
				return 0;
			} else {
				cout << "You are a Capricorn and a Earth sign. \n"
				<< "Capricorn is a sign that represents time and responsibility, \n"
				<< "and its representatives are traditional and often very serious by nature. \n"
				<< "Earth signs value material things, work hard, and know how to make a plan and put it to action. \n"
				<< "You are most compatible with Taurus and Cancer.";
				return 0;
			}
} else if (birth_month == 2) { /*feburary restriction*/
				while (!correct_two) {
		cout << "Please enter your birth day. (1-29) \n";
		cin >> birth_day;
			if (birth_day < 1 || cin.fail() || birth_day > 29 || floor(birth_day) != birth_day) {
					
				cin.clear();
				while (cin.get() != '\n');
				correct_two = false;
				
			} else {
				cin.ignore();
				correct_two = true;
				if (birth_day <= 18) {
					cout << "You are an Aquarius an an Air sign. \n"
				<< "Aquarius-born are shy and quiet , but on the other hand they can be eccentric and energetic. \n"
				<< "Air signs' main goal in life is often just to stop pleasing others and worrying about their opinions, \n"
				<< "so they can be able to follow their brightest and most liberating ideas. \n"
				<< "You are most compatible with Leo and Sagittarius.";
				return 0;
				} else {
					cout << "You are a Pisces and a Water sign. \n"
				<< "Pisces are very friendly, so they often find themselves in a company of very different people. \n"
				<< "Pisces are selfless, they are always willing to help others, without hoping to get anything back. \n"
				<< "Water signs are highly intuitive and they can be as mysterious as the ocean itself. \n"
				<< "You are most compatible with  Virgo and Taurus.";
				return 0;
				}
			} 
		}
} else {
				while (!correct_two) {
		cout << "Please enter your birth day. (1-30) \n"; /* 30 days restriction*/
		cin >> birth_day;
			if (birth_day < 1 || cin.fail() || birth_day > 30 || floor(birth_day) != birth_day) {
					
				cin.clear();
				while (cin.get() != '\n');
				correct_two = false;
			} else {
				cin.ignore();
				correct_two = true;
				if (birth_month = 4 && birth_day <= 19) {
					cout << "You are an Aries and a Fire sign. \n"
				<< "They are continuously looking for dynamic, speed and competition, \n"
				<< "always being the first in everything - from work to social gatherings. \n"
				<< "Fire signs truly uplift the strength of the Sun. \n"
				<< "You are most compatible with Libra and Leo.";
				return 0;
				} else if (birth_month = 4 && birth_day > 19) {
					cout << "You are a Taurus and an Earth sign. \n"
				<< "Taurus' feel the need to always be surrounded by love and beauty, \n"
				<< "turned to the material world, hedonism, and physical pleasures. \n"
				<< "Earth signs value material things, work hard, and know how to make a plan and put it to action. \n"
				<< "You are most compatible with Scorpio and Cancer.";
				return 0;
				} else if (birth_month = 6 && birth_day <= 20) {
					cout << "You are a Gemini and an Air sign. \n"
				<< "Gemini are sociable, communicative and ready for fun, with a tendency to suddenly get serious, thoughtful and restless. \n"
				<< "Air signs' main goal in life is often just to stop pleasing others and worrying about their opinions, \n"
				<< "so they can be able to follow their brightest and most liberating ideas. \n"
				<< "You are most compatible with Sagittarius and Aquarius.";
				return 0;
				} else if (birth_month = 6 && birth_day > 20) {
					cout << "You are a Cancer and a Water Sign. \n"
				<< "Cancers are very emotional and sensitive, and care deeply about matters of the family and their home. \n"
				<< "Water signs are highly intuitive and they can be as mysterious as the ocean itself. \n"
				<< "You are most compatible with Capricorn and Taurus.";
				return 0;
				} else if (birth_month = 9 && birth_day <= 22) {
					cout << "You are a Virgo and an Earth sign. \n"
				<< "Virgos' methodical approach to life ensures that nothing is left to chance, \n"
				<< "and although they are often tender, their heart might be closed for the outer world. \n"
				<< "Earth signs value material things, work hard, and know how to make a plan and put it to action. \n"
				<< "You are most compatible with Pisces and Cancer.";
				return 0; 
				} else if (birth_month = 9 && birth_day > 22) {	
						cout << "You are a Libra and an Air sign. \n"
				<< "People born under the sign of Libra are peaceful, fair, and they hate being alone. \n"
				<< "Air signs' main goal in life is often just to stop pleasing others and worrying about their opinions, \n"
				<< "so they can be able to follow their brightest and most liberating ideas. \n"
				<< "You are most compatible with Aries and Sagittarius.";
				return 0;
				} else if (birth_month = 11 && birth_day <= 21) {
					cout << "You are a Scorpio and a Water sign. \n"
				<< "Scorpios are determined and decisive, and will research until they find out the truth. \n"
				<< "Water signs are highly intuitive and they can be as mysterious as the ocean itself. \n"
				<< "You are most compatible with Taurus and Cancer.";
				return 0;
				} else {
					cout << "You are a Sagittarius and a Fire sign. \n"
				<< "Sagittarius' open mind and philosophical view motivates them to wander around the world in search of the meaning of life. \n"
				<< "Fire signs truly uplift the strength of the Sun. \n"
				<< "You are most compatible with Gemini and Aries.";
				return 0;
				}
			}	
		}
	}
}
