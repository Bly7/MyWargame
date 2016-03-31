#include "stdafx.h"

float Vec2Length(sf::Vector2f vec)
{
	return sqrtf((vec.x * vec.x) + (vec.y * vec.y));
}

sf::Vector2f Vec2Normalize(sf::Vector2f vec)
{
	float len = Vec2Length(vec);

	if (len != 0)
		return sf::Vector2f(vec.x / len, vec.y / len);
	else
		return vec;
}

float Vec2AngleR(sf::Vector2f vec)
{
	return atan2f(vec.y, vec.x);
}

float Vec2AngleD(sf::Vector2f vec)
{
	return atan2f(vec.y, vec.x) * 180 / Pi;
}

sf::Vector2f Vec2iTof(sf::Vector2i vec)
{
	return sf::Vector2f(vec.x, vec.y);
}