#include<iostream>
#include<vector>

//External APIs
#include"GLFW/glfw3.h"
#include"GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtx/transform.hpp"

//My imports
#include"Model.h"
#include"Buffers.h"
#include"ShaderProgram.h"

#pragma once

class Body
{
public:
	struct BodyData {
	};

protected:
	//Rendering
	unsigned int vao = 0, vbo = 0;
	std::vector<float> vertices;
	//Matrix
	glm::vec3 position;
	glm::mat4 modelMatrix;

	BodyData data;

public:

	Body(BodyData data);
	~Body() = default;
	
	//Setters
	inline void setPosition(glm::vec3 _position) {
		position = _position;
	}
	inline void setModelMatrix(glm::vec3 position) {
		setPosition(position);
		updateModelMatrix();
	}
	inline void setModelMatrix(glm::mat4 matrix) {
		modelMatrix = matrix;
	}
	inline void updateModelMatrix() {
		modelMatrix = glm::translate(position);
	}

	//Getters
	const BodyData& getData() const {
		return data;
	}
	const glm::mat4 getModelMatrix() const {
		return modelMatrix;
	}
	const glm::vec3 getPosition() const {
		return position;
	}

	//Main draw
	virtual void draw() = 0;

	//Different drawing passes
	virtual void shadowMapPass() = 0;

protected:
	virtual void drawPass() = 0;
	virtual void alphaPass() = 0;
};

