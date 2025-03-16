#include "Player.h"
#include <stdexcept>
#include <algorithm>

Player::Player(sf::RenderWindow* window) : m_window(window), m_texture("resources/doodle.png"), m_sprite(m_texture), m_orientation(PlayerOrientation::Right)
{
    m_sprite.setTexture(m_texture);
    m_sprite.setOrigin({ m_sprite.getLocalBounds().size.x / 2.0f, m_sprite.getLocalBounds().size.y / 2.0f });
    m_sprite.setScale({ 0.2f, 0.2f });

    const sf::Vector2u windowSize = m_window->getSize();
    m_sprite.setPosition(sf::Vector2f(windowSize.x / 2.0f, windowSize.y - m_sprite.getGlobalBounds().size.y));
    m_position = m_sprite.getPosition();
}

void Player::update()
{
    handleInput();
    enforceBoundaries();

    m_sprite.setPosition(m_position);

    if ((m_newOrientationRequest == PlayerOrientation::Left && m_sprite.getScale().x > 0) ||
        (m_newOrientationRequest == PlayerOrientation::Right && m_sprite.getScale().x < 0))
    {
        m_sprite.setScale({ -m_sprite.getScale().x, m_sprite.getScale().y });
    }

    m_orientation = m_newOrientationRequest;
}

void Player::draw()
{
    m_window->draw(m_sprite);
}

void Player::handleInput()
{
    const float SPEED_X = 15.0f;
    float deltaX = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        deltaX += -SPEED_X;
        m_newOrientationRequest = PlayerOrientation::Left;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        deltaX += SPEED_X;
        m_newOrientationRequest = PlayerOrientation::Right;
    }

    m_position.x += deltaX;
}

void Player::enforceBoundaries()
{
    sf::Vector2u windowSize = m_window->getSize();
    float spriteHalfWidth = m_sprite.getGlobalBounds().size.x / 2.0f;

    m_position.x = std::clamp(m_position.x, spriteHalfWidth, static_cast<float>(windowSize.x) - spriteHalfWidth);
}
