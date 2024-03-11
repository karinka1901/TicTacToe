
#include <vector>
#include <ctime>
#pragma once

#include "TicTacToe.h"

class FiveByFive : public TicTacToe {
public:
    FiveByFive(); // Constructor
    virtual void symbol_select() override;
    virtual void switch_player() override;
    virtual bool can_move() override;
    //virtual char check_win() override;
    virtual std::pair<char, std::vector<std::pair<int, int>>>check_win() override;
    virtual int check_score(const std::vector<std::vector<char>>& board) override;
    virtual void human_move(int row, int col) override;
    virtual void ai_move() override;
    int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing);
    bool return_winner() override;
    void reset() override;
};