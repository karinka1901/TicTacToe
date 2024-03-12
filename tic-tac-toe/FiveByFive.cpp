#include "FiveByFive.h"
#include <ostream>
#include <iostream>

using namespace std;


FiveByFive::FiveByFive() : TicTacToe(5) {}

void FiveByFive::symbol_select()
{
    TicTacToe::symbol_select();
}

void FiveByFive::switch_player() {

    TicTacToe::switch_player();
}

bool FiveByFive::can_move() {
    return TicTacToe::can_move();
}


pair<char, vector<pair<int, int>>> FiveByFive::check_win() {
    char winner = '\0';
    int free_cell = 0;
    vector<pair<int, int>> winning_cells;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == ' ') {
                free_cell++;
            }
        }
    }

    // ROWS
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 2; ++j) {  
            if (board[i][j] == ai && board[i][j + 1] == ai && board[i][j + 2] == ai && board[i][j + 3] == ai) {
                winner = ai;
                winning_cells = { {i, j}, {i, j + 1}, {i, j + 2}, {i, j + 3} };
            }
            else if (board[i][j] == human && board[i][j + 1] == human && board[i][j + 2] == human && board[i][j + 3] == human) {
                winner = human;
                winning_cells = { {i, j}, {i, j + 1}, {i, j + 2}, {i, j + 3} };
            }
        }
    }

    // COLUMNS
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 2; ++i) { 
            if (board[i][j] == ai && board[i + 1][j] == ai && board[i + 2][j] == ai && board[i + 3][j] == ai) {
                winner = ai;
                winning_cells = { {i, j}, {i + 1, j}, {i + 2, j}, {i + 3, j} };
            }
            else if (board[i][j] == human && board[i + 1][j] == human && board[i + 2][j] == human && board[i + 3][j] == human) {
                winner = human;
                winning_cells = { {i, j}, {i + 1, j}, {i + 2, j}, {i + 3, j} };
            }
        }
    }

    //DIAGONALS
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            if ((i + 3 < board.size()) && (j + 3 < board[i].size()) &&
                ((board[i][j] == ai && board[i + 1][j + 1] == ai && board[i + 2][j + 2] == ai && board[i + 3][j + 3] == ai) ||
                    (board[i][j + 3] == ai && board[i + 1][j + 2] == ai && board[i + 2][j + 1] == ai && board[i + 3][j] == ai))) {
                winner = ai;
                winning_cells = { {i, j}, {i + 1, j + 1}, {i + 2, j + 2}, {i + 3, j + 3} };
            }
            else if ((i + 3 < board.size()) && (j + 3 < board[i].size()) &&
                ((board[i][j] == human && board[i + 1][j + 1] == human && board[i + 2][j + 2] == human && board[i + 3][j + 3] == human) ||
                    (board[i][j + 3] == human && board[i + 1][j + 2] == human && board[i + 2][j + 1] == human && board[i + 3][j] == human))) {
                winner = human;
                winning_cells = { {i, j}, {i + 1, j + 1}, {i + 2, j + 2}, {i + 3, j + 3} };
            }
        }
    }


    // Tie
    if (winner == '\0' && free_cell == 0) {
        winner = 'T';
    }

    return { winner, winning_cells };
}



void FiveByFive::human_move(int row, int col)
{
    TicTacToe::human_move(row, col);
}

int FiveByFive::check_score(const std::vector<std::vector<char>>& board) {
    return TicTacToe::check_score(board);
}

bool FiveByFive::return_winner()
{
		return TicTacToe::return_winner();
}


int FiveByFive::minimax(std::vector<std::vector<char>>& board, int depth, int alpha, int beta, bool isMaximizing)
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
        else {
            score = 0;
        }
        return score * 10 + depth;
    }

    if (depth == 5) {
        return 0;
    }

    if (isMaximizing) {
        int best_score = INT_MIN;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = ai;
                    score = minimax(board, depth + 1, alpha, beta, false);
                    board[i][j] = ' ';
                    best_score = std::max(best_score, score);
                    alpha = std::max(alpha, best_score);

                    if (beta <= alpha) {
                        break; // Beta cut-off
                    }
                }
            }
        }
        return best_score;
    }
    else {
        int best_score = INT_MAX;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = human;
                    score = minimax(board, depth + 1, alpha, beta, true);
                    board[i][j] = ' ';
                    best_score = std::min(best_score, score);
                    beta = std::min(beta, best_score);

                    if (beta <= alpha) {
                        break; // Alpha cut-off
                    }
                }
            }
        }
        return best_score;
    }
}


bool FiveByFive::compare_moves(const pair<int, int>& a, const pair<int, int>& b) {
    int center = 2; 
    return -(abs(a.first - center) + abs(a.second - center)) > -(abs(b.first - center) + abs(b.second - center));
}


void FiveByFive::ai_move() {
    pair<int, int> best_move = { -1, -1 };
    int best_score = INT_MIN;

	//vector of all possible moves
    vector<pair<int, int>> moves;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == ' ') {
                moves.push_back({ i, j });
            }
        }
    }
    std::sort(moves.begin(), moves.end(), compare_moves);



    // Evaluate each move using the sorted list of moves
    for (const auto& move : moves) {
        int i = move.first;
        int j = move.second;
        board[i][j] = ai;
        int score = minimax(board, 0, INT_MIN, INT_MAX, false);
        board[i][j] = ' ';
        if (score > best_score) {
            best_score = score;
            best_move = move;
        }
    }

    // Make the best move
    board[best_move.first][best_move.second] = ai;
    std::cout << "AI chose move at (" << best_move.first << ", " << best_move.second << ")." << std::endl;
}

 void FiveByFive::reset()
{
	TicTacToe::reset();
}

