/*Bryan Yam
20828243
October 21, 2019
SYDE 121
A. Chung
CPH 1346
Lab 04, 01*/	
/*The purpose of this program is to simulate a tic tac toe game.*/

/*I tested the program for multiple games to confirm that it resets and keeps track of the number of games, wins and turns*/
/*Also tested all winning combinations and ties*/
#include <iostream>

using namespace std;

void run_sim(int& game_num, int& x_win, int& o_win);
/*runs the tic tac toe simulation*/
/*inputs the game number, as well as variables to track wins*/
/*no outputs*/

void print(string board[][4]);
/*prints the board in a 4x4 config*/
/*uses the array inputted*/
/*outputs the board display*/

void turn(string board[][4], string move);
/*performs a turn*/
/*takes the board input and the player input*/
/*no outputs*/

bool check(string board[][4], string move);
/*checks if someone has won*/
/*inputs the board input and the player input*/
/*outputs false when someone has won*/

int main() /*runs the simulation*/
{
	int game_num = 0;
	int x_win = 0;
	int o_win = 0;
	char input;
	do
	{
		game_num++; /*keeps track of the game number*/
		run_sim(game_num, x_win, o_win);
		cout << "Would you like to play again? (y/n) \n";
		cin >> input; 
	} while (input == 'y'); /*only runs again if user types y*/
	cout << "X has won " << x_win << " times. \n";
	cout << "O has won " << o_win << " times. \n";
	cout << "You have tied " << game_num - x_win - o_win << " times. \n";
	return 0;
}

void run_sim(int& game_num, int& x_win, int& o_win)
{
	string board[4][4] = {{"1","2","3","4"},{"5","6","7","8"},{"9","10","11","12"},{"13","14","15","16"}}; /*resets the board everytime you play*/
	
	int input = 0;
	int move_num = 0;
	string letter;
	if (game_num % 2 == 1) /*determines who goes first*/
	    letter = "X";
	else
		letter = "O";
	
	do
	{
		print(board);
		turn(board, letter);
		move_num++;
		if (letter == "X") /*switches player turn*/
		    letter = "O";
		else 
	 	    letter = "X";    	
	} while (check(board, "X") && check(board, "O") && move_num != 16); /*checks if a player has won or tied each turn*/
	if (!check(board, "X"))
	{
		print(board); /*winner/tie statements and outputs*/
		x_win++;
		cout << "X wins! \n";
	} else if (!check(board, "O")) {
		print(board);
		o_win++;
		cout << "O wins! \n";
	} else {
		print(board);
		cout << "Tie! \n";
	}
}

void turn(string board[][4], string move)
{
	bool correct = false;
	string input;
    while (!correct) /*if number does not exist or input is already taken, loop continues*/
	{
	    cout << "Where would you like to play " << move << "\n";
		cin >> input;
		 	for (int i = 0; i < 4; i++) /*checks all values in array for match with input number*/
		 	{
		 		for (int j = 0; j < 4; j++)
		 		{
		 			if (board[i][j] == input)
		 			{
		 			board[i][j] = move;
		 			correct = true;
		 			}
	 			}
	 		}
 	}
}
void print(string board[][4])
{
	for (int i = 0; i < 4; i++) /*prints board as a 4x4 grid*/
	{
		for (int j = 0; j < 4; j++)
		{
			cout << board[i][j] << "\t";
		}
		cout << "\n"; 
	}
}

bool check(string board[][4], string move)
{
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;	
	for (int a = 0; a < 4; a++) /*checks horizontal win*/
	{
		if (board[a][0] == board[a][1] && board[a][1] == board[a][2] && board[a][2] == board[a][3] && board[a][3] == move)
		return false;
	}
	
	for (int a = 0; a < 4; a++) /*checks vertical win*/
	{
		if (board[0][a] == board[1][a] && board[1][a] == board[2][a] && board[2][a] == board[3][a] && board[3][a] == move)
		return false;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == move) /*diagonal wins*/
	return false;
	else if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[0][3] && board[0][3] == move)
	return false; /*returns false to stop the while loop in sim*/
	else
	return true;
}
