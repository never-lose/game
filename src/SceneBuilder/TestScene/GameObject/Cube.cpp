#include "Cube.hpp"

Cube::Cube(float width, sf::Vector2f startPosition, float startRotateAngle, sf::Color color)
{
    this->width = width;
    this->startPosition = startPosition;
    this->startRotateAngle = startRotateAngle;
    this->color = color;
}

Cube::~Cube()
{
    if (cube)
    {
        delete cube;
    }
}

void Cube::start()
{
    cube = new sf::RectangleShape(sf::Vector2f(width, width));
    cube->setFillColor(color);
    cube->setPosition(startPosition);
    cube->setRotation(startRotateAngle);

    collider = new Collider();
    collider->setFloatRect(cube->getGlobalBounds());

    rayCather = new Collider();
    rayCather->setFloatRect(cube->getGlobalBounds());

    registerComponent(Tag::Collider, collider);
    registerComponent(Tag::RayCather, rayCather);
}

void Cube::update()
{
    if (ElementContainer::get().getGameMode() == GameMode::Composite)
    {
        ElementContainer::get().getRenderWindow()->draw(*cube);
    }
}

sf::Vector2f Cube::getPosition()
{
    return cube->getPosition();
}

float Cube::getRotateAngle()
{
    return cube->getRotation();
}

sf::Color Cube::getColor()
{
    return cube->getFillColor();
}
