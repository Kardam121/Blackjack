enum Suit {Spades, Diamonds, Hearts, Clubs};

void getPlayerInfo(const char*);

class Player {

	char firstName[20];
	char lastName[20];
	size_t playedGames;
	double winRatio;
	size_t current_points;
	size_t wins;


public:

	Player(char* x, char* y) {
		strcpy_s(firstName, x);
		strcpy_s(lastName, y);
		playedGames = 0;
		winRatio = 0;
		current_points = 0;
		wins = 0;
	}

	Player(char* x, char* y, size_t z, double l, size_t m, size_t p) {
		strcpy_s(firstName, x);
		strcpy_s(lastName, y);
		playedGames = z;
		winRatio = l;
		current_points = m;
		wins = p;

	}
	void addWin();
	void addGame();
	void resetPoints();
	void winRate();
	void addPoints(size_t);
	size_t getPoints();
	void showInfo(const char*);
	
	
};

class Card{
public:

	Suit card_suit;
	size_t card_rank;

	Card() {}

	void setSuit(Suit);
	void setRank(size_t);
	void display();
	Suit checkSuit();
	int checkRank();
	int points();
};

class Deck{

	size_t deckSize;
	size_t topcard;
	Card deck_of_cards[204];

public:
	
	Deck(size_t x) {
		deckSize = x;
		topcard = 0;

		for (int i = 0; i < deckSize; i++) {

			deck_of_cards[i].setRank(i % 13 + 2);

			switch ((i / 13) % 4)
			{
			case 0: deck_of_cards[i].setSuit(Clubs); break;
			case 1: deck_of_cards[i].setSuit(Diamonds); break;
			case 2: deck_of_cards[i].setSuit(Hearts); break;
			case 3: deck_of_cards[i].setSuit(Spades); break;
			}

		}
	}


	int draw();
	int toPlayerPoints();
	void rank_and_suit();
	void Shuffle();
	void swap(size_t, size_t);
	int rank_count(char*);
	int suit_count(Suit);

};
