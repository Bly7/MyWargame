#include "stdafx.h"

Unit::Unit()
{
	Position = sf::Vector2f(0, 0);
	float Speed = 0;
	float Direction = 0;
}

Mission Unit::GetCurrentMission()
{
	return MissionQueue[0];
}

Mission Unit::GetNewestMission()
{
	return MissionQueue[MissionQueue.size()-1];
}

std::vector<Mission> Unit::GetMissions()
{
	return MissionQueue;
}

void Unit::RemoveNewestMission()
{
	MissionQueue.erase(MissionQueue.end());
}

void Unit::RemoveCurrentMission()
{
	MissionQueue.erase(MissionQueue.begin());
}

void Unit::ClearMissions()
{
	MissionQueue.clear();
}

void Unit::GoToPosition(sf::Vector2f Pos)
{
	Mission mission;
	mission.Type = MissionType::Move;
	mission.Position = Pos;
	MissionQueue.push_back(mission);
}

void Unit::SetPosition(sf::Vector2f Pos)
{
	Position = Pos;
}

void Unit::SetSpeed(float mps)
{
	Speed = mps;
}

void Unit::SetDirection(float Dir)
{
	Direction = Dir;
}

sf::Vector2f Unit::GetPosition()
{
	return Position;
}

float Unit::GetSpeed()
{
	return Speed;
}

float Unit::GetDirection()
{
	return Direction;
}

void Unit::Update(float dt)
{
	if (!MissionQueue.empty())
	{
		Mission curMission = MissionQueue[0];

		switch (curMission.Type)
		{
		case MissionType::Move:
			Move(dt, curMission.Position);
			break;
		default:
			// Do Nothing
			break;
		}
	}
	else
	{

	}
}

void Unit::Move(float dt, sf::Vector2f pos)
{
	sf::Vector2f dir = pos - Position;
	float dist = Vec2Length(dir);
	dir = dir / dist;
	
	Direction = Vec2AngleD(dir);
	float distTrav = Speed * dt;

	if (dist < distTrav)
	{
		Position = pos;
		RemoveCurrentMission();
	}
	else
	{
		Position += dir * distTrav;
	}
}