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
std::pair<char, std::vector<std::pair<int, int>>> FiveByFive::check_win() {
    char winner = '\0';
    int free_cell = 0;
    std::vector<std::pair<int, int>> winning_cells;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == ' ') {
                free_cell++;
            }
        }
    }

    // ROWS
    for (int i = 0; i < 5; ++i) {
        if (board[i][0] == ai && board[i][1] == ai && board[i][2] == ai && board[i][3] == ai && board[i][4] == ai) {
            winner = ai;
            winning_cells = { {i, 0}, {i, 1}, {i, 2}, {i, 3}, {i, 4} };
        }
        else if (board[i][0] == human && board[i][1] == human && board[i][2] == human && board[i][3] == human && board[i][4] == human) {
            winner = human;
            winning_cells = { {i, 0}, {i, 1}, {i, 2}, {i, 3}, {i, 4} };
        }
    }

    // COLUMNS
    for (int j = 0; j < 5; ++j) {
        if (board[0][j] == ai && board[1][j] == ai && board[2][j] == ai && board[3][j] == ai && board[4][j] == ai) {
            winner = ai;
            winning_cells = { {0, j}, {1, j}, {2, j}, {3, j}, {4, j} };
        }
        else if (board[0][j] == human && board[1][j] == human && board[2][j] == human && board[3][j] == human && board[4][j] == human) {
            winner = human;
            winning_cells = { {0, j}, {1, j}, {2, j}, {3, j}, {4, j} };
        }
    }

    // DIAGONALS
    if ((board[0][0] == ai && board[1][1] == ai && board[2][2] == ai && board[3][3] == ai && board[4][4] == ai) ||
        (board[0][4] == ai && board[1][3] == ai && board[2][2] == ai && board[3][1] == ai && board[4][0] == ai)) {
        winner = ai;
        winning_cells = { {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4} };
    }
    else if ((board[0][0] == human && board[1][1] == human && board[2][2] == human && board[3][3] == human && board[4][4] == human) ||
        (board[0][4] == human && board[1][3] == human && board[2][2] == human && board[3][1] == human && board[4][0] == human)) {
        winner = human;
        winning_cells = { {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4} };
    }

    // Tie
    if (winner == '\0' && free_cell == 0) {
        winner = 'T';
    }

    return { winner, winning_cells };
}


//char FiveByFive::check_win() {
//    char winner = '\0';
//    int free_cell = 0;
//
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            if (board[i][j] == ' ') {
//                free_cell++;
//            }
//        }
//    }
//
//    // ROWS
//    for (int i = 0; i < 5; ++i) {
//        if (board[i][0] == ai && board[i][1] == ai && board[i][2] == ai && board[i][3] == ai && board[i][4] == ai) {
//            winner = ai;
//        }
//        else if (board[i][0] == human && board[i][1] == human && board[i][2] == human && board[i][3] == human && board[i][4] == human) {
//            winner = human;
//        }
//    }
//
//    // COLUMNS
//    for (int j = 0; j < 5; ++j) {
//        if (board[0][j] == ai && board[1][j] == ai && board[2][j] == ai && board[3][j] == ai && board[4][j] == ai) {
//            winner = ai;
//        }
//        else if (board[0][j] == human && board[1][j] == human && board[2][j] == human && board[3][j] == human && board[4][j] == human) {
//            winner = human;
//        }
//    }
//
//    // DIAGONALS
//    if ((board[0][0] == ai && board[1][1] == ai && board[2][2] == ai && board[3][3] == ai && board[4][4] == ai) ||
//        (board[0][4] == ai && board[1][3] == ai && board[2][2] == ai && board[3][1] == ai && board[4][0] == ai)) {
//        winner = ai;
//    }
//    else if ((board[0][0] == human && board[1][1] == human && board[2][2] == human && board[3][3] == human && board[4][4] == human) ||
//        (board[0][4] == human && board[1][3] == human && board[2][2] == human && board[3][1] == human && board[4][0] == human)) {
//        winner = human;
//    }
//
//    // Tie
//    if (winner == '\0' && free_cell == 0) {
//        winner = 'T';
//    }
//
//    return winner;
//}


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


//std::unordered_map<std::string, int> transpositionTable;
//
//std::string boardToString(std::vector<std::vector<char>>& board) {
//    std::string boardString;
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            boardString += board[i][j];
//        }
//    }
//    return boardString;
//}

int FiveByFive::minimax(std::vector<std::vector<char>>& board, int depth, int alpha, int beta, bool isMaximizing)
{
    //std::string boardString = boardToString(board);
    //if (transpositionTable.find(boardString) != transpositionTable.end()) {
    //    return transpositionTable[boardString];
    //}

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
        return 0; // Or return a heuristic score
    }

    if (isMaximizing) {
        int bestScore = INT_MIN;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = ai;
                    score = minimax(board, depth + 1, alpha, beta, false);
                    board[i][j] = ' ';
                    bestScore = std::max(bestScore, score);
                    alpha = std::max(alpha, bestScore);

                    if (beta <= alpha) {
                        break; // Beta cut-off
                    }
                }
            }
        }
        //transpositionTable[boardString] = bestScore;
        return bestScore;
    }
    else {
        int bestScore = INT_MAX;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = human;
                    score = minimax(board, depth + 1, alpha, beta, true);
                    board[i][j] = ' ';
                    bestScore = std::min(bestScore, score);
                    beta = std::min(beta, bestScore);

                    if (beta <= alpha) {
                        break; // Alpha cut-off
                    }
                }
            }
        }
        return bestScore;
    }
}

// This is a simple heuristic that favors moves near the center of the board.
int FiveByFive::heuristic(int i, int j) {
    int center = 2; // The index of the center square on a 5x5 board
    return -(abs(i - center) + abs(j - center));
}

bool compareMoves(const pair<int, int>& a, const pair<int, int>& b) {
    int center = 2; // The index of the center square on a 5x5 board
    return -(abs(a.first - center) + abs(a.second - center)) > -(abs(b.first - center) + abs(b.second - center));
}


void FiveByFive::ai_move() {
    pair<int, int> bestMove = { -1, -1 };
    int bestScore = INT_MIN;

    // Create a vector of all possible moves
    std::vector<std::pair<int, int>> moves;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == ' ') {
                moves.push_back({ i, j });
            }
        }
    }

    std::sort(moves.begin(), moves.end(), compareMoves);



    // Evaluate each move using the sorted list of moves
    for (const auto& move : moves) {
        int i = move.first;
        int j = move.second;
        board[i][j] = ai;
        int score = minimax(board, 0, INT_MIN, INT_MAX, false);
        board[i][j] = ' ';
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }

    // Make the best move
    board[bestMove.first][bestMove.second] = ai;
    std::cout << "AI chose move at (" << bestMove.first << ", " << bestMove.second << ")." << std::endl;
}


//void FiveByFive::ai_move()
//{
//    pair<int, int> bestMove = { -1, -1 };
//    int bestScore = INT_MIN; // Initialize bestScore to a very low value
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            if (board[i][j] == ' ') {
//                std::cout << "AI considering moveee at (" << i << ", " << j << "). ";
//                board[i][j] = ai;
//                int score = minimax(board, 0, INT_MIN, INT_MAX, false);
//                // Pass depth as 0 for the first call
//                board[i][j] = ' '; // Undo the move
//
//                if (score > bestScore) {
//                    bestScore = score;
//
//                    bestMove = { i, j };
//                }
//            }
//        }
//    }
//    // Make the best move
//    board[bestMove.first][bestMove.second] = ai;
//    std::cout << "AI chose move at (" << bestMove.first << ", " << bestMove.second << ")." << std::endl;
//
//}
 void FiveByFive::reset()
{
	TicTacToe::reset();
}

