#include<iostream>
#include<cstring>
#include "Game.h"
#include <fstream>
#include <cstdlib>		// for rand(), srand()
#include <ctime>		// for clock()

void Randomize() // To shuffle deck, Source : cplusplus.com
{
	unsigned int seed = unsigned(clock());
	srand(seed);
}
void Player::showInfo(const char* fileName) {

	std::ofstream out(fileName, std::fstream::app);

	if (out.is_open()) {

		out << firstName << lastName << playedGames << winRatio <<current_points<<wins;
		out << std::endl;
		out.close();
	}

	else {
		std::cout << "File " << fileName << " is not open";
	}
}

void Player::addPoints(size_t add) 
{
	if (add == 11 && current_points > 10) {
		add = 1;
	}
	current_points+=add;
}
void Player::addWin() {
	wins++;
}
void Player::addGame() {
	playedGames++;
}
void Player::resetPoints() {
	current_points = 0;
}
void Player::winRate() {
	winRatio = wins / playedGames;
}

size_t Player::getPoints() 
{
	return current_points;
}

void Card::setSuit(Suit s)
{
	card_suit = s;
}

void Card::setRank(size_t r) 
{
	card_rank = r;
}
Suit Card::checkSuit()
{
	return card_suit;
}
int Card::checkRank()
{
	return card_rank;
}
int Card::points() 
{
	int card_points;

	if (card_rank >= 2 && card_rank <= 10) {
		card_points = card_rank;
	}

	else {

		if (card_rank == 11 || card_rank == 12 || card_rank == 13) {
			card_points = 10;
		}
		else {
			card_points = 11;
			}

	}
	return card_points;

}
void Card::display()
{

	if (card_rank >= 2 && card_rank <= 10) {
		std::cout << card_rank;
	}

	else {

		switch (card_rank) {
		case 11: std::cout << 'J'; break;
		case 12: std::cout << 'Q'; break;
		case 13: std::cout << 'K'; break;
		case 14: std::cout << 'A'; break;
		}

	}

	switch (card_suit) 
	{
	case Diamonds: std::cout << " of Diamonds"; break;
	case Clubs: std::cout << " of Clubs"; break;
	case Spades: std::cout << " of Spades"; break;
	case Hearts: std::cout << " of Hearts"; break;
	}

	std::cout << '\n';
}

int Deck::draw() 
{
	Card temp = deck_of_cards[topcard];
	topcard++;
	if (topcard > deckSize) {
		topcard = 1;
	}
	return temp.points();
}

int Deck::toPlayerPoints() 
{
	Card temp2 = deck_of_cards[topcard-1];
	return temp2.points();
}
void Deck::rank_and_suit()
{
	Card temp3 = deck_of_cards[topcard-1];
	 temp3.display();
}
void Deck::swap(size_t first, size_t second) 
{
	if (first >= 1 && first <= deckSize && second >= 1 && second <= deckSize && first != second) 
	{
		Card temp4 = deck_of_cards[first - 1];
		deck_of_cards[first - 1] = deck_of_cards[second - 1];
		deck_of_cards[second - 1] = temp4;
	}
}

int Deck::rank_count(char* val) 
{
	int toInt;
	if (!(strcmp(val, "2"))) {
    toInt = 2;
	}
	else if (!(strcmp(val, "3"))) {
	toInt = 3;
	}
	else if (!(strcmp(val, "4"))) {
	toInt = 4;
	}
	else if (!(strcmp(val, "5"))) {
	toInt = 5;
	}
	else if (!(strcmp(val, "6"))) {
	toInt = 6;
	}
	else if (!(strcmp(val, "7"))) {
	toInt = 7;
	}
	else if (!(strcmp(val, "8"))) {
	toInt = 8;
	}
	else if (!(strcmp(val, "9"))) {
	toInt = 9;
	}
	else if (!(strcmp(val, "10"))) {
	toInt = 10;
	}
	else if (!(strcmp(val, "J"))) {
	toInt = 11;
	}
	else if (!(strcmp(val, "Q"))) {
	toInt = 12;
	}
	else if (!(strcmp(val, "K"))) {
	toInt = 13;
	}
	else if (!(strcmp(val, "A"))) {
	toInt = 14;
	}
	

	int num = 0;

	for (int d = topcard; d < deckSize; d++) {

		if (deck_of_cards[d].checkRank() == toInt) {
			num++;
		}
	}
	return num;
}
int Deck::suit_count(Suit p)
{
	int num = 0;

	for (int d = 0; d < deckSize; d++) {

		if (deck_of_cards[d].checkSuit() == p) {
			num++;
		}

	}

	return num;
}

void Deck::Shuffle()

{
	Randomize();
	
		for (int j = 0; j < deckSize; j++)
		{
			int r = rand() % deckSize;
			Card c = deck_of_cards[j];
			deck_of_cards[j] = deck_of_cards[r];
			deck_of_cards[r] = c;
		}
	
}
