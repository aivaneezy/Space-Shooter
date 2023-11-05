#include "math.h"



sf::Vector2i Math::normalizeVector(sf::Vector2i vector)
{
	
	// calculating the magnitude of the vector
	float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	// normalizzing the vector
	sf::Vector2i normalizeV;
	normalizeV.x = vector.x / magnitude;
	normalizeV.y = vector.y / magnitude;

	return normalizeV;

}

long double::CalculateAngle(long double y, long double x)
{
	return atan2(y, x);
}
