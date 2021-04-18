#include<iostream>
#include "Game.h"
#include <fstream>
#include<cstring>
#include <cstdlib>		// for rand(), srand()
#include <ctime>		// for clock()

int main() {
	

	std::ofstream file("newPlayer.txt");
	file.close();

	std::cout << "Enter player name:" << '\n';

	char playerFirstName[20];
	char playerLastName[20];

	std::cin >> playerFirstName;
	std::cin >> playerLastName;
	
	Player player1(playerFirstName, playerLastName);
	
	size_t size;
	std::cout << "Choose deck size"<<'\n';
	std::cin >> size;

	Deck deck1(size);
	deck1.Shuffle();

	bool playing = true;
	char action[20];

	
	while (playing) {

		std::cout << '\n' << "hit/stand" << '\n';

		std::cin >> action;

		if (!strcmp(action, "hit")) {

			deck1.draw();
			player1.addPoints(deck1.toPlayerPoints());
			deck1.rank_and_suit();
			std::cout << "(points: " << player1.getPoints() << ')';

		}
		else if (!strcmp(action, "stand"))
		{
			playing = false;
		}

		else {

			std::cout << "Please enter a valid command";
			continue;
		}
	
		if (player1.getPoints() > 21) {
			std::cout << "You lose!" << '\n';
			playing = false;
		}

	}

	if (player1.getPoints() <= 21) {

		int dealerSum = 0;
		std::cout << "Dealer's draw: ";
		while (dealerSum <= 16) {
			dealerSum += deck1.draw();
			deck1.rank_and_suit();
		}
		
		std::cout << "(points: " << dealerSum << ')' << '\n';

		if (dealerSum > 21) {
			std::cout << "You win!";
			player1.addWin();
		}
		else if (player1.getPoints() >= dealerSum) {
			std::cout << "You win!";
			player1.addWin();
		}
		else {
			std::cout << "You lose!";
		}
	}
	player1.addGame();
	player1.resetPoints();
	player1.winRate();
	player1.showInfo("newPlayer.txt");

	
	return 0;
}