#include<iostream>
#include<vector>

#include"GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtx/transform.hpp"

//My imports
#include"Renderer.h"
#include"Model.h"
#include"Buffers.h"
#include"ShaderProgram.h"
#include"Camera.h"
#include"SolarSystem.h"

//test
#include"PlanetManager.h"

#include"JsonData.h"

#define TICK_RATE 0.02
#define TICK_RATE_SLOW 1

#pragma once

class Gravity : public Renderer
{
private:

	void init() override;
	void loop() override;
	void cleanUp() override;

	void resize(glm::mat4 &perspective);

	//Updates
	void tick();
	void tick_slow();

public:

	Gravity();
	~Gravity() = default;

};

