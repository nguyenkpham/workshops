#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int health;
    bool isBlocking;
   
public:
    // ========================================
    // TODO: Implement constructor.
    // ========================================
    Player(std::string playerName);
    

    // ========================================
    // TODO: Implement takeDamage. Refer to problem description for function behaviour.
    // ========================================
    void takeDamage(int damage);
    
    
    // ========================================
    // TODO: Implement setter and getters.
    // ========================================
    void setBlocking(bool blocking);
    bool getIsBlocking();
    int getHealth();
    std::string getName();
    bool isAlive();
};

#endif
