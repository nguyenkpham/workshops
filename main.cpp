#include "GameInterface.h"

int main() {
    // Player names
    std::string p1Name = "Player 1";
    std::string p2Name = "Player 2";
    GameInterface::displayWelcome();
    ActionType move = GameInterface::getPlayerAction("Player 1");
    // TODO: Display welcome message using GameInterface
    

    // TODO: Create outer game loop using while(true)
    // This loop allows playing multiple games
    
        // TODO: Create a new BattleGame object with p1Name and p2Name
        
        
        // TODO: Create inner game loop - continues while game state is PLAYING
        // Hint: while (game.getGameState() == GameState::PLAYING)
        
            // TODO: Get Player 1's action
            // Use GameInterface::getPlayerAction(p1Name)
            
            
            // TODO: Get Player 2's action
            // Use GameInterface::getPlayerAction(p2Name)
            
            
            // TODO: Execute the turn with both players' actions
            // Use game.executeTurn(p1Move, p2Move)
            
            
            // TODO: Display what happened this turn
            // Use GameInterface::displayTurnResult(p1Name, p1Move, p2Name, p2Move)
            
            
            // TODO: Display current HP status
            // Use game.displayStatus()
            
        
        // Game has ended (inner loop exited)
        
        // TODO: Display the winner
        // Use GameInterface::displayWinner() with game state and player names
        
        
        // TODO: Display all-time statistics
        // Use BattleGame::displayStatistics() - notice this is STATIC!
        
        
        // TODO: Ask if player wants to play again
        // If they don't want to play again, break out of the outer loop
        // Hint: if (!GameInterface::askPlayAgain()) { break; }
        
    
    std::cout << "\nThanks for playing!" << std::endl;
    
    return 0;
}