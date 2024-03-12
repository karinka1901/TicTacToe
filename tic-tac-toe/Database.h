#pragma once
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <tuple>
#include "json.hpp"
#include <iomanip>

using json = nlohmann::json;
using namespace std;

class TicTacToe;

class Database {
public:
    Database();
    ~Database();

	map<string, tuple<char, string>> playerData;

    void write_player_data(const char* playerName, TicTacToe* game);
    const map<string, tuple<char, string>>& get_player_data() const;
    void read_player_data();
	void saveToFile();
    void loadFromFile();
    void reset_db();
};
