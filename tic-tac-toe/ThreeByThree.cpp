#include <ostream>
#include <iostream>
#include "ThreeByThree.h"

using namespace std;

ThreeByThree::ThreeByThree() : TicTacToe(3) {}

void ThreeByThree::symbol_select()
{
    TicTacToe::symbol_select();
}

void ThreeByThree::switch_player() {

    TicTacToe::switch_player();
}


bool ThreeByThree::can_move() {
    return TicTacToe::can_move();
}

pair<char, vector<pair<int, int>>> ThreeByThree::check_win() {
        char winner = '\0';
        free_cell = 0;
        std::vector<std::pair<int, int>> winning_cells;
    
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    free_cell++;
                }
            }
        }
    
        // ROWS
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == ai && board[i][1] == ai && board[i][2] == ai ) {
                winner = ai;
                winning_cells = { {i, 0}, {i, 1}, {i, 2} };
            }
            else if (board[i][0] == human && board[i][1] == human && board[i][2] == human ) {
                winner = human;
                winning_cells = { {i, 0}, {i, 1}, {i, 2} };
            }

        }
    
        // COLUMNS
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] == ai && board[1][j] == ai && board[2][j] == ai ) {
                winner = ai;
                winning_cells = { {0, j}, {1, j}, {2,j} };
            }
            else if (board[0][j] == human && board[1][j] == human && board[2][j] == human ) {
                winner = human;
                winning_cells = { {0, j}, {1, j}, {2,j} };
            }
        }
    
        // DIAGONALS
        if ((board[0][0] == ai && board[1][1] == ai && board[2][2] == ai ) 
           ) {
            winner = ai;
            winning_cells = { {0, 0}, {1, 1}, {2, 2} };
        }
        else if(board[0][2] == ai && board[1][1] == ai && board[2][0] == ai)
        {
            winner = ai;
        	winning_cells = { {0, 2}, {1, 1}, {2, 0} };
        }
        else if (board[0][0] == human && board[1][1] == human && board[2][2] == human )
          {
            winner = human;
            winning_cells = { {0, 0}, {1, 1}, {2, 2} };
            
        }
        else if (board[0][2] == human && board[1][1] == human && board[2][0] == human)
        {
            winner = human;
            winning_cells = { {0, 2}, {1, 1}, {2, 0} };
        }
    
        // Tie
        if (winner == '\0' && free_cell == 0) {
            winner = 'T';
        }
    
        return { winner, winning_cells };
    }


void ThreeByThree::human_move(int row, int col)
{
    TicTacToe::human_move(row, col);
}

int ThreeByThree::check_score(const std::vector<std::vector<char>>& board) {
    return TicTacToe::check_score(board);
}

bool ThreeByThree::return_winner()
{
		return TicTacToe::return_winner();
}


int ThreeByThree::minimax(vector<vector<char>>& board, int depth, bool isMaximizing)
{
    int score = 0;
    char winner = check_win().first;
    if (winner != '\0') {
        if (winner == ai) {
            score = 1;
        }
        else if (winner == human) {
            score = -1;
        }
        else { // game is a tie
            score = 0;
        }
        return score * 10 + depth; // give higher scores to states closer to the root
    }
    if (depth >= 5 || winner != '\0') {
        return check_score(board);
    }

    if (isMaximizing) { // AI is doing the action
        int bestScore = INT_MIN; // Initialize bestScore to a very low value
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    //cout << "thinking ";
                    board[i][j] = ai; // Make a move
                    score = minimax(board, depth + 1, false); // Call minimax recursively with increased depth and opposite player
                    board[i][j] = ' '; // Undo the move
                    if (score > bestScore) bestScore = score; // Update bestScore if needed
                }
            }
        }
        return bestScore; // Return the best score
    }
    else { // Human is doing the action
        int bestScore = INT_MAX; // Initialize bestScore to a very high value
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = human; // Make a move
                    score = minimax(board, depth + 1, true); // Call minimax recursively with increased depth and opposite player
                    board[i][j] = ' '; // Undo the move
                    if (score < bestScore) {
                        bestScore = score; // Update bestScore if needed
                    }
                }
            }
        }
        return bestScore; // Return the best score
    }
}
void ThreeByThree::ai_move()
{
    pair<int, int> bestMove = { -1, -1 };
    int bestScore = INT_MIN; // Initialize bestScore to a very low value
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
               // std::cout << "AI considering move at (" << i << ", " << j << "). ";
                board[i][j] = ai;
                int score = minimax(board, 0, false); // Pass depth as 0 for the first call
                board[i][j] = ' '; // Undo the move

                if (score > bestScore) {
                    bestScore = score;

                    bestMove = { i, j };
                }
            }
        }
    }
     // Make the best move
    board[bestMove.first][bestMove.second] = ai;
  //  std::cout << "AI chose move at (" << bestMove.first << ", " << bestMove.second << ")." << std::endl;
  
}

void ThreeByThree::reset()
{
		TicTacToe::reset();
}

