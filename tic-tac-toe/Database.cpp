#include "Database.h"
#include "TicTacToe.h"

Database::Database() {
    // Initialize as needed
}

Database::~Database() {
    // Cleanup if needed
}

void Database::writePlayerData(const char* playerName, TicTacToe* game) {
    if (game == nullptr) {
        std::cerr << "Error: TicTacToe game is not initialized." << std::endl;
        return;
    }

    char symbol = game->human;
    std::string won;
     int score = game->check_score(game->board);

        if (score == -1) {
            won = "WIN";
        }
        else if (score == 1) {
            won = "LOSS";
           // std::cout << "lost" << std::endl;
        }
        else if (score == 0) {
            won = "TIE";
        }

    playerData[playerName] = std::make_tuple(symbol, won);
    saveToFile();
}

const std::map<std::string, std::tuple<char, std::string>>& Database::getPlayerData() const {
    return playerData;
}

void Database::readPlayerData() {
    loadFromFile();
}

void Database::saveToFile() {
    std::ofstream outFile("player_stats.txt");
   // std::cout << "Saving player data to file..." << std::endl;

    if (outFile.is_open()) {
        for (const auto& entry : playerData) {
            outFile << entry.first << " " << std::get<0>(entry.second) << " " << std::get<1>(entry.second) << std::endl;
           // std::cout << "Player: " << entry.first << " Symbol: " << std::get<0>(entry.second) << " Result: " << std::get<1>(entry.second) << std::endl;
        }
        outFile.close();
    }
    else {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }
}

void Database::loadFromFile() {
    std::ifstream inFile("player_stats.txt");

    if (inFile.is_open()) {
        std::string name;
        char symbol;
        std::string won;

        while (inFile >> name >> symbol >> won) {
            playerData[name] = std::make_tuple(symbol, won);
        }
        inFile.close();
    }
    else {
        std::cerr << "Unable to open the file for reading. The file may not exist yet." << std::endl;
    }
}
