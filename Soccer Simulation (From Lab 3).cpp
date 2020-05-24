/*Bryan Yam
20828243
October 7, 2019
SYDE 121
A. Chung
CPH 1346
Lab 03, 01*/	
/*The purpose of this program is to simulate a soccer game.*/

/*I used cout to test that the output events were random*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

bool run_soccer_simulation(); 
/*runs simulation 
no inputs
no returns
*/

void shot_on_target(string team_name, int& goals, int& on_goal, int& off_goal, int& blocked); 
/*shot on target for cases 1,2,3,4
input: team_name = team name, goals = goals for respective team, on_goal = saved, off_goal = miss, blocked = blocked shot
returns outcome of shot as a cout and counts stats
*/
void penalty(string team_name, int& goals, int& on_goal, int& off_goal); /*penalty function*/
/*shot on target for cases 5,6
input: team_name = team name, goals = goals for respective team, on_goal = saved, off_goal = miss
returns outcome of shot as a cout and counts stats
*/
void card(string team_name, int& red, int& yellow, int& fouls); /*card function*/
/*card for cases 3,4,5,6
input: team_name = team name, red = red card for team, yellow = yellow card for team
returns outcome of card as a cout and counts stats
*/
int main() { 
/*runs the simulation*/
	run_soccer_simulation();
	cout << "\nSoccer simulation completed successfully." << endl;
	return 0;
}

bool run_soccer_simulation() {
/*declare stat variables for both teams*/
	const string team_a = "Team A", team_b = "Team B";
	int a_goals = 0, b_goals = 0, a_on_goal = 0, b_on_goal = 0, a_off_goal = 0, b_off_goal = 0;
	int a_blocked = 0, b_blocked = 0, no_of_events, cur_event, a_fouls = 0, b_fouls = 0;
	int a_red = 0, a_yellow = 0, b_red = 0, b_yellow = 0;
	
	srand(time(0)); /*generates different seed value per generation of program*/
	
	no_of_events = (rand() % 30) + 1; /*calculates # of events in game*/
	
	for (int event = 1; event <= no_of_events; ++event) { /*for every event, determines an action*/
/*outputs scores at halftime*/		
	if (event == (no_of_events/2)) {
	   cout << "\nHALFTIME \n"
	   << "\t" << team_a << "\t\t\t" << team_b << "\n"
	   << "\t" << a_goals << "\tGOALS\t\t" << b_goals << "\n"
	   << "\t" << a_on_goal << "\tSHOTS ON GOAL\t" << b_on_goal << "\n"
	   << "\t" << a_off_goal << "\tSHOTS OFF GOAL\t" << b_off_goal << "\n"
	   << "\t" << a_blocked << "\tSHOTS BLOCKED\t" << b_blocked << "\n"
	   << "\t" << a_fouls << "\tFOULS\t\t" << b_fouls << "\n"	
	   << "\t" << a_yellow << "\tYELLOW CARDS\t" << b_yellow << "\n"
	   << "\t" << a_red << "\tRED CARDS\t" << b_red << "\n\n";	
    }
    cur_event = (rand() % 6) + 1;
		switch(cur_event) {
			case 1:
				cout << "Team A has shot the ball! \n\n"; 
				shot_on_target(team_a, a_goals, a_on_goal, a_off_goal, b_blocked); /*calls shot on target function and declares variables for team a*/
				break;
			case 2:
				cout << "Team B has shot the ball! \n\n";
				shot_on_target(team_b, b_goals, b_on_goal, b_off_goal, a_blocked); /*calls shot on target function and declares variables for team b*/	
				break;
			case 3:
				cout << "Team B has fouled Team A, Team A receives a free kick. \n\n";
				card(team_b, b_red, b_yellow, b_fouls); /*calls card function for team b*/
				shot_on_target(team_a, a_goals, a_on_goal, a_off_goal, b_blocked); /*calls shot on target function and declares variables for team a*/
			case 4:
				cout << "Team A has fouled Team B, Team B receives a free kick. \n\n";
				card(team_a, a_red, a_yellow, a_fouls); /*calls card function for team a*/
				shot_on_target(team_b, b_goals, b_on_goal, b_off_goal, a_blocked); /*calls shot on target function and declares variables for team b*/	
			case 5:
				cout << "Team B has fouled Team A close to the goal, Team A receives a penalty. \n\n";
				card(team_b, b_red, b_yellow, b_fouls); /*calls card function for team b*/
				penalty(team_a, a_goals, a_on_goal, a_off_goal); /*calls penalty function and declares variables for team a*/	
			case 6:	
				cout << "Team A has fouled Team B close to the goal, Team B receives a penalty. \n\n"; 
				card(team_a, a_red, a_yellow, a_fouls); /*calls card function for team a*/
				penalty(team_b, b_goals, b_on_goal, b_off_goal); /*calls penalty function and declares variables for team b*/		
		}
	}
/*displays full time scores*/
    cout << "\nFULL TIME \n"
 	<< "\t" << team_a << "\t\t\t" << team_b << "\n"
  	<< "\t" << a_goals << "\tGOALS\t\t" << b_goals << "\n"
   	<< "\t" << a_on_goal << "\tSHOTS ON GOAL\t" << b_on_goal << "\n"
   	<< "\t" << a_off_goal << "\tSHOTS OFF GOAL\t" << b_off_goal << "\n"
   	<< "\t" << a_blocked << "\tSHOTS BLOCKED\t" << b_blocked << "\n"
   	<< "\t" << a_fouls << "\tFOULS\t\t" << b_fouls << "\n"
   	<< "\t" << a_yellow << "\tYELLOW CARDS\t" << b_yellow << "\n"
   	<< "\t" << a_red << "\tRED CARDS\t" << b_red << "\n";
	return true;
}

void shot_on_target(string team_name, int& goals, int& on_goal, int& off_goal, int& blocked) { /*determines output for cases 1,2,3,4 depending on the call of reference*/
	int shot_outcome;
	
	shot_outcome = rand() % 4;
	/*output based on random number*/
	switch(shot_outcome) {
		case 0:
			cout << "\t" << team_name << " has scored a goal! Fantastic shot!\n\n"; /*goal has been scored, keeps record of goal and shot on net*/
			++goals;
			++on_goal;
			break;
		case 1:
			cout << "\t" << team_name << " has shot on goal. Great save by the opposing team.\n\n"; /*shot has saved, keeps record of shot on net*/
			++on_goal;
			break;
		case 2:
			cout << "\t" << team_name << " has shot off goal. Excellent attempt.\n\n"; /*shot has missed, keeps record of shot off net*/
			++off_goal;
			break;
		case 3:
			cout << "\t" << team_name << "'s shot was blocked. Excellent attempt.\n\n"; /*shot has been blocked, keeps record of blocked shot*/
			++blocked;
			break;
	}
}	

void penalty(string team_name, int& goals, int& on_goal, int& off_goal) { /*determines output for cases 5,6*/
    int shot_outcome;
	
	shot_outcome = rand() % 3;
	/*output based on random number*/
	switch(shot_outcome) {
		case 0:
			cout << "\t" << team_name << " has scored a goal! Fantastic shot!\n\n"; /*goal has been scored, keeps record of goal and shot on net*/
			++goals; /*keeps stat for assigned variable*/
			++on_goal;
			break;
		case 1:
			cout << "\t" << team_name << " has shot on goal. Great save by the opposing team.\n\n"; /*shot has saved, keeps record of shot on net*/
			++on_goal;
			break;
		case 2:
			cout << "\t" << team_name << " has shot off goal. Excellent attempt.\n\n"; /*shot has missed, keeps record of shot off net*/
			++off_goal;
			break;
    }
}

void card(string team_name, int& red, int& yellow, int& fouls) /*determines output for cases 3,4,5,6*/
{ 
	int card_outcome;
	
	card_outcome = rand() % 3; 
	/*output based on random number*/
	switch(card_outcome) 
	{
		case 0:
			cout << "\t" << team_name << " has received no card from the referee. \n\n"; /*no card has been given*/
			++fouls;
			break;
		case 1:
	 	    cout << "\t" << team_name << " has received a yellow card from the referee. \n\n"; /*yellow card has been given, keeps record of card*/	
	        ++yellow;
	        ++fouls;
	        break;
	 	case 2: 
		 	cout << "\t" << team_name << " has received a red card from the referee. \n\n"; /*red card has been given, keeps record of card*/	
			++red;
			++fouls;  
			break;
	}
}
