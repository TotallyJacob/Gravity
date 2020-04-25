#include<iostream>
#include<vector>

//My imports
#include"Star.h"
#include"PlanetSystem.h"
#include"Camera.h"
#include"ShaderProgram.h"

#pragma once

class SolarSystem
{
private:
	std::vector<PlanetSystem> planetSystems;
	std::vector<Star> stars;

	unsigned int program = 0;

public:
	SolarSystem(const char *dataFilePath);
	~SolarSystem() = default;

	virtual void draw(Camera &camera, const float *perspective);

	void updateSystemPositions();
};

