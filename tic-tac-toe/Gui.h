#ifndef GUI_H
#define GUI_H
#pragma once
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <imgui.h>
#include <GLFW/glfw3.h>
#include "TicTacToe.h"

using namespace std;


class GUI {
public:
    TicTacToe** game;
    Database database;
    GUI(TicTacToe*& game);
    ~GUI();
    GLFWwindow* window;
    ImVec4 colour;

	char name[100] = "";
    void run();
	bool symbol_selected;
    bool game_mode_selected;
    int game_mode;
    bool color_selected;
    bool game_over;
	bool first_move;
    bool name_entered;
	string output_text;

    void render_settings();
    void render_game_board_three();
    void render_game_board_five();
    void render_results();
    void reset();
    void player_turns();
    void play_again();
    void display_data();
    void exit_game();
    void render_output(const string& text);
    
};
#endif  GUI_H