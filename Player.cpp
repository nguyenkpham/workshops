#include "Player.h"

Player::Player(std::string playerName) : 
name(playerName), health(100), isBlocking(false) {
}


void Player::takeDamage(int damage) {
    if (isBlocking == true) {
        damage /= 2;
        isBlocking = false; 
    }
    health -= damage;

    if(health < 0){
        health = 0;
    }  
}

void Player::setBlocking(bool blocking) {
    isBlocking = blocking;
}

bool Player::getIsBlocking() {
    return isBlocking;
}

int Player::getHealth() {
    return health;
}

std::string Player:: getName() {
    return name;
}

bool Player::isAlive() {
    return health > 0;
}