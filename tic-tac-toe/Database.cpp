#include "Database.h"
#include "TicTacToe.h"

Database::Database() {

}

Database::~Database() {
   
}

void Database::write_player_data(const char* playerName, TicTacToe* game) {
    if (game == nullptr) {
        cerr << "Error: TicTacToe game is not initialized." << endl;
        return;
    }

    char symbol = game->human;
    string won = " ";
    int score = game->check_score(game->board);

    if (score == -1) {
        won = "WIN";
    }
    else if (score == 1) {
        won = "LOSS";
    }
    else if (score == 0 && game->free_cell==0) {
        won = "TIE";
    }
    else
    {
        won = " ";
    }

    playerData[playerName] = make_tuple(symbol, won);
    saveToFile();
}

const map<string, tuple<char, string>>& Database::get_player_data() const {
    return playerData;
}

void Database::read_player_data() {
    loadFromFile();
}

void Database::saveToFile() {
    json jsonData;

    for (const auto& entry : playerData) {
        json playerEntry;
        playerEntry["name"] = entry.first;
        playerEntry["symbol"] = string(1, get<0>(entry.second));
        playerEntry["result"] = get<1>(entry.second);

        jsonData.push_back(playerEntry);
    }

    ofstream outFile("stats.json");
    outFile << setw(4) << jsonData; 
    outFile.close();
}

void Database::loadFromFile() {
    ifstream inFile("stats.json");

    if (inFile.is_open()) {
        json jsonData;
        inFile >> jsonData;

        for (const auto& entry : jsonData) {
            string name = entry["name"];
            char symbol = entry["symbol"].get<string>()[0];
            string won = entry["result"];

            playerData[name] = make_tuple(symbol, won);
        }

        inFile.close();
    }
    else {
        cerr << "cant open the file for reading" << endl;
    }
}
void Database::reset_db() {
    playerData.clear();  
    saveToFile();
}
