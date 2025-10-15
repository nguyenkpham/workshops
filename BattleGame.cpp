#include "BattleGame.h"



// ========================================
// TODO: Initialize static variables outside the class
// ========================================
// CRITICAL: Static variables must be defined here, outside the class
// Format: int BattleGame::variableName = 0;
// Initialize all four static variables to 0

int BattleGame::totalGamesPlayed = 0;
int BattleGame::totalDamageDealt = 0;
int BattleGame::player1Wins = 0;
int BattleGame::player2Wins = 0;



// ====================


// Constructor. Implementation given.
BattleGame::BattleGame(std::string p1Name, std::string p2Name)
    : player1(p1Name), player2(p2Name), currentState(GameState::PLAYING)
{}



// ========================================
// TODO: Implement calculateDamage
// ========================================
// Based on the ActionType. Return damage values for:
//   LIGHTATTACK: 15
//   HEAVYATTACK: 30
//   BLOCK: 0
// If using a switch statement, remember to set default: 0.
int BattleGame::calculateDamage(ActionType action) {
    if (action == ActionType::LIGHTATTACK) {
        return 15;
    } else if (action == ActionType::HEAVYATTACK) {
        return 30;
    } else if (action == ActionType::BLOCK) {
        return 0;
    }
}


// ========================================
// TODO: Implement resolveActions
// ========================================
// This function applies damage from both players
// 1. Calculate damage for both players. Which method from BattleGame should be used here?
// 2. If p1Damage > 0:
//    - Apply damage to player2 (Which method from Player should be used here?)
//    - Add to static counter totalDamageDealt
// 3. If p2Damage > 0:
//    - Apply damage to player1 (Which method from Player should be used here?)
//    - Add to static counter totalDamageDealt
void BattleGame::resolveActions(ActionType p1Move, ActionType p2Move) {

    int p1Damage = calculateDamage(p1Move);
    int p2Damage = calculateDamage(p2Move);

    if (p1Damage > 0){
        player2.takeDamage(p1Damage);
        totalDamageDealt += p1Damage;
    }

    else if (p2Damage > 0){
        player1.takeDamage(p2Damage);
        totalDamageDealt += p2Damage;
    }
    
}


// ========================================
// TODO: Implement updateGameState
// ========================================
// This function checks if the game has ended and updates statistics
// 1. Check if both players are alive. Which Player class function can you use here?
// 2. Determine outcomes for:
//    i.   If both players are not alive
//    ii.  If only p1 not alive
//    iii. If only p2 not alive
// 3. For each of the possible outcomes
//    - Set appropriate game states (refer to GameState enum values)
//    - Increment the static variables player1Wins or player2Wins where necessary.
//    - Increment the static variable totalGamesPlayed
//
// IMPORTANT: Notice we increment totalGamesPlayed HERE when game ends,
// NOT in the constructor. A game is only "played" when it finishes!
void BattleGame::updateGameState() {
     if (!player1.isAlive() && !player2.isAlive()) {
        currentState = GameState::DRAW;
        totalGamesPlayed++;
    }

    else if (player1.isAlive() && !player2.isAlive()){
        currentState = GameState::PLAYER1_WON;
        totalGamesPlayed++;
        player1Wins++;
    }

    else if (!player1.isAlive() && player2.isAlive()){
        currentState = GameState::PLAYER2_WON;
        totalGamesPlayed++;
        player2Wins++;
    }
    else if (player1.isAlive() && player2.isAlive()) {
        currentState = GameState::PLAYING;
    }
    

    
    
}


// ========================================
// TODO: Implement executeTurn
// ========================================
// This function orchestrates a single turn of combat. (Also demonstrates function decomposition)
// 1. Set each player's blocking status:
//    - If action is BLOCK, call setBlocking(true)
//    - Otherwise, call setBlocking(false)
// 2. Call resolveActions(p1Move, p2Move)
// 3. Call updateGameState()
void BattleGame::executeTurn(ActionType p1Move, ActionType p2Move) {
   if (p1Move == ActionType::BLOCK) {
    player1.setBlocking(true);
   } else {
    player1.setBlocking(false);
   }

   if (p2Move == ActionType::BLOCK) {
    player2.setBlocking(true);
   } else {
    player2.setBlocking(false);

   }

   resolveActions(p1Move, p2Move);
   updateGameState();
}


// Displays current HP for both players. Implementation is given.
void BattleGame::displayStatus() {
    std::cout << "\n=== Battle Status ===" << std::endl;
    std::cout << player1.getName() << " HP: " << player1.getHealth() << std::endl;
    std::cout << player2.getName() << " HP: " << player2.getHealth() << std::endl;
    std::cout << "===================\n" << std::endl;
}

// ========================================
// TODO: Returns the current game's state.
// ========================================
GameState BattleGame::getGameState() {
   
}


// Displays the current game's statistics. Implementation is given.
void BattleGame::displayStatistics() {
    std::cout << "\n=== Game Statistics ===" << std::endl;
    std::cout << "Total Games Played: " << totalGamesPlayed << std::endl;
    std::cout << "Total Damage Dealt: " << totalDamageDealt << std::endl;
    std::cout << "Player 1 Wins: " << player1Wins << std::endl;
    std::cout << "Player 2 Wins: " << player2Wins << std::endl;
    std::cout << "=======================\n" << std::endl;
}


// ========================================
// TODO: Returns the total number of games played.
// ========================================
int BattleGame::getTotalGamesPlayed() {

}


