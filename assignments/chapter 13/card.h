#ifndef CARD_H
#define CARD_H

#include <vector>
#include <string>

class Card {
public:
    int rank;
    int suit;

    Card(int r, int s);
};

bool compareCards(Card a, Card b);
void addCard(Card c, std::vector<Card>& deck);

#endif // CARD_H