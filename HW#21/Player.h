#pragma once
#include <SFML/Graphics.hpp>

enum class PlayerOrientation
{
    Left,
    Right,
    Center
};

class Player
{
public:
    Player(sf::RenderWindow* window);

    void update();
    void draw();

    const sf::Sprite& getSprite() const { return m_sprite; }

private:
    void handleInput();
    void enforceBoundaries();

    //Somehow this order is important: putting m_sprite first won't work??? 
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    sf::RenderWindow* m_window = nullptr;

    sf::Vector2f m_position;
    PlayerOrientation m_orientation;
    PlayerOrientation m_newOrientationRequest;
};
