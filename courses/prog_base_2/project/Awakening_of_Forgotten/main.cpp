#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow win(sf::VideoMode(200, 200), "SFML Test", sf::Style::Fullscreen );


    sf::Texture t;

    t.loadFromFile("background.jpg");
 /*
    sf::Sprite bg;
    bg.SetImage(background);
    bg.setPosition(0,0);
    t.loadFromFile("Test.png");
    */
    sf::Sprite s;
    s.setTexture(t);
    s.setPosition(0,0);

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }

        win.clear();
        win.draw(s);
        win.display();
    }

    return 0;
}
