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
    //cout << "Select X or O";
    cin >> human;
    if (human == 'X') {
        ai = 'O';
    }
    else 
    {
        ai = 'X';
        human = 'O';
    }
    current_player = human;
}

void TicTacToe::switch_player() {

    if (current_player == human) {
        current_player = ai;
    }
    else 
    {
        current_player = human;
    }

}


bool TicTacToe::can_move() {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return true; 
            }
        }
    }
    return false; //boar=rd is full
}



void TicTacToe::human_move(int row, int col)
{
    if (row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] == ' ') {
        board[row][col] = human;
        cout << "human " << human << " moves to " << row << ", " << col << endl;
    }
}

int TicTacToe::check_score() {
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

bool TicTacToe::return_winner() 
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
    cout << "Resetting the game......" << endl;
    winner = check_win().first;
    winner = '\0';
    current_player = '\0';  
}

