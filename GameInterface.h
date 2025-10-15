#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "BattleGame.h"


// ========================================
// TODO: Convert this class into a Utility class.
// ========================================

/**
 * Utility class that does the I/O operations for main game status / stats.
 */
class GameInterface {
public:
    static void displayWelcome();
    static void displayMenu();
    static ActionType getPlayerAction(std::string playerName);
    static void displayTurnResult(std::string p1Name, ActionType p1Move, std::string p2Name, ActionType p2Move);
    static void displayWinner(GameState state, std::string p1Name, std::string p2Name);
    static bool askPlayAgain();
    
private:
    static std::string actionTypeToString(ActionType action);
};

#endif
