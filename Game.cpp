#include "Game.hpp"
#include <iostream>

Game::Game(): m_window("Minesweeper", sf::Vector2u(400,400)) {
    RestartClock();
    srand(time(NULL)); // start clock on creation of game object
      
    m_texture.loadFromFile("images/tiles.png");
    m_sprite.setTexture(m_texture);

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            m_sgrid[i][j] = 10;
            if (rand() % 5 == 0) m_grid[i][j] = 9;
            else m_grid[i][j] = 0;
        }
    }

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            int n = 0;
            if (m_grid[i][j] == 9) continue;
            if (m_grid[i+1][j] == 9) n++;
            if (m_grid[i][j+1] == 9) n++;
            if (m_grid[i-1][j] == 9) n++;
            if (m_grid[i][j-1] == 9) n++;
            if (m_grid[i+1][j+1] == 9) n++;
            if (m_grid[i-1][j-1] == 9) n++;
            if (m_grid[i-1][j+1] == 9) n++;
            if (m_grid[i+1][j-1] == 9) n++;
            m_grid[i][j] = n;
        }
    }
}
Game::~Game() {}

void Game::Update() {
    m_window.Update();

    int cellSize = m_board.GetCellSize();
    for(int i = 1; i<= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (m_sgrid[i][j] == 9) m_sgrid[i][j] = m_grid[i][j];
            m_sprite.setTextureRect(sf::IntRect(m_sgrid[i][j]*cellSize, 0, cellSize, cellSize));
            m_sprite.setPosition(i*cellSize, j*cellSize);
        }
    }

    if (m_window.GetClickedLeft()) {
        sf::Vector2i pos = m_window.GetPos();
        m_sgrid[pos.x/cellSize][pos.y/cellSize] = m_grid[pos.x/cellSize][pos.y/cellSize];
    } else if (m_window.GetClickedRight()) {
        sf::Vector2i pos = m_window.GetPos();
        m_sgrid[pos.x/cellSize][pos.y/cellSize] = 11;
    }
    m_window.ClearMouseEvents();
}

void Game::Render() {
    m_window.BeginDraw();

    int cellSize = m_board.GetCellSize();
    for(int i = 1; i<= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (m_sgrid[i][j] == 9) m_sgrid[i][j] = m_grid[i][j];
            m_sprite.setTextureRect(sf::IntRect(m_sgrid[i][j]*cellSize, 0, cellSize, cellSize));
            m_sprite.setPosition(i*cellSize, j*cellSize);
            m_window.Draw(m_sprite);
        }
    }
    m_window.EndDraw();
}

void Game::HandleInput(){
	// Input handling.
    
}

Window* Game::GetWindow(){ return &m_window; }
Board* Game::GetBoard(){ return &m_board; }

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }
