#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <tuple>

// Forward declaration of the TicTacToe class
class TicTacToe;

class Database {
public:
    Database();
    ~Database();

    void writePlayerData(const char* playerName, TicTacToe* game);
    const std::map<std::string, std::tuple<char, std::string>>& getPlayerData() const;
    void readPlayerData();

private:
    std::map<std::string, std::tuple<char, std::string>> playerData;

    void saveToFile();
    void loadFromFile();
};
