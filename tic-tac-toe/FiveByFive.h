#pragma once

#include "TicTacToe.h"

class FiveByFive : public TicTacToe {
public:

    FiveByFive();
    void symbol_select() override;
    void switch_player() override;
    bool can_move() override;
    pair<char, vector<pair<int, int>>>check_win() override;
    int check_score(const vector<vector<char>>& board) override;
    void human_move(int row, int col) override;
    void ai_move() override;
    int minimax(vector<vector<char>>& board, int depth, int alpha, int beta, bool isMaximizing);
    bool return_winner() override;
    void reset() override;
    static bool compare_moves(const pair<int, int>& a, const pair<int, int>& b);
};