#pragma once
#include <vector>
#include <iostream>
#include "Database.h"





class TicTacToe {
public:
	Database database;
    std::vector<std::vector<char>> board;
    char human;
    char ai;
    char current_player;
    char winner;
    int game_mode;

	TicTacToe(int boardSize);
    virtual void symbol_select() = 0;
    virtual void switch_player() = 0;
    virtual bool can_move() = 0;
    //virtual char check_win() = 0;
    virtual std::pair<char, std::vector<std::pair<int, int>>>check_win() = 0;
    virtual int check_score(const std::vector<std::vector<char>>& board) = 0;
    virtual bool return_winner() = 0;
    virtual void human_move(int row, int col) = 0;
    virtual void ai_move() = 0;
    virtual void reset() = 0;
    virtual ~TicTacToe() = default;
    virtual int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizing) = 0;
    static TicTacToe* createGame(int game_mode);
    int free_cell = 0;

};