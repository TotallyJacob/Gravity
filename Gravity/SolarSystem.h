#include<iostream>
#include<vector>

//My imports
#include"Star.h"
#include"PlanetSystem.h"

#pragma once

class SolarSystem
{
private:
	std::vector<PlanetSystem> planetSystems;
	std::vector<Star> stars;

public:
	SolarSystem();
	~SolarSystem() = default;
};

