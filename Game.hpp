#pragma once
#include "Window.hpp"
#include "Board.hpp"

class Game {
    public: 
        Game();
        ~Game();

        void HandleInput();
        void Update();
        void Render();
        Window* GetWindow();
        Board* GetBoard();
        sf::Time GetElapsed();
        void RestartClock();
        void Reveal(int x, int y);
    private:
        void MoveMushroom();
        Window m_window;
        Board m_board;
        sf::Clock m_clock;
        sf::Time m_elapsed;
        int m_grid[12][12];
        int m_sgrid[12][12];
        sf::Texture m_texture;
        sf::Sprite m_sprite;
};