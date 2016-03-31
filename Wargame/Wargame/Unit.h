#pragma once

#include "stdafx.h"

enum MissionType{Move,Fire,Entrench};

struct Mission
{
	int Type;
	sf::Vector2f Position;
};

class Unit
{
public:
	Unit();
	
	Mission GetCurrentMission();
	Mission GetNewestMission();
	std::vector<Mission> GetMissions();	
	void RemoveNewestMission();
	void RemoveCurrentMission();
	void ClearMissions();

	void GoToPosition(sf::Vector2f Pos);

	void SetPosition(sf::Vector2f Pos);
	void SetSpeed(float mps);
	void SetDirection(float Dir);

	sf::Vector2f GetPosition();
	float GetSpeed();
	float GetDirection();

	void Update(float dt);

private:
	void Move(float dt, sf::Vector2f pos);

private:
	sf::Vector2f Position;
	float Speed;
	float Direction;

	std::vector<Mission> MissionQueue;
};