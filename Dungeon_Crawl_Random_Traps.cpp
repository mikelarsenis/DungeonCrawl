#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

char grid[]{"..........\n..........\n..........\n..........\n..........\n..........\n.........X\0"}; 
int row = 0;
int column = 0;
int gPosition = ((row*11)+column); // (row * 11) + column
int xPosition = ((6*11) + 9);
int trap1;
int trap2;
int trap3;
int trap4;
int trap5;
int trap6;

//Returns the position of the player
int GetgPosition() 
{
	gPosition = ((row * 11) + column);
	return gPosition;
}

//Prints the board
void PrintBoard()
{
	system("cls");
	cout << grid << endl << endl;
}

//Checks if going off the board
bool ColumnCheckRight()
{
	if ((column + 1) >= 10) // too far right
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool ColumnCheckLeft()
{
	if ((column - 1)<0) // too farfar left
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool RowCheckTop()
{
	if (row - 1 < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool RowCheckBottom()
{
	if (row +1 > 6)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Moves player
void MoveRight()
{
	grid[gPosition] = '-';
	column++;
	GetgPosition();
	grid[gPosition] = 'G';
	PrintBoard();
}
void MoveLeft()
{
	grid[gPosition] = '-';
	column--;
	GetgPosition();
	grid[gPosition] = 'G';
	PrintBoard();
}
void MoveUp() //dec row
{
	grid[gPosition] = '-';
	row--;
	GetgPosition();
	grid[gPosition] = 'G';
	PrintBoard();
}
void MoveDown()
{
	grid[gPosition] = '-';
	row++;
	GetgPosition();
	grid[gPosition] = 'G';
	PrintBoard();
}

//Checks if player stepped on trap
bool TrapCheck()
{
	if (gPosition == trap1 || gPosition == trap2 || gPosition == trap3 || gPosition == trap4 || gPosition == trap5 || gPosition == trap6)
	{
		return true; //they stepped on a trap
	}
	else
	{
		return false;
	}
}

//Called when player steps on trap
void TrapTripped()
{
	//display trap positions on board
	grid[trap1] = 'T';
	grid[trap2] = 'T';
	grid[trap3] = 'T';
	grid[trap4] = 'T';
	grid[trap5] = 'T';
	grid[trap6] = 'T';
	grid[gPosition] = 'G';

	PrintBoard();
	cout << " SNAP! You stepped on a trap and now you're bleeding to death...\n\n GAME OVER\n\n";
	system("pause");
	::exit(1);
}

//Displays instructions
void PrintInstructions()
{
	system("cls");
	cout << "\nYour goal is to move the player 'G' through the board toward the goal 'X'.\nDon't step on the traps 'T', which are hidden, or you will lose.\n\n";
	cout << "You are going to use your number pad to make your moves.\nPress 8 to move up, 4 to move left,\n6 to move right, and 5 to move down.\n\n";
	system("pause");
}

int main()
{
	{ //instructions scope
		char instructions;

		system("cls");
		cout << "*****Welcome to Dungeon Crawl*****\n\n  Press 1 for instructions, otherwise press any key to play. ";
		instructions = _getch();
		if (instructions == '1')
		{
			PrintInstructions();
		}	
	} //instructions scope

	//seed srand
	srand(time(NULL));
	
	//Set Traps
		// Trap 1
		trap1 = ((rand() % 7 * 11) + rand() % 10);   // ((r*11)+column)
		//make sure trap is not set to player position or another trap
		if (trap1 == GetgPosition() || trap1 == xPosition)
		{
			trap1 = ((rand() % 10 * 11) + rand() % 7);
		}

		// Trap 2
		trap2 = ((rand() % 7 * 11) + rand() % 10);   // ((r*11)+column)
		if (trap2 == GetgPosition() || trap2 == xPosition || trap2==trap1)
		{
			trap2 = ((rand() % 10 * 11) + rand() % 7);
		}

		// Trap 3
		trap3 = ((rand() % 7 * 11) + rand() % 10);   // ((r*11)+column)
		if (trap3 == GetgPosition() || trap3 == xPosition || trap3 == trap1 || trap3 == trap2)
		{
			trap3 = ((rand() % 10 * 11) + rand() % 7);
		}

		// Trap 4
		trap4 = ((rand() % 7 * 11) + rand() % 10);   // ((r*11)+column)
		if (trap4 == GetgPosition() || trap4 == xPosition || trap4 == trap1 || trap4 == trap2 || trap4 == trap3)
		{
			trap4 = ((rand() % 10 * 11) + rand() % 7);
		}

		// Trap 5
		trap5 = ((rand() % 7 * 11) + rand() % 10);   // ((r*11)+column)
		if (trap5 == GetgPosition() || trap5 == xPosition || trap5 == trap1 || trap5 == trap2 || trap5 == trap3 || trap5 == trap4)
		{
			trap5 = ((rand() % 10 * 11) + rand() % 7);
		}

		// Trap 6
		trap6 = ((rand() % 7 * 11) + rand() % 10);   // ((r*11)+column)
		if (trap6 == GetgPosition() || trap6 == xPosition || trap6 == trap1 || trap6 == trap2 || trap6 == trap3 || trap6 == trap4 || trap6 == trap5)
		{
			trap6 = ((rand() % 10 * 11) + rand() % 7);
		}
	
	grid[gPosition] = 'G';

	//TESTING: displays trap position during game play
	//grid[trap1] = 'T';
	//grid[trap2] = 'T';
	//grid[trap3] = 'T';
	//grid[trap4] = 'T';
	//grid[trap5] = 'T';
	//grid[trap6] = 'T';

	while (::exit) //allows to jump to beginning of loop if running off board
	{
		while ((gPosition != xPosition)) //while player has made goal
		{
			char move;

			//cout << grid[10]; // new line character
			PrintBoard();
			move = _getch();
			
			//valid data check
			while (move != '8' && move != '4' && move != '6' && move != '5')
			{
				cout << "Please use keys 4, 5, 6, and 8 to make your move.\n";
				move = _getch();
			}
			
			if (move == '8') //move up
			{
				if (RowCheckTop()) //Check if moving off board
				{
					cout << "You cannot move off the board. Make another selection\n";
					system("pause");
					continue;
				}
				MoveUp(); //move player
				if (TrapCheck()) //check if stepped on trap
				{
					TrapTripped();
				}
			}
			if (move == '4') //move left
			{
				if (ColumnCheckLeft())
				{
					cout << "You cannot move off the board. Make another selection\n";
					system("pause");
					continue;
				}
				MoveLeft();
				if (TrapCheck())
				{
					TrapTripped();
				}
			}
			if (move == '6') //move right
			{
				if (ColumnCheckRight())
				{
					cout << "You cannot move off the board. Make another selection\n";
					system("pause");
					continue;
				}
				MoveRight();
				if (TrapCheck())
				{
					TrapTripped();
				}
			}
			if (move == '5') //move down
			{
				if (RowCheckBottom())
				{
					cout << "You cannot move off the board. Make another selection\n";
					system("pause");
					continue;
				}
				MoveDown();
				if (TrapCheck())
				{
					TrapTripped();
				}
			}
		} // end while

		cout << "You made it! YOU WIN!!\n\nPress any key to close...";
		_getch();
		::exit(0);
	}//end exit while
}// end main