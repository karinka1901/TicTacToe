#include "Gui.h"


int main() {
    TicTacToe* game = nullptr;
    GUI gui(game);

    gui.run();

    delete game;

    return 0;
}
