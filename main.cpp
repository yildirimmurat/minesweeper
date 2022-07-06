#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.hpp"

int main (int argc, char** argv) {
    Game game;

    while(!game.GetWindow()->IsDone()) {
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }

    return 0;
}