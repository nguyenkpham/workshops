// Deck.cpp (Skeleton)
#include <iostream>

#include "Creature.h"
#include "Deck.h"
#include "Land.h"

int Deck::totalDecks = 0;

Deck::Deck() {
  // Initialize an empty deck
  totalDecks++;
}

Deck::Deck(const Deck& other) {
  totalDecks++;
  // Deep copy cards from other
  for (Card* c : other.cards) {
    cards.push_back(c->clone());
    // TODO: copy/clone card from the deck and add it to teh new deck
    // NOTE: Increment Card count static in each new Card's constructor (happens
    // automatically)
  }
}

Deck::~Deck() {
  // Delete all cards in the deck
  for (Card* c : cards) {
    delete c;
  }
  totalDecks--;
}

void Deck::addCard(Card* card) {
  cards.push_back(card);
  // NOTE: (Card count is updated by Card constructor of the object being added)
}

int Deck::size() const {
    return cards.size();
  // TODO: return number of cards in deck
}

int Deck::countCreatures() const {
  int count = 0;
  for (Card* c : cards) {
    if (c->getType() == Card::Type::CREATURE){
        count++;
        }
    }
    // TODO: if c is a Creature , increment count
  return count;
}

void Deck::printDeck() const {
  std::cout << "Deck contains " << cards.size() << " cards:" << std::endl;
  for (Card* c : cards) {
    // TODO: print details of each card
    c->printInfo();
  }
}

int Deck::getTotalDecks() { return totalDecks; }