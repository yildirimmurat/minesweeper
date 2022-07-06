#include "Window.hpp"

class Game {
    public: 
        Game();
        ~Game();

        void HandleInput();
        void Update();
        void Render();
        Window* GetWindow();
        sf::Time GetElapsed();
        void RestartClock();
    private:
        void MoveMushroom();
        Window m_window;
        sf::Clock m_clock;
        sf::Time m_elapsed;
        int m_w;
        int m_grid[12][12];
        int m_sgrid[12][12];
        sf::Texture m_texture;
        sf::Sprite m_sprite;
};