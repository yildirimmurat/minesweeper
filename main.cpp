#include <SFML/Graphics.hpp>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));

    sf::RenderWindow app(sf::VideoMode(400,400), "Minesweeper");

    int w = 32;
    int grid[12][12];
    int sgrid[12][12]; 
    
    sf::Texture t;
    t.loadFromFile("images/tiles.png");
    sf::Sprite s(t);

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            sgrid[i][j] = 10;
            if (rand()%5==0) grid[i][j] = 9;
            else grid[i][j] = 0;
        }
    }

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            int n = 0;
            if (grid[i][j] == 9) continue;
            if (grid[i+1][j] == 9) n++;
            if (grid[i][j+1] == 9) n++;
            if (grid[i-1][j] == 9) n++;
            if (grid[i][j-1] == 9) n++;
            if (grid[i+1][j+1] == 9) n++;
            if (grid[i-1][j-1] == 9) n++;
            if (grid[i-1][j+1] == 9) n++;
            if (grid[i+1][j-1] == 9) n++;
            grid[i][j] = n;
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
                sgrid[i][j] = grid[i][j];
                // sf::RectangleShape rectangle;
                // rectangle.setSize(sf::Vector2f(w, w));
                // rectangle.setPosition(i*w, j*w);
                // rectangle.setTexture(&t);
                // app.draw(rectangle);
                s.setTextureRect(sf::IntRect(sgrid[i][j]*w,0,w,w));
                s.setPosition(i*w, j*w);
                app.draw(s);
            }
        }

        app.display();
    }

    return 0;
}