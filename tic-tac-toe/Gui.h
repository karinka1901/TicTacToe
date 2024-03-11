#ifndef GUI_H
#define GUI_H

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
//#include <GL/glew.h>
#pragma once
//#include "Database.h"
#include "TicTacToe.h"



class GUI {
public:
    TicTacToe** game;
    Database database;
    GUI(TicTacToe*& game);
    ~GUI();
    char name[100] = "";
    void run();
    void printBoard();
    void renderSettings();
    void renderGameBoardThree();
    void renderGameBoardFive();
    void renderResults();
    //TicTacToe& game;
    GLFWwindow* window;
  //  float color;
    ImVec4 colour;
    bool symbol_selected;
    bool game_mode_selected;
    int game_mode;
    bool color_selected ;
    bool game_over;
    void reset();
    bool first_move;
    bool name_entered;
    void renderPlayerDataText();
    void player_turns();

    // Additional ImGui-related variables or methods as needed
};
#endif // GUI_H