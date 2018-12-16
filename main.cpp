/*
	C++ implementation of Go, a game invented in China around 4,000 years ago.
	Written by Jacob Seadorf, December 16, 2018.
*/

#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

bool gameOver = false;

//RNG, for the makeMove function
default_random_engine RNG(time(NULL));
uniform_int_distribution<int> boardX(1, 9); //random coordinate for boardX
uniform_int_distribution<int> boardY(1, 9); //random coordinate for boardY

//int board[9][9]; //start off with a 9x9 board
void makeMove();
void play();


int main() {
	play();
	return 0;
	}

void makeMove() {
	int cpuX = boardX(RNG); //cpu coordinates for x and y
	int cpuY = boardY(RNG);
	int x, y; //Player coordinates for x and y
	bool validMove = true; //assume a move is valid until checked.
	//CPU moves first...
	std::cout << "X: " << cpuX << std::endl;
	std::cout << "Y: " << cpuY << std::endl;

	//...Player moves second
    std::cout << "Enter X: " << std::endl;
    std::cin >> x;
    std::cout << "Enter Y: " << std::endl;
    std::cin >> y;

    //valid move checking
    if(cpuX == x && cpuY == y || x == cpuX && y == cpuY) {
		validMove = false;
		std::cout << "Illegal move.\n";
		makeMove();
    } else {
		validMove = true;
		std::cout << "Valid move.\n";
		gameOver = true; //end the "game" (REMOVE ONCE GAME IS COMPLETE).
    }
}

void play() {
while(!gameOver) {
	makeMove();
	}
}
