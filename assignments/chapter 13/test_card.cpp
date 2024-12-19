#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Card.h"

TEST_CASE("Test Card Creation and Comparison") {
    Card card1(1, 1);
    Card card2(2, 2);
    
    CHECK(compareCards(card1, card2) == true);
    CHECK(compareCards(card2, card1) == false);
}

TEST_CASE("Test Adding Card to Deck") {
    std::vector<Card> deck;
    Card card1(1, 1);
    
    addCard(card1, deck);
    
    CHECK(deck.size() == 1);
    CHECK(deck[0].rank == 1);
    CHECK(deck[0].suit == 1);
}