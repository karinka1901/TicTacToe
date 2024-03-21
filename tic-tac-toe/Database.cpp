#include "Database.h"
#include "TicTacToe.h"



void Database::write_player_data(const char* player_name, TicTacToe* game) {
    if (game == nullptr) {
        cout << "game doesnt exist" << endl;
        return;
    }

    char symbol = game->human;
    string result = " ";
    int score = game->check_score();

    if (score == -1) {
        result = "WIN";
    }
    else if (score == 1) {
        result = "LOSS";
    }
    else if (score == 0 && game->free_cell==0) {
        result = "TIE";
    }
    else
    {
        result = " ";
    }

    player_data[player_name] = make_tuple(symbol, result);
    saveToFile();
}

map<string, tuple<char, string>> &Database::get_player_data() { //for gui
    return player_data;
}

void Database::read_player_data() {
    loadFromFile();
}

void Database::saveToFile() {
    json json_data;

    for (const auto& entry : player_data) {
        json player_entry;
        player_entry["name"] = entry.first;
        player_entry["symbol"] = string(1, get<0>(entry.second));
        player_entry["result"] = get<1>(entry.second);

        json_data.push_back(player_entry);
    }

    ofstream out_file("stats.json");
    out_file << setw(4) << json_data; 
    out_file.close();
}

void Database::loadFromFile() {
    ifstream in_file("stats.json");

    if (in_file.is_open()) {
        json json_data;
        in_file >> json_data;

        for (const auto& entry : json_data) {
            string name = entry["name"];
            char symbol = entry["symbol"].get<string>()[0];
            string won = entry["result"];

            player_data[name] = make_tuple(symbol, won);
        }

        in_file.close();
    }
    else {
        cout << "cant open the file" << endl;
    }
}
void Database::reset_db() {
    player_data.clear();  
    saveToFile();
}
