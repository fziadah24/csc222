#include "Card.h"

Card::Card(int r, int s) : rank(r), suit(s) {}

bool compareCards(Card a, Card b) {
    return a.rank < b.rank;
}

void addCard(Card c, std::vector<Card>& deck) {
    deck.push_back(c);
}