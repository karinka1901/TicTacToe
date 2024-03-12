#include "Gui.h"
#include <iostream>
#include <ostream>


GUI::GUI(TicTacToe*& game) : game(&game), database(), symbol_selected(false), color_selected(false), game_over(false), name_entered(false), first_move(true) {
    if (!glfwInit()) {
        std::exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_TRUE);
    window = glfwCreateWindow(1280, 720, "Tic Tac Toe", NULL, NULL);

    if (!window) {
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    ImGuiIO& io = ImGui::GetIO();

    std::vector<ImFont*> my_fonts;

    ImFont* font1 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\ARIALN.TTF", 25.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    my_fonts.push_back(font1);

    ImFont* font2 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\impact.ttf", 30.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    my_fonts.push_back(font2);

    ImFont* font3 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\impact.ttf", 54.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    my_fonts.push_back(font3);

    ImFont* font4 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\impact.ttf", 90.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    my_fonts.push_back(font4);

    ImFont* font5 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\impact.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
    my_fonts.push_back(font5);

    if (!my_fonts.data()) {
        std::cerr << "Failed to load font file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

  //  database.readPlayerData();
}

GUI::~GUI() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

void GUI::reset()
{
    ImGui::SetNextWindowPos(ImVec2((1920 - 110) * 0.5f, (1080 + 800) * 0.5f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(620, 620), ImGuiCond_Always);
    ImGui::Begin("reset", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);

    ImGuiStyle& style = ImGui::GetStyle();
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[4]);
    //style.ItemSpacing = ImVec2(100.0f, 100.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    ImVec4 buttonColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 borderColor = ImVec4(1.0f, 0.5f, 0.8f, 1.0f);
    ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
    ImGui::PushStyleColor(ImGuiCol_Border, borderColor);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 4.0f);

    // ImGui::SetCursorPos(ImVec2(ImGui::GetWindowContentRegionMax().x - 120, ImGui::GetWindowContentRegionMax().y -500));
    if (ImGui::Button("RESET", ImVec2(100, 30)))
    {
        game_mode = 0;
        symbol_selected = false;
        color_selected = false;
        name_entered = false;
        (*game)->reset();
        name[0] = '\0';
        game_over = false;

    }

    ImGui::PopStyleColor();
    ImGui::PopFont();
    ImGui::PopStyleVar();
    ImGui::PopStyleColor();
    // ImGui::PopStyleColor(2);

    ImGui::End();
    
}

void GUI::renderSettings() {
    ImGuiStyle& style = ImGui::GetStyle();
	 ImGui::SetNextWindowPos(ImVec2((1920 - 360) * 0.5f, (1080 - 1000) * 0.5f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(360, 120), ImGuiCond_Always);
////////////////////////////////TITLE WINDOW////////////////////////////////////////////////
    ImGui::Begin("name", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
    style.WindowBorderSize = 0.0f;
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.0f, 0.5f, 0.8f, 1.0f)); // Pink background
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[3]);
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.5f, 0.8f, 1.0f));
    ImGui::Text("TIC TAC TOE");
    ImGui::PopStyleVar();
    ImGui::PopFont();
    ImGui::PopStyleColor(2);
    ImGui::End();

    ImGui::SetNextWindowSize(ImVec2(500, 900), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2((1920 -1700) * 0.5f, (1080 - 650) * 0.5f), ImGuiCond_Always);
//////////////////////////////////////////////SETTINGS WINDOW/////////////////////////////
    ImGui::Begin("settings", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 4.0f);
    style.ItemSpacing = ImVec2(13.0f, 3.0f);

//////////////////////////NAME////////////////////////
	ImGui::SetNextWindowPos(ImVec2((1920 + 960) * 0.5f, (1080 - 650) * 0.5f), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(500, 100), ImGuiCond_Always);
    ImGui::Begin("name_field", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
	if(!name_entered)
    {
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.0f, 0.0f, 0.0f, 1.0f)); // Black background
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1.0f, 0.5f, 0.8f, 1.0f)); // Pink border

	    ImGui::Text("Enter your name:");
       // ImVec2 inputSize(200, ImGui::GetTextLineHeightWithSpacing());
        if (ImGui::InputText("##name", name, sizeof(name), ImGuiInputTextFlags_EnterReturnsTrue)) {

            name_entered = true;
            std::cout<< "Name entered: " << name;
        }
        ImGui::PopStyleColor(2);
    }
    if(name_entered)
    {
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.5f, 0.8f, 1.0f));
			ImGui::Text(" ");
    		ImGui::Text("CURRENT PLAYER: %s", name);
            ImGui::PopStyleColor();
	    }
    ImGui::End();

    //W:# L:# T:# 

////////////////MODE SELECTION////////////////////////
    if (game_mode == 0) { // game mode not selected yet
        ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
        ImGui::Text("Select the game mode:");
        ImGui::PopFont();
        style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
        ImVec4 buttonColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
        ImVec4 borderColor = ImVec4(1.0f, 0.5f, 0.8f, 1.0f);

        ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
        ImGui::PushStyleColor(ImGuiCol_Border, borderColor);
        ImGui::Spacing();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 65.0f);
        if (ImGui::Button("3x3", ImVec2(100, 100))) {
            colour = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
            game_mode = 3;
            *game = TicTacToe::createGame(3);
            symbol_selected = false;

        }
        ImGui::SameLine(NULL, 30);
         // Keep the next button on the same line
        //ImGui::Dummy(ImVec2(1, 0)); // Add 10 units of horizontal space

        if (ImGui::Button("5x5", ImVec2(100, 100))) {
            colour = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
            game_mode = 5;
            *game = TicTacToe::createGame(5);
            symbol_selected = false;
        }

        ImGui::PopStyleColor(2);
    }

    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    ImVec4 buttonColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 borderColor = ImVec4(1.0f, 0.5f, 0.8f, 1.0f);
    ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
    ImGui::PushStyleColor(ImGuiCol_Border, borderColor);

/////////////////SYMBOL SELECTION////////////////////////
    if (!symbol_selected && game_mode != 0) {
        ImGui::Text("Select your symbol:");

        ImGui::Spacing();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 65.0f);

        if (ImGui::Button("X", ImVec2(100, 100))) {
            colour = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
            (*game)->human = 'X';
            (*game)->ai = 'O';
            (*game)->current_player = (*game)->human;
            symbol_selected = true;
        }

        ImGui::SameLine(NULL,30);

        if (ImGui::Button("O", ImVec2(100, 100))) {
            colour = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
            (*game)->human = 'O';
            (*game)->ai = 'X';
            (*game)->current_player = (*game)->human;
            symbol_selected = true;
        }

        //if (symbol_selected) {
        //    // Initialize random seed
        //    srand(time(0));

        //    // Generate a random number: 0 or 1
        //    int random_start = rand() % 2;

        //    // Decide who starts first based on the random number
        //    if (random_start == 0) {
        //        (*game)->current_player = (*game)->human;
        //        std::cout << "You start first!";
        //        ImGui::Text("You start first!");
        //    }
        //    else {
        //        (*game)->current_player = (*game)->ai;
        //       
        //        ImGui::Text("AI starts first!");
        //    }
        //    std::cout << (*game)->current_player << std::endl;
      
        //}
    }
    ImGui::PopStyleColor(2);
    ImGui::PopFont();

//////////////////////////////COLOR SELECTION////////////////////////   
    if (symbol_selected && !color_selected ) {
        ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
        ImGui::Text("Select the color:");
        ImGui::PopFont();

        if (ImGui::ColorPicker4("Symbol Color", reinterpret_cast<float*>(&colour))) {
            true;
        }

        style.Colors[ImGuiCol_Button] = colour;
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
        ImVec4 buttonColor = colour;
        ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);

        if (ImGui::Button("CHOOSE", ImVec2(325, 50))) {
            color_selected = true;

        }
        ImGui::PopStyleColor();
    }
    //player_turns();
  //  if(color_selected && ((*game)->current_player == (*game)->ai))
  //  {
  //  	(*game)->ai_move();
  //      first_move = false;
		//(*game)->switch_player();
  //      
  //  }


    ImGui::PopStyleColor();
    ImGui::PopStyleVar();
    ImGui::End();
}

void GUI::player_turns()
{
    ImGui::SetNextWindowPos(ImVec2((1920 - 360) * 0.5f, (1080 - 1000) * 0.5f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(360, 120), ImGuiCond_Always);

    ImGui::Begin("turn", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
    ImGui::SetWindowPos(ImVec2(0, 0), 1); // Set a higher z-order
    if (first_move)
    {
        if ((*game)->current_player == (*game)->human)
        {
            ImGui::Text("You start first!");
        }
        else if ((*game)->current_player == (*game)->ai)
        {
            ImGui::Text("AI starts first!");
        }
    }
    ImGui::End();
}


///////////////////////////////////////////////////////////3X3 GAME////////////////////////////////////////
void GUI::renderGameBoardThree() {
    ImGuiStyle& style = ImGui::GetStyle();
    ImGui::SetNextWindowPos(ImVec2((1920 - 620) * 0.5f, (1080 - 620) * 0.5f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(620, 620), ImGuiCond_Always);

///////////////////////////////////////GAME WINDOW////////////////
    ImGui::Begin("game", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::SetWindowFontScale(2.5f);

    char winner = (*game)->check_win().first;
    std::vector<std::pair<int, int>> winning_cells = (*game)->check_win().second;
    ImVec4 winner_line = ImVec4(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, 1.0f);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ImGui::PushID(3 * i + j);

            ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
            style.ItemSpacing = ImVec2(0.0f, 0.0f);
            style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
            ImVec4 buttonColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
            ImVec4 borderColor = ImVec4(1.0f, 0.5f, 0.8f, 1.0f);
            ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
            ImGui::PushStyleColor(ImGuiCol_Border, borderColor);
            ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 4.0f);

            char label[2] = { (*game)->board[i][j], '\0' };

            ///PLAYERS COLORS//////////////////
            if (winner != '\0' && std::find(winning_cells.begin(), winning_cells.end(), std::make_pair(i, j)) != winning_cells.end())
            {
                ImGui::PushStyleColor(ImGuiCol_Text, winner_line); // animated color for the winning line
                game_over = true;

            }
            else if (winner == 'T')
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.5f, 0.5f, 0.5f, 0.5f)); // Tie color grey
                game_over = true;
            }
            else if ((*game)->board[i][j] == (*game)->human) {
                ImGui::PushStyleColor(ImGuiCol_Text, colour); // human color
            }
            else if ((*game)->board[i][j] == (*game)->ai) {

                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.5f, 0.8f, 1.0f)); //AI color
            }
            else
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f)); // base color
            }

            ////////////////BUTTONS IN THE GAMEBORAD////////////////////////
            if (ImGui::Button(label, ImVec2(200, 200))) {

                if ((*game)->current_player == (*game)->human && (*game)->can_move() && winner == '\0') {
                    (*game)->human_move(i, j);
                    (*game)->switch_player();

                    if (winner == '\0' && (*game)->can_move()) {
                        (*game)->ai_move();
                        (*game)->switch_player();
                    }
                    winner = (*game)->check_win().first;
                    winning_cells = (*game)->check_win().second;
                    if (winner != '\0') {
                        for (const auto& cell : winning_cells) {
                            std::cout << "(" << cell.first << ", " << cell.second << ") ";
                        }
                        std::cout << std::endl;
                    }
                    first_move = false;
                }
            }
            ImGui::PopStyleColor(); 
            ImGui::PopFont();
            ImGui::PopStyleVar();
            ImGui::PopStyleColor(2);
            ImGui::PopID();

            if (j < 2) ImGui::SameLine();
        }
    }
    ImGui::PopStyleColor();
    ImGui::End();
}
    
///////////////////////////////////////////////////////RESULT WINDOW////////////////////////////////////////////////////////////////
void GUI::renderResults(){
    ImGui::Begin("result", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowBorderSize = 0.0f;
   // ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);

    char winner = (*game)->check_win().first;
    std::string winner_person;

    if(winner == (*game)->human)
    {
    	winner_person = "You";

    }
    else if(winner == (*game)->ai)
    {
    	winner_person = "AI";
	}
 
    if (winner == 'X' || winner == 'O')
    {
        ImGui::Text("%s, won!", winner_person.c_str());
        play_again();

    }
    else if (winner == 'T')
    {
        ImGui::Text("It's a tie!");
        play_again();
    }
    else
    {
	    ImGui::Text(" ");
    }
    ImGui::PopFont();
   // ImGui::PopStyleVar();
    ImGui::End();
}

void GUI::play_again()
{
	ImGui::SetNextWindowPos(ImVec2((1920 - 1700) * 0.5f, (1080 - 650) * 0.5f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(500, 600), ImGuiCond_Always);
    //////////////////////////
	ImGui::Begin("replay", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 30.0f);
    ImGuiStyle& style = ImGui::GetStyle();
    style.ItemSpacing = ImVec2(13.0f, 3.0f);

    ImGui::Text("Start a new game?");
    ImGui::Spacing();

    
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    ImVec4 buttonColr = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 borderColr = ImVec4(1.0f, 0.5f, 0.8f, 1.0f);

    ImGui::PushStyleColor(ImGuiCol_Button, buttonColr);
    ImGui::PushStyleColor(ImGuiCol_Border, borderColr);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 4.0f);
    ImGui::Spacing();
	ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 65.0f);
    
    if (ImGui::Button("YES", ImVec2(100, 100))) {
        colour = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

        game_mode = 0;
        symbol_selected = false;
        color_selected = false;
        name_entered = false;
        (*game)->reset();
        game_over = false;
    }

    ImGui::SameLine(NULL, 30);

    if (ImGui::Button("NO", ImVec2(100, 100))) {
        colour = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
        exit(0);
    }

    ImGui::PopFont();
    ImGui::PopStyleVar();
    ImGui::PopStyleColor(2);

    ImGui::End();
}
///////////////////////////////////////////////////////////////////DATABASE WINDOW////////////////////////////////////////////
void GUI::display_data()
{
    ImGui::SetNextWindowPos(ImVec2((1920 + 960) * 0.5f, (1080 - 500) * 0.5f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(500, 500), ImGuiCond_Always);
    ImGui::Begin("database", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
    ImGui::Text("PLAYER STATS");

	database.readPlayerData();

    const auto& playerData = database.getPlayerData();

    for (const auto& entry : playerData) {
        std::string name = entry.first;
        char symbol = std::get<0>(entry.second); // Access first element of tuple
        std::string result = std::get<1>(entry.second); // Access second element of tuple

        std::string text = "Name: " + name + " Symbol: " + std::string(1, symbol) + " Result: " + result;
        ImGui::Text("%s", text.c_str());
    }

    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2((1920 + 1400) * 0.5f, (1080 + 800) * 0.5f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(620, 620), ImGuiCond_Always);
    ImGui::Begin("clearbtn", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
    ImGuiStyle& style = ImGui::GetStyle();
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[4]);
    //style.ItemSpacing = ImVec2(100.0f, 100.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    ImVec4 buttonColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 borderColor = ImVec4(1.0f, 0.5f, 0.8f, 1.0f);
    ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
    ImGui::PushStyleColor(ImGuiCol_Border, borderColor);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 4.0f);

   // ImGui::SetCursorPos(ImVec2(ImGui::GetWindowContentRegionMax().x - 120, ImGui::GetWindowContentRegionMax().y -500));
    if (ImGui::Button("CLEAR", ImVec2(100, 30))) {
        colour = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

        database.reset_db();
    }

    ImGui::PopStyleColor();
    ImGui::PopFont();
    ImGui::PopStyleVar();
    ImGui::PopStyleColor();

    ImGui::End();
}




///////////////////////////////////////////////5X5 GAME////////////////////////////////////////
///
void GUI::renderGameBoardFive() {
    ImGuiStyle& style = ImGui::GetStyle();

    ImGui::SetNextWindowPos(ImVec2((1920 - 770) * 0.5f, (1080 - 770) * 0.5f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(770, 770), ImGuiCond_Always);

    ImGui::Begin("game", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));

    ImGui::SetWindowFontScale(2.5f);

    char winner = (*game)->check_win().first;
    std::vector<std::pair<int, int>> winning_cells = (*game)->check_win().second;
    ImVec4 winner_line = ImVec4(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, 1.0f);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            ImGui::PushID(5 * i + j);

            ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
            style.ItemSpacing = ImVec2(0.0f, 0.0f);
            style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
            ImVec4 buttonColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
            ImVec4 borderColor = ImVec4(1.0f, 0.5f, 0.8f, 1.0f);

            ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
            ImGui::PushStyleColor(ImGuiCol_Border, borderColor);
            ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 4.0f);

            char label[2] = { (*game)->board[i][j], '\0' };

            ///PLAYERS COLORS//////////////////
            if (winner != '\0' && std::find(winning_cells.begin(), winning_cells.end(), std::make_pair(i, j)) != winning_cells.end())
            {
                ImGui::PushStyleColor(ImGuiCol_Text, winner_line); // animated color for the winning line
                game_over = true;

            }
            else if (winner == 'T')
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.5f, 0.5f, 0.5f, 0.5f)); // Tie color grey
                game_over = true;
            }
            else if ((*game)->board[i][j] == (*game)->human) {
                ImGui::PushStyleColor(ImGuiCol_Text, colour); // human color
            }
            else if ((*game)->board[i][j] == (*game)->ai) {

                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.5f, 0.8f, 1.0f)); //AI color
            }
            else
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f)); // base color
            }

            ////////////////BUTTONS IN THE GAMEBORAD////////////////////////
            if (ImGui::Button(label, ImVec2(150, 150))) {

                if ((*game)->current_player == (*game)->human && (*game)->can_move() && winner == '\0') {
                    (*game)->human_move(i, j);
                    (*game)->switch_player();

                    if (winner == '\0' && (*game)->can_move()) {
                        (*game)->ai_move();
                        (*game)->switch_player();
                    }
                    winner = (*game)->check_win().first;
                    winning_cells = (*game)->check_win().second;
                    if (winner != '\0') {
                        for (const auto& cell : winning_cells) {
                            std::cout << "(" << cell.first << ", " << cell.second << ") ";
                        }
                        std::cout << std::endl;
                    }
                    first_move = false;
                }
            }

            ImGui::PopFont();
            ImGui::PopStyleVar();
            ImGui::PopStyleColor(2);
            ImGui::PopID();
            ImGui::PopStyleColor();

            if (j < 4) ImGui::SameLine();
        }
    }

    ImGui::PopStyleColor();
    ImGui::End();
}

//    ImGuiStyle& style = ImGui::GetStyle();
//
//    ImGui::SetNextWindowPos(ImVec2((1920 - 770) * 0.5f, (1080 - 770) * 0.5f), ImGuiCond_Always);
//    ImGui::SetNextWindowSize(ImVec2(770, 770), ImGuiCond_Always);
//
//    ImGui::Begin("game", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
//    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
//
//    ImGui::SetWindowFontScale(2.5f);
//
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            ImGui::PushID(5 * i + j);
//
//            ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
//            style.ItemSpacing = ImVec2(0.0f, 0.0f);
//            style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
//            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
//            ImVec4 buttonColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
//            ImVec4 borderColor = ImVec4(1.0f, 0.5f, 0.8f, 1.0f);
//
//            ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
//            ImGui::PushStyleColor(ImGuiCol_Border, borderColor);
//            ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 4.0f);
//
//            char label[2] = { (*game)->board[i][j], '\0' };
//            ImGui::PushStyleColor(ImGuiCol_Text, colour);
//
//            if (ImGui::Button(label, ImVec2(150, 150))) {
//
//                if ((*game)->current_player == (*game)->human && (*game)->can_move() && (*game)->check_win().first == '\0') {
//                    (*game)->human_move(i, j);
//                    (*game)->switch_player();
//
//                    if ((*game)->check_win().first == '\0' && (*game)->can_move()) {
//                        (*game)->ai_move();
//                        (*game)->switch_player();
//
//                    }
//                }
//            }
//
//            ImGui::PopFont();
//            ImGui::PopStyleVar();
//            ImGui::PopStyleColor(2);
//            ImGui::PopID();
//            ImGui::PopStyleColor();
//
//            if (j < 4) ImGui::SameLine();
//        }
//    }
//
//    ImGui::PopStyleColor();
//    ImGui::End();
//}

void GUI::exit_game()
{
    ImGui::SetNextWindowPos(ImVec2((1920 - 1600) * 0.5f, (1080 + 800) * 0.5f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(620, 620), ImGuiCond_Always);
    ImGui::Begin("exit", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
	ImGuiStyle& style = ImGui::GetStyle();
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[4]);
    //style.ItemSpacing = ImVec2(100.0f, 100.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    ImVec4 buttonColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 borderColor = ImVec4(1.0f, 0.5f, 0.8f, 1.0f);
    ImGui::PushStyleColor(ImGuiCol_Button, buttonColor);
    ImGui::PushStyleColor(ImGuiCol_Border, borderColor);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 4.0f);


    if (ImGui::Button("EXIT", ImVec2(100, 30))) {
        colour = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

        exit(0);
    }

    ImGui::PopStyleColor();
    ImGui::PopFont();
    ImGui::PopStyleVar();
    ImGui::PopStyleColor();
    ImGui::End();
}

void GUI::run() {
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        exit_game();
        reset();
        display_data();
      //  renderPlayerDataText();
        renderSettings();
        if (game_mode != 0) {
            if (game_mode == 3) {
                renderGameBoardThree();
            }
            else if (game_mode == 5) {
                renderGameBoardFive();
            }
            
        }
        if(game_over)
        {
            database.writePlayerData(name, *game);
        	renderResults();
            //play_again();
        	
          //  game_over= false;
		}   


        ImGui::SetNextWindowSize(ImVec2(0, 0), ImGuiCond_FirstUseEver);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }
}
