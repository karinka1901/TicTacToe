///*
// - timer
// - ai
// -database:
//	-save player data:
//		-wins, losses, draws
//		-time per each game
//		-total games played
//		-total time played
// 
// */
//#include <imgui.h>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//class TicTacToe {
//public:
//    vector<vector<char>> board;
//    char human;
//    char ai;
//    char current_player;
//
//    TicTacToe();
//    void human_move(int row, int col);
//    void ai_move();
//    void symbol_select();
//    void switch_player();
//    void starting_player();
//    bool check_win();
//    bool can_move();
//    int win(const std::vector<std::vector<char>>& board);
//    int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing);
//
//
//
//};
//
//
//TicTacToe::TicTacToe() : board(5, vector<char>(5, ' ')), human('X') {};
//
//
//void TicTacToe::starting_player() {
//    // Randomly determine the starting player
//    int random_number = rand() % 2 + 1;  // Generates a random number 1 or 2
//
//    if (random_number == 1) {
//        current_player = human;
//        cout << "Human player starts!" << endl;
//    }
//    else {
//        current_player = ai;
//        cout << "AI starts!" << endl;
//    }
//}
//void TicTacToe::symbol_select()
//{
//    cout << "Select X or O";
//    cin >> human;
//    ai = human == 'X' ? 'O' : 'X';
//
//    starting_player();
//}
//
//void TicTacToe::switch_player() {
//
//    current_player = (current_player == human) ? ai : human;
//}
//
//
//bool TicTacToe::check_win()
//{
//    // ROWS
//    for (int i = 0; i < 5; ++i) {
//        if (board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player && board[i][3] == current_player && board[i][4] == current_player) {
//            return true;
//        }
//    }
//
//    // COLUMNS
//    for (int j = 0; j < 5; ++j) {
//        if (board[0][j] == current_player && board[1][j] == current_player && board[2][j] == current_player && board[3][j] == current_player && board[4][j] == current_player) {
//            return true;
//        }
//    }
//
//    // DIAGONALS
//    if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player && board[3][3] == current_player && board[4][4] == current_player) {
//        return true;
//    }
//
//    if (board[0][4] == current_player && board[1][3] == current_player && board[2][2] == current_player && board[3][1] == current_player && board[4][0] == current_player) {
//        return true;
//    }
//
//    return false;
//}
//
//
//bool TicTacToe::can_move()
//{
//    for (const auto& row : board) {
//        for (char cell : row) {
//            if (cell != ' ') {
//                return true; // There is at least one non-empty cell
//            }
//        }
//    }
//    return false; // The board is empty, and it's the first human_move
//
//}
//
//
//int TicTacToe::win(const vector<vector<char>>& board) {
//    if (check_win())
//    {
//        return 1; // win
//    }
//    if(!check_win())
//    {
//    	return -1; // loss
//	}
//    else if (!can_move() && !check_win())
//    {
//        return 0; // tie
//    }
//}
//
//
//void TicTacToe::human_move(int row, int col)
//{
//    if (row >= 0 && row < 5 && col >= 0 && col < 5 && board[row][col] == ' ') {
//        board[row][col] = human;
//    }
//}
//
//void TicTacToe::ai_move() {
//    int bestScore = INT_MIN;
//    pair<int, int> bestMove;
//
//    // Loop through all empty spots on the board and find the best move for AI
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            if (board[i][j] == ' ') {
//                board[i][j] = ai;
//                int score = minimax(board, 0, false);
//                board[i][j] = ' '; // Undo the move
//
//                if (score > bestScore) {
//                    bestScore = score;
//                    bestMove = { i, j };
//                }
//            }
//        }
//    }
//
//    // Make the best move
//    board[bestMove.first][bestMove.second] = ai;
//    switch_player(); // Switch to the human player after the move
//}
//
//int TicTacToe::minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing) {
//    int score = win(board);
//
//    if (score == 1) return score; // AI wins
//    if (score == -1) return score; // Human wins
//    if (!can_move()) return 0; // Tie
//
//    if (isMaximizing) {
//        int best_score = INT_MIN;
//        for (int i = 0; i < 5; ++i) {
//            for (int j = 0; j < 5; ++j) {
//                if (board[i][j] == ' ') {
//                    board[i][j] = ai;
//                    best_score = max(best_score, minimax(board, depth + 1, !isMaximizing));
//                    board[i][j] = ' '; // Undo the move
//                }
//            }
//        }
//        return best_score;
//    }
//    else {
//        int bestScore = INT_MAX;
//        for (int i = 0; i < 5; ++i) {
//            for (int j = 0; j < 5; ++j) {
//                if (board[i][j] == ' ') {
//                    board[i][j] = human;
//                    bestScore = min(bestScore, minimax(board, depth + 1, !isMaximizing));
//                    board[i][j] = ' '; // Undo the move
//                }
//            }
//        }
//        return bestScore;
//    }
//}
//
