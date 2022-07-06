#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window {
    public:
        Window();
        Window(const std::string &l_title, const sf::Vector2u &l_size);
        ~Window();

        void BeginDraw();
        void EndDraw();
        
        void Update();
        
        bool IsDone();
        bool IsFullscreen();
        sf::Vector2u GetWindowSize();

        void ToggleFullscreen();

        void Draw(sf::Drawable &l_drawable);

        sf::RenderWindow* GetRenderWindow();
        
        sf::Vector2i GetPos();
        bool GetClickedLeft();
        bool GetClickedRight();
        void ClearMouseEvents();
    private:
        void Setup (const std::string &l_title, const sf::Vector2u &l_size);
        void Destroy();
        void Create();

        sf::RenderWindow m_window;
        sf::Vector2u m_windowSize;
        std::string m_windowTitle;
        bool m_isDone;
        bool m_isFullscreen;
        sf::Vector2i m_pos;
        bool m_clickedLeft;
        bool m_clickedRight;
};