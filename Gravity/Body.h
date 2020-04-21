//External APIs
#include"GL/glew.h"
#include"GLFW/glfw3.h"
#include"GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtx/transform.hpp"

#include<iostream>
#include<vector>

//My imports
#include"BodyData.h"
#include"Model.h"
#include"Buffers.h"
#include"ShaderProgram.h"

#pragma once

class Body : public BodyData
{
protected:
	//Rendering
	unsigned int vao = 0, vbo = 0;
	std::vector<float> vertices;
	//Matrix
	glm::vec3 position;
	glm::mat4 modelMatrix;

public:

	Body(const char *dataFilePath);
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
	const glm::mat4 getModelMatrix() const {
		return modelMatrix;
	}
	const glm::vec3 getPosition() const {
		return position;
	}


	//Different drawing passes
	virtual void draw() = 0;
	virtual void shadowMapPass() = 0;
	virtual void alphaPass() = 0;
};

