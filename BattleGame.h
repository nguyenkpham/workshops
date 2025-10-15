#ifndef BATTLEGAME_H
#define BATTLEGAME_H

#include "Player.h"
#include <iostream>

// ========================================
// TODO: Define ActionType enum
// ========================================
enum class ActionType {
    LIGHTATTACK,
    HEAVYATTACK,
    BLOCK
};
// ========================================

// ========================================
// TODO: Define GameState enum
// ========================================
enum class GameState {
    PLAYING,
    PLAYER1_WON,
    PLAYER2_WON,
    DRAW
};
// ========================================

class BattleGame {
private:
    Player player1;
    Player player2;
    GameState currentState;


    // ========================================
    // TODO: Declare 4 static member variables. Refer to problem description.
    // ========================================

    static int totalGamesPlayed;
    static int totalDamageDealt;
    static int player1Wins;
    static int player2Wins;



    // ========================================


    // ----------------------------------------
    // Private helper methods
    // ----------------------------------------

    // ========================================
    // TODO: Implement calculateDamage. Returns damage values based on ActionType.
    // ========================================
    int calculateDamage(ActionType action);

    // ========================================
    // TODO: Implement resolveActions. Refer to problem description for function behaviour.
    // ========================================
    void resolveActions(ActionType p1Move, ActionType p2Move);

    // ========================================
    // TODO: Implement updateGameState. Refer to problem description for function behaviour
    // ========================================
    void updateGameState();

public:
    // Constructor: Sets 2 players' names and set game status to PLAYING. Implementation is given.
    BattleGame(std::string p1Name, std::string p2Name);
    
    // ========================================
    // TODO: Implement executeTurn
    // ========================================
    // 1. Set blocking state for both players based on their actions
    // 2. Call resolveActions()
    // 3. Call updateGameState()
    void executeTurn(ActionType p1Move, ActionType p2Move);

    // Displays current HP. Implementation is given.
    void displayStatus();

    // ========================================
    // TODO: Returns the current game's state.
    // ========================================
    GameState getGameState();


    // ----------------------------------------
    // Static Methods: 
    // These operate on static data that's shared across all instances.
    // It doesn't belong to any specific BattleGame instance, 
    // nor does it need a specific instance to be called.
    // ----------------------------------------

    // Displays the current game's statistics. Implementation is given.
    static void displayStatistics();

    // ========================================
    // TODO: Returns the total number of games played.
    // ========================================
    static int getTotalGamesPlayed();
    
};

#endif
