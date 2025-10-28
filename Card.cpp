#include <iostream>

#include "Card.h"

int Card::totalCards = 0;

Card::Card(const std::string& n, int c) : name(n), cost(c) {
    totalCards++;
}

Card::~Card() {
    totalCards--;
}

std::string Card::getName() const {
  // TODO: return the card name
    return name;
}

int Card::getCost() const {
  // TODO: return the card cost
    return cost;
}

int Card::getTotalCards() {
  // TODO: return the totalCards count
    return totalCards;
}