#pragma once

#include "TicTacToe.h"

class FiveByFive : public TicTacToe {
public:

    FiveByFive();
    void symbol_select() override;
    void switch_player() override;
    bool can_move() override;
    pair<char, vector<pair<int, int>>>check_win() override;
    int check_score() override;
    void human_move(int row, int col) override;
    void ai_move() override;
    bool return_winner() override;
    void reset() override;

    static bool compare_moves(const pair<int, int>& move1, const pair<int, int>& move2);
	int minimax(vector<vector<char>>& board, int depth, int alpha, int beta, bool isMaximizing);
};