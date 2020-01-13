#include "Entity.h"

Entity::Entity(sf::Vector2f size, sf::Vector2f position, string path)
    : Component(size, position, path), health(100.0f), attackDamage(25.0f)
{
    animation = new Animation;

    sprite.setScale({ 3, 3 });
    right = true;
}

Entity::~Entity()
{
    delete animation;
}

void Entity::Draw(sf::RenderWindow* window)
{
    if (health > -10.0f)
    {
        window->draw(sprite);
    }
}

bool Entity::checkCollision(Component* component)
{
    if (sprite.getGlobalBounds().intersects(component->getEntity().getGlobalBounds()))
        return true;
    return false;
}
