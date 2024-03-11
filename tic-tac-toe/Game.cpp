#include "FiveByFive.h"
#include "Gui.h"
#include "ThreeByThree.h"

int main() {
    TicTacToe* game = nullptr;
    GUI gui(game);

    // Run the GUI
    gui.run();

    // Cleanup
    delete game;

    return 0;
}



//int main() {
//    TicTacToe game;
//    game.symbol_select();
//
//    while (!game.check_win() && game.can_move()) {
//        // Print the current state of the board
//        for (int i = 0; i < 5; ++i) {
//            for (int j = 0; j < 5; ++j) {
//                std::cout << game.board[i][j];
//                if (j < 4) std::cout << " | ";
//            }
//            std::cout << "\n";
//            if (i < 4) std::cout << "-----------\n";
//        }
//
//        // Make a move based on the current player
//        if (game.current_player == game.human) {
//            int row, col;
//            std::cout << "Enter your move (row and column): ";
//            std::cin >> row >> col;
//            game.human_move(row, col);
//            game.switch_player();
//            std::cout << endl;
//        }
//        else {
//            game.ai_move();
//            // 
//        }
//
//        // Switch to the next player
//    }
//
//    // Print the final state of the board
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            std::cout << game.board[i][j];
//            if (j < 4) std::cout << " | ";
//        }
//        std::cout << "\n";
//        if (i < 4) std::cout << "-----------\n";
//    }
//
//    // Print the result of the game
//    if (game.check_win()) {
//        std::cout << "Player " << game.current_player << " wins!\n";
//    }
//    else {
//        std::cout << "It's a tie!\n";
//    }
//
//    return 0;
////}
//
//
//#include <iostream>
//
//#include "TicTacToe.h"
//using namespace std;
//
//int main() {
//    TicTacToe game;
//    game.symbol_select();
//
//    while (game.check_win() == NULL && game.can_move()) {
//        // Print the current state of the board
//        for (int i = 0; i < 5; ++i) {
//            for (int j = 0; j < 5; ++j) {
//                std::cout << game.board[i][j];
//                if (j < 4) std::cout << " | ";
//            }
//            std::cout << "\n";
//            if (i < 4) std::cout << "---------\n";
//        }
//
//        // Make a move based on the current player
//        if (game.current_player == game.human) {
//            int row, col;
//            std::cout << "Player " << game.check_win() << std::endl;
//            std::cout << "Enter your move (row and column): ";
//            std::cin >> row >> col;
//            game.human_move(row, col);
//            game.switch_player();
//            std::cout << std::endl;
//        }
//        else {
//            game.ai_move();
//            game.switch_player();
//        }
//    }
//
//    // Print the final state of the board
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            std::cout << game.board[i][j];
//            if (j < 4) std::cout << " | ";
//        }
//        std::cout << "\n";
//        if (i < 4) std::cout << "---------\n";
//    }
//
//    // Print the result of the game
//    if (game.check_win() == game.human) {
//        std::cout << "Player " << game.human << " wins!\n";
//    }
//    else if (game.check_win() == game.ai) {
//        std::cout << "Player " << game.ai << " wins!\n";
//    }
//    else {
//        std::cout << "It's a tie!\n";
//    }
//
//    return 0;
//}
