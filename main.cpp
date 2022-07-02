#include <SFML/Graphics.hpp>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));

    sf::RenderWindow app(sf::VideoMode(400,400), "Minesweeper");

    int w = 32;
    int grid[12][12];
    int sgrid[12][12]; 
    
    sf::Texture emptyTexture;
    emptyTexture.loadFromFile("images/0.png");
    sf::Sprite s(emptyTexture);

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            sgrid[i][j] = 10;
        }
    }

    while (app.isOpen()) {
        sf::Event e;
        while (app.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                app.close();
            }
        }

        for(int i = 1; i<= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(w, w));
                rectangle.setPosition(i*w, j*w);
                rectangle.setTexture(&emptyTexture);
                app.draw(rectangle);
            }
        }

        app.display();
    }

    return 0;
}