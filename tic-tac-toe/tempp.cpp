
//#define TICTACTOE_H
//
//#include <vector>
//#include <ctime>
//
//class TicTacToe {
//public:
//    std::vector<std::vector<char>> board;
//    char human;
//    char ai;
//    char current_player;
//
//    int scores[5][5] = {
//        {3, 2, 3, 2, 3},
//        {2, 4, 2, 4, 2},
//        {3, 2, 5, 2, 3},
//        {2, 4, 2, 4, 2},
//        {3, 2, 3, 2, 3}
//    };
//
//    int check_score(const std::vector<std::vector<char>>& board);
//    int heuristic(const std::vector<std::vector<char>>& board);
//
//
//    TicTacToe();
//
//    int game_mode;
//    void symbol_select();
//    void switch_player();
//    bool can_move();
//    char check_win();
//    void human_move(int row, int col);
//    int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing);
//    void ai_move();
//    std::pair<int, int> find_best_move(int time_limit);
//    int count_empty_cells(const std::vector<std::vector<char>>& board);
//   // int check_score(const std::vector<std::vector<char>>& board, const std::pair<int, int>& bestMove);
//};
//
//#endif



#include <ostream>
//
//#include "TicTacToe.h"
//
//#include <iostream>
//
//using namespace std;
//
//
//TicTacToe::TicTacToe() : board(5, vector<char>(5, ' ')), human(' ') {};
//
//
//void TicTacToe::symbol_select()
//{
//	cout << "Select X or O";
//    cin >> human;
//    ai = human == 'X' ? 'O' : 'X';
//
//    current_player = human;
//}
//
//void TicTacToe::switch_player() {
//
//    current_player = (current_player == human) ? ai : human;
//}
//
//
//bool TicTacToe::can_move() {
//    for (const auto& row : board) {
//        for (char cell : row) {
//            if (cell == ' ') {
//                return true; // There is at least one empty cell
//            }
//        }
//    }
//    return false; // The board is full, and it's a tie
//}
//
//char TicTacToe::check_win() {
//        char winner = '\0';
//        int free_cell = 0;
//    
//        for (int i = 0; i < 5; ++i) {
//            for (int j = 0; j < 5; ++j) {
//                if (board[i][j] == ' ') {
//                    free_cell++;
//                }
//            }
//        }
//    
//        // ROWS
//        for (int i = 0; i < 5; ++i) {
//            if (board[i][0] == ai && board[i][1] == ai && board[i][2] == ai && board[i][3] == ai && board[i][4] == ai) {
//                winner = ai;
//            }
//            else if (board[i][0] == human && board[i][1] == human && board[i][2] == human && board[i][3] == human && board[i][4] == human) {
//                winner = human;
//            }
//        }
//    
//        // COLUMNS
//        for (int j = 0; j < 5; ++j) {
//            if (board[0][j] == ai && board[1][j] == ai && board[2][j] == ai && board[3][j] == ai && board[4][j] == ai) {
//                winner = ai;
//            }
//            else if (board[0][j] == human && board[1][j] == human && board[2][j] == human && board[3][j] == human && board[4][j] == human) {
//                winner = human;
//            }
//        }
//    
//        // DIAGONALS
//        if ((board[0][0] == ai && board[1][1] == ai && board[2][2] == ai && board[3][3] == ai && board[4][4] == ai) ||
//            (board[0][4] == ai && board[1][3] == ai && board[2][2] == ai && board[3][1] == ai && board[4][0] == ai)) {
//            winner = ai;
//        }
//        else if ((board[0][0] == human && board[1][1] == human && board[2][2] == human && board[3][3] == human && board[4][4] == human) ||
//            (board[0][4] == human && board[1][3] == human && board[2][2] == human && board[3][1] == human && board[4][0] == human)) {
//            winner = human;
//        }
//    
//        // Tie
//        if (winner == '\0' && free_cell == 0) {
//            winner = 'T';
//        }
//    
//        return winner;
//    }
//
//
//void TicTacToe::human_move(int row, int col)
//{
//    if (row >= 0 && row < 5 && col >= 0 && col < 5 && board[row][col] == ' ') {
//        board[row][col] = human;
//    }
//}
//
//int TicTacToe::check_score(const std::vector<std::vector<char>>& board) {
//    char winner = check_win();
//
//    // Check if AI won
//    if (winner == ai) {
//        return 1;
//    }
//    // Check if human won
//    else if (winner == human) {
//        return -1;
//    }
//    // Check if it's a tie
//    else if (!can_move()) {
//        return 0;
//    }
//
//    // If the game is still in progress, return a neutral score
//    return 0;
//}
//
//
//int TicTacToe::minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing)
//{
//    int score = 0;
//    char winner = check_win();
//    if (winner != '\0') {
//        if (winner == ai) {
//            score = 1;
//        }
//        else if (winner == human) {
//            score = -1;
//        }
//        else { // game is a tie
//            score = 0;
//        }
//        return score * 10 + depth; // give higher scores to states closer to the root
//    }
//   /* if (depth >= 5 || winner != '\0') {
//        return check_score(board);
//    }*/
//
//    if (isMaximizing) { // AI is doing the action
//        int bestScore = INT_MIN; // Initialize bestScore to a very low value
//        for (int i = 0; i < 5; i++) {
//            for (int j = 0; j < 5; j++) {
//                if (board[i][j] == ' ') {
//                    board[i][j] = ai; // Make a move
//                    score = minimax(board, depth + 1, false); // Call minimax recursively with increased depth and opposite player
//                    board[i][j] = ' '; // Undo the move
//                    if (score > bestScore) bestScore = score; // Update bestScore if needed
//                }
//            }
//        }
//        return bestScore; // Return the best score
//    }
//    else { // Human is doing the action
//        int bestScore = INT_MAX; // Initialize bestScore to a very high value
//        for (int i = 0; i < 5; i++) {
//            for (int j = 0; j < 5; j++) {
//                if (board[i][j] == ' ') {
//                    board[i][j] = human; // Make a move
//                    score = minimax(board, depth + 1, true); // Call minimax recursively with increased depth and opposite player
//                    board[i][j] = ' '; // Undo the move
//                    if (score < bestScore) {
//                        bestScore = score; // Update bestScore if needed
//                    }
//                }
//            }
//        }
//        return bestScore; // Return the best score
//    }
//}
//void TicTacToe::ai_move()
//{
//    pair<int, int> bestMove = { -1, -1 };
//    int bestScore = INT_MIN; // Initialize bestScore to a very low value
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            if (board[i][j] == ' ') {
//                std::cout << "AI considering move at (" << i << ", " << j << "). ";
//                board[i][j] = ai;
//                int score = minimax(board, 0, false); // Pass depth as 0 for the first call
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
//     // Make the best move
//    board[bestMove.first][bestMove.second] = ai;
//    std::cout << "AI chose move at (" << bestMove.first << ", " << bestMove.second << ")." << std::endl;
//  
//}
//
//
//
////
////
////
////
////
////
////
////#include "TicTacToe.h"
////#include <iostream>
////#include <climits>
////
////TicTacToe::TicTacToe() : board(5, std::vector<char>(5, ' ')), human(' '), current_player(' '), ai(' ') {}
////
////void TicTacToe::symbol_select() {
////    std::cout << "Select X or O: ";
////    std::cin >> human;
////    ai = (human == 'X') ? 'O' : 'X';
////    current_player = human;
////}
////
////void TicTacToe::switch_player() {
////    current_player = (current_player == human) ? ai : human;
////}
////
////bool TicTacToe::can_move() {
////    for (const auto& row : board) {
////        for (char cell : row) {
////            if (cell == ' ') {
////                return true; // There is at least one empty cell
////            }
////        }
////    }
////    return false; // The board is full, and it's a tie
////}
////
////char TicTacToe::check_win() {
////    char winner = '\0';
////    int free_cell = 0;
////
////    for (int i = 0; i < 5; ++i) {
////        for (int j = 0; j < 5; ++j) {
////            if (board[i][j] == ' ') {
////                free_cell++;
////            }
////        }
////    }
////
////    // ROWS
////    for (int i = 0; i < 5; ++i) {
////        if (board[i][0] == ai && board[i][1] == ai && board[i][2] == ai && board[i][3] == ai && board[i][4] == ai) {
////            winner = ai;
////        }
////        else if (board[i][0] == human && board[i][1] == human && board[i][2] == human && board[i][3] == human && board[i][4] == human) {
////            winner = human;
////        }
////    }
////
////    // COLUMNS
////    for (int j = 0; j < 5; ++j) {
////        if (board[0][j] == ai && board[1][j] == ai && board[2][j] == ai && board[3][j] == ai && board[4][j] == ai) {
////            winner = ai;
////        }
////        else if (board[0][j] == human && board[1][j] == human && board[2][j] == human && board[3][j] == human && board[4][j] == human) {
////            winner = human;
////        }
////    }
////
////    // DIAGONALS
////    if ((board[0][0] == ai && board[1][1] == ai && board[2][2] == ai && board[3][3] == ai && board[4][4] == ai) ||
////        (board[0][4] == ai && board[1][3] == ai && board[2][2] == ai && board[3][1] == ai && board[4][0] == ai)) {
////        winner = ai;
////    }
////    else if ((board[0][0] == human && board[1][1] == human && board[2][2] == human && board[3][3] == human && board[4][4] == human) ||
////        (board[0][4] == human && board[1][3] == human && board[2][2] == human && board[3][1] == human && board[4][0] == human)) {
////        winner = human;
////    }
////
////    // Tie
////    if (winner == '\0' && free_cell == 0) {
////        winner = 'T';
////    }
////
////    return winner;
////}
////
////void TicTacToe::human_move(int row, int col) {
////    if (row >= 0 && row < 5 && col >= 0 && col < 5 && board[row][col] == ' ') {
////        board[row][col] = human;
////        std::cout << "Human chose move at (" << row << ", " << col << ")." << std::endl;
////    }
////}
////
////int TicTacToe::check_score(const std::vector<std::vector<char>>& board) {
////    int ai_score = 0;
////    int human_score = 0;
////
////    for (int i = 0; i < 5; i++) {
////        for (int j = 0; j < 5; j++) {
////            if (board[i][j] == ai) {
////                ai_score += scores[i][j]; // Add the score of the cell occupied by the AI
////            }
////            else if (board[i][j] == human) {
////                human_score += scores[i][j]; // Add the score of the cell occupied by the human
////            }
////        }
////    }
////
////    return ai_score - human_score; // Return the difference between the scores
////}
////
////
////int TicTacToe::minimax(std::vector<std::vector<char>>& board, int depth, int alpha, int beta, bool isMaximizingPlayer, int limit) {
////    int score = 0;
////    char winner = check_win();
////
////    if (winner != '\0' || depth == limit) {
////        return check_score(board) - depth;
////    }
////
////    if (isMaximizingPlayer) {
////        int bestScore = INT_MIN;
////        for (int i = 0; i < 5; i++) {
////            for (int j = 0; j < 5; j++) {
////                if (board[i][j] == ' ') {
////                    board[i][j] = ai;
////                    score = minimax(board, depth + 1, alpha, beta, false, limit);
////                    board[i][j] = ' ';
////                    bestScore = std::max(bestScore, score);
////                    alpha = std::max(alpha, bestScore);
////                    if (beta <= alpha) break;
////                }
////            }
////        }
////        return bestScore;
////    }
////    else {
////        int bestScore = INT_MAX;
////        for (int i = 0; i < 5; i++) {
////            for (int j = 0; j < 5; j++) {
////                if (board[i][j] == ' ') {
////                    board[i][j] = human;
////                    score = minimax(board, depth + 1, alpha, beta, true, limit);
////                    board[i][j] = ' ';
////                    bestScore = std::min(bestScore, score);
////                    beta = std::min(beta, bestScore);
////                    if (beta <= alpha) break;
////                }
////            }
////        }
////        return bestScore;
////    }
////}
////
////void TicTacToe::ai_move() {
////    std::pair<int, int> bestMove = { -1, -1 };
////    int bestScore = INT_MIN;
////
////    for (int i = 0; i < 5; ++i) {
////        for (int j = 0; j < 5; ++j) {
////            if (board[i][j] == ' ') {
////                std::cout << "AI considering move at (" << i << ", " << j << "). ";
////                board[i][j] = ai;
////                int score = minimax(board, 0, INT_MIN, INT_MAX, false, 5); // Depth limit set to 5
////                board[i][j] = ' ';
////                if (score > bestScore) {
////                    bestScore = score;
////                    bestMove = { i, j };
////                }
////            }
////        }
////    }
////
////    board[bestMove.first][bestMove.second] = ai;
////    std::cout << "AI chose move at (" << bestMove.first << ", " << bestMove.second << ")." << std::endl;
////}
////
////std::pair<int, int> TicTacToe::find_best_move(int time_limit) {
////    std::pair<int, int> bestMove = { -1, -1 };
////    int bestScore = INT_MIN;
////    int depth = 1;
////    time_t start_time = time(nullptr);
////
////    while (true) {
////        for (int i = 0; i < 5; ++i) {
////            for (int j = 0; j < 5; ++j) {
////                if (board[i][j] == ' ') {
////                    board[i][j] = ai;
////                    int score = minimax(board, 0, INT_MIN, INT_MAX, false, depth);
////                    board[i][j] = ' ';
////                    if (score > bestScore) {
////                        bestScore = score;
////                        bestMove = { i, j };
////                    }
////                }
////            }
////        }
////
////        time_t end_time = time(nullptr);
////        double elapsed_time = difftime(end_time, start_time);
////
////        if (elapsed_time > time_limit) {
////            break;
////        }
////
////        if (bestScore == 1 || bestScore == -1) {
////            break;
////        }
////
////        depth = depth + 1;
////    }
////
////    return bestMove;
////}
//
