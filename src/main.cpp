#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window");

    sf::Texture map;
    if (!map.loadFromFile("/home/dev/development/dogGame01/Assets/Maps/gametown2d probably finished now.png"))
    {
        std::cout << "Failed to load map texture!\n";
        return 1;
    }

    sf::Texture character;
    if(!character.loadFromFile("/home/dev/development/dogGame01/Assets/Sprites/Character1M_1_walk_0.png"))
    {
        std::cout << "Failed to load character texture!\n";
        return 1;
    }

    sf::Sprite char1;
    char1.setTexture(character);
    char1.setPosition(sf::Vector2f(300, 1010));
    char1.setScale(2.0f, 2.0f);

    sf::Sprite mapbg;
    mapbg.setTexture(map);
    mapbg.setPosition(sf::Vector2f(-360, 375));
    mapbg.setScale(0.75f, 0.75f);

    sf::View view(char1.getPosition(), static_cast<sf::Vector2f>(window.getSize()));
    view.setCenter(char1.getPosition());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            char1.move(-0.1f,  0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            char1.move(0.1f, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            char1.move(0.f, 0.1f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            char1.move(0.f, -0.1f);
        }

        sf::Vector2f viewCenter = view.getCenter();
        sf::Vector2f char1position = char1.getPosition();

        float viewWidth = view.getSize().x;
        float viewHeight = view.getSize().y;
        float mapWidth = mapbg.getGlobalBounds().width;
        float mapHeight = mapbg.getGlobalBounds().height;

        if(char1position.x - viewWidth/2 < 0)
        {
            viewCenter.x = viewWidth/2;
        }
        else if (char1position.x + viewWidth/2 > mapWidth)
        {
            viewCenter.x = mapWidth - viewWidth/2;
        }
        else
        {
            viewCenter.x = char1position.x;
        }

        if(char1position.y - viewHeight/2 < 0)
        {
            viewCenter.y = viewHeight/2;
        }
        else if(char1position.y + viewHeight/2 > mapHeight)
        {
            viewCenter.y = mapHeight - viewHeight/2;
        }
        else
        {
            viewCenter.y = char1position.y;
        }


        

        window.clear();
        sf::View updatedView(viewCenter, view.getSize());
        window.setView(updatedView);
        window.draw(mapbg);
        window.draw(char1);
        window.display();
    }

    return 0;
}