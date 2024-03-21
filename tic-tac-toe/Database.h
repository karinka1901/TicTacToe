#pragma once
#include "json.hpp"
#include <map>
#include <tuple>
#include <fstream>
#include <iomanip>

using json = nlohmann::json;
using namespace std;

class TicTacToe;

class Database {
public:

	map<string, tuple<char, string>> player_data; // name, symbol, game mode

    void write_player_data(const char* player_name, TicTacToe* game);
    map<string, tuple<char, string>> &get_player_data();
    void read_player_data();
	void saveToFile();
    void loadFromFile();
    void reset_db();
};
