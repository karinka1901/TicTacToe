#pragma once
#include <vector>
#include <iostream>
#include "Database.h"
#include "Gui.h"
using  namespace std;

class TicTacToe {
public:
	Database database;
    vector<vector<char>> board;
    char human;
    char ai;
    char current_player;
    char winner;
    int game_mode;
	int free_cell = 0; 


	TicTacToe(int boardSize);
	static TicTacToe* create_game(int game_mode);

    virtual void symbol_select() = 0;
    virtual void switch_player() = 0;
    virtual bool can_move() = 0;
    virtual pair<char, vector<pair<int, int>>>check_win() = 0; //charv winner and int,int winning cells for the gui
    virtual int check_score() = 0;
    virtual bool return_winner() = 0;
    virtual void human_move(int row, int col) = 0;
    virtual void ai_move() = 0;
    virtual void reset() = 0;

    
    

};