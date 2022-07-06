#include "Window.hpp"

Window::Window() {
    Setup("Window", sf::Vector2u(400,400));
}
Window::Window(const std::string &l_title, const sf::Vector2u &l_size) {
    Setup(l_title, l_size);
}
Window::~Window() {
    Destroy();
}

void Window::Setup(const std::string &l_title, const sf::Vector2u &l_size) {
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    m_window.setFramerateLimit(60); // to save cpu
    Create();
}
void Window::Create() {
    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
}
void Window::Destroy() {
    m_window.close();
}

void Window::Update() {
    sf::Event e;
    while (m_window.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            m_isDone = true;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_pos = sf::Mouse::getPosition(m_window);
            m_clickedLeft = true;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            m_pos = sf::Mouse::getPosition(m_window);
            m_clickedRight = true;
        }
    }
}
void Window::ToggleFullscreen() {
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}

void Window::BeginDraw() {
    m_window.clear(sf::Color::White);
}
void Window::EndDraw() {
    m_window.display();
}

bool Window::IsDone() { return m_isDone; }
bool Window::IsFullscreen() { return m_isFullscreen; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::Draw(sf::Drawable &l_drawable) {
    m_window.draw(l_drawable);
}

sf::Vector2i Window::GetPos() {
    return m_pos;
}

bool Window::GetClickedLeft() { return m_clickedLeft; }
bool Window::GetClickedRight() { return m_clickedRight; }

sf::RenderWindow* Window::GetRenderWindow() {
    return &m_window;
}

void Window::ClearMouseEvents() {
    m_clickedLeft = false;
    m_clickedRight = false;
}
