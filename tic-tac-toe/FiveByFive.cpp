#include "FiveByFive.h"

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

void FiveByFive::human_move(int row, int col)
{
    TicTacToe::human_move(row, col);
}

int FiveByFive::check_score() {
    return TicTacToe::check_score();
}

bool FiveByFive::return_winner()
{
    return TicTacToe::return_winner();
}

//////////winnig conditions
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
        for (int j = 0; j < 5; ++j) {
            if ((j + 3 < board[i].size())) {
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
    }
    ////COLUMNS
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 5; ++i) {
            if ((i + 3 < board[i].size())) {
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
    }
    ////DIAGONALS
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            if ((i + 3 < board.size()) && (j + 3 < board[i].size())) { //has to fit in the board
                if ((board[i][j] == ai && board[i + 1][j + 1] == ai && board[i + 2][j + 2] == ai && board[i + 3][j + 3] == ai))//top left->bottom right
                {
                    winner = ai;
                    winning_cells = { {i, j}, {i + 1, j + 1}, {i + 2, j + 2}, {i + 3, j + 3} };
                }
                else if((board[i][j + 3] == ai && board[i + 1][j + 2] == ai && board[i + 2][j + 1] == ai && board[i + 3][j] == ai))  //top right->bottom left))
                {
                	winner = ai;
                	winning_cells = { {i, j+3}, {i + 1, j + 2}, {i + 2, j + 1}, {i + 3, j} };
                }

                else if ((board[i][j] == human && board[i + 1][j + 1] == human && board[i + 2][j + 2] == human && board[i + 3][j + 3] == human)) {
                    winner = human;
                    winning_cells = { {i, j}, {i + 1, j + 1}, {i + 2, j + 2}, {i + 3, j + 3} };
                }
                else if (board[i][j + 3] == human && board[i + 1][j + 2] == human && board[i + 2][j + 1] == human && board[i + 3][j] == human) {
                    winner = human;
                    winning_cells = { {i, j + 3}, {i + 1, j + 2}, {i + 2, j + 1}, {i + 3, j} };
                }
            }
        }
    }
    //////Tie
    if (winner == '\0' && free_cell == 0) {
        winner = 'T';
    }

    return { winner, winning_cells };
}

/////////////minmax with alpha beta pruning
int FiveByFive::minimax(vector<vector<char>>& board, int depth, int alpha, int beta, bool isMaximizing)
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

    if (depth == 5) { //5 moves ahead
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
                    best_score = max(best_score, score);
                    alpha = max(alpha, best_score);

                    if (beta <= alpha) {
                        break; 
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
                    best_score = min(best_score, score);
                    beta = min(beta, best_score);

                    if (beta <= alpha) {
                        break; 
                    }
                }
            }
        }
        return best_score;
    }
}


bool FiveByFive::compare_moves(const pair<int, int> &move1, const pair<int, int> &move2) { // priotorising the moves in the center
    int center = 2;
    int distance1 = abs(move1.first - center) + abs(move1.second - center);
    int distance2 = abs(move2.first - center) + abs(move2.second - center);

    if(distance1 < distance2)
    {
        return true;
	}
    else
    {
        return false;
    }

}

void FiveByFive::ai_move() {
    pair<int, int> best_move = { -1, -1 };
    int best_score = INT_MIN;

    vector<pair<int, int>> all_moves;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == ' ') {
                all_moves.push_back({ i, j });
            }
        }
    }
    sort(all_moves.begin(), all_moves.end(), compare_moves); //sorting moves based on priority

    for (const auto& move : all_moves) {
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
    board[best_move.first][best_move.second] = ai;
}

 void FiveByFive::reset()
{
	TicTacToe::reset();
}

