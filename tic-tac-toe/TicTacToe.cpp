#include <ostream>
#include <iostream>
#include <cstdlib>  
#include "TicTacToe.h"
#include "FiveByFive.h"
#include "ThreeByThree.h"


using namespace std;

TicTacToe::TicTacToe(int boardSize) : board(boardSize, vector<char>(boardSize, ' ')), human(' '), ai(' ') {}

TicTacToe* TicTacToe::create_game(int game_mode) {
    if (game_mode == 3) {
        return new ThreeByThree();
    }
    else if (game_mode == 5) {
        return new FiveByFive();
    }
    else {
        return nullptr; 
    }
}

void TicTacToe::symbol_select()
{
    cout << "Select X or O";
    cin >> human;
    ai = human == 'X' ? 'O' : 'X';

    current_player = human;


}

void TicTacToe::switch_player() {

    current_player = (current_player == human) ? ai : human;
}


bool TicTacToe::can_move() {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return true; //board is not full
            }
        }
    }
    return false; //boar=rd is full
}



void TicTacToe::human_move(int row, int col)
{
    if (row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] == ' ') {
        board[row][col] = human;
        std::cout << "Player " << human << " moves to " << row << ", " << col << std::endl;
    }
}

int TicTacToe::check_score(const std::vector<std::vector<char>>& board) {
    char winner = check_win().first;

   //AI won
    if (winner == ai) {
        return 1;
    }
    //human won
    if (winner == human) {
        return -1;
    }
    //tie
    if (!can_move()) {
        return 0;
    }

    return 0;
}

bool TicTacToe::return_winner() // not needed
{
    if (winner == human) 
    {
        return true;
    }
    else
    {
	    return false;
    }

}

void TicTacToe::reset()
{
    cout << "Resetting the game" << endl;
    winner = check_win().first;
    current_player = '\0';  
    winner = '\0';
    
}

