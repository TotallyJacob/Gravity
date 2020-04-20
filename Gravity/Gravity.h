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

#pragma once

class Gravity : public Renderer
{
private:

	void init() override;
	void loop() override;
	void cleanUp() override;

public:

	Gravity();
	~Gravity() = default;

};

