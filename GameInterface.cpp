// ========================================
// THIS FILE CONTAINS ALREADY IMPLEMENTED METODS FOR THE GAMEINTERFACE CLASS.
// PLEASE DO NOT MODIFY THIS FILE.
// ========================================


#include "GameInterface.h"

void GameInterface::displayWelcome() {
        std::cout << "\n======================================" << std::endl;
        std::cout << "    WELCOME TO BATTLE SIMULATOR" << std::endl;
        std::cout << "======================================\n" << std::endl;
        std::cout << "Rules:" << std::endl;
        std::cout << "- Each player starts with 100 HP" << std::endl;
        std::cout << "- Light Attack: 15 damage" << std::endl;
        std::cout << "- Heavy Attack: 30 damage" << std::endl;
        std::cout << "- Block: Reduces next attack by 50%" << std::endl;
        std::cout << "- First player to reach 0 HP loses!\n" << std::endl;
    }
    

void GameInterface::displayMenu() {
    std::cout << "\nChoose your action:" << std::endl;
    std::cout << "1. Light Attack (15 damage)" << std::endl;
    std::cout << "2. Heavy Attack (30 damage)" << std::endl;
    std::cout << "3. Block (50% damage reduction)" << std::endl;
    std::cout << "Enter choice (1-3): ";
}
    
ActionType GameInterface::getPlayerAction(std::string playerName) {
    std::cout << "\n" << playerName << "'s turn" << std::endl;
    displayMenu();
    
    int choice;
    std::cin >> choice;
    
    while (choice < 1 || choice > 3) {
        std::cout << "Invalid choice! Please enter 1-3: ";
        std::cin >> choice;
    }
    
    switch (choice) {
        case 1:
            return ActionType::LIGHTATTACK;
        case 2:
            return ActionType::HEAVYATTACK;
        case 3:
            return ActionType::BLOCK;
        default:
            return ActionType::BLOCK;
    }
}


void GameInterface::displayTurnResult(std::string p1Name, ActionType p1Action, std::string p2Name, ActionType p2Action) {
    std::cout << "\n--- Turn Result ---" << std::endl;
    std::cout << p1Name << " used: " << actionTypeToString(p1Action) << std::endl;
    std::cout << p2Name << " used: " << actionTypeToString(p2Action) << std::endl;
    std::cout << "-------------------" << std::endl;
}


void GameInterface::displayWinner(GameState state, std::string p1Name, std::string p2Name) {
    std::cout << "\n======================================" << std::endl;
    std::cout << "           GAME OVER!" << std::endl;
    std::cout << "======================================" << std::endl;
    
    switch (state) {
        case GameState::PLAYER1_WON:
            std::cout << p1Name << " WINS!" << std::endl;
            break;
        case GameState::PLAYER2_WON:
            std::cout << p2Name << " WINS!" << std::endl;
            break;
        case GameState::DRAW:
            std::cout << "IT'S A DRAW!" << std::endl;
            break;
        default:
            break;
    }
    std::cout << "======================================\n" << std::endl;
}


bool GameInterface::askPlayAgain() {
    std::cout << "Play again? (y/n): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}


/**
 * Default is Block
 */
std::string GameInterface::actionTypeToString(ActionType action) {
    switch (action) {
        case ActionType::LIGHTATTACK:
            return "Light Attack";
        case ActionType::HEAVYATTACK:
            return "Heavy Attack";
        case ActionType::BLOCK:
            return "Block";
        default:
            return "Block";
    }
}