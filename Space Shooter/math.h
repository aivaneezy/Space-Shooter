#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>


class Math
{
public:
	static sf::Vector2i normalizeVector(sf::Vector2i vector);
	static long double calculateAngle(long double y, long double x);
private:
};