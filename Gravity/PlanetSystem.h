#include<iostream>
#include<vector>

//My imports
#include"Planet.h"
#include"Moon.h"

#pragma once

class PlanetSystem
{
protected:
	std::vector<Planet> bodies;
	unsigned int shadowMapTextureId = 0;

public:

	PlanetSystem();
	~PlanetSystem() = default;

	virtual void draw(unsigned int program);
	virtual void shadowMapPass();

	//Setter and Getter methods
	//void addBody(Body body);
	inline void setShadowMapTextureId(unsigned int id) {
		shadowMapTextureId = id;
	}

};

