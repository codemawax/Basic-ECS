#include "Application.h"

void Application::Update()
{
    Time currentTime = clock.getElapsedTime();

    if (currentTime.asMilliseconds() - lastUpdateTime.asMilliseconds() > 10)
    {

    }
}

void Application::Draw(sf::RenderWindow& window)
{
    window.clear(Color::Black);
}