#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace std;
using namespace sf;
using uint = unsigned int;

static float GetDistance(const Vector2f a, const Vector2f b)
{
    return sqrt(pow(a.x - b.x, 2.f) + pow(a.y - b.y, 2.f));
}