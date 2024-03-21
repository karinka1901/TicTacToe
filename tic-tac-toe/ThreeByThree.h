#pragma once
#include <vector>

#include "TicTacToe.h"
using namespace std;


class ThreeByThree : public TicTacToe {
public:

    ThreeByThree();
    virtual void symbol_select() override;
    virtual void switch_player() override;
    virtual bool can_move() override;
    virtual pair<char, vector<pair<int, int>>>check_win() override;
    virtual int check_score() override;
    virtual void human_move(int row, int col) override;
    virtual void ai_move() override;
    int minimax(vector<vector<char>>& board, int depth, bool isMaximizing);
    virtual void reset() override;
    virtual bool return_winner() override;
};