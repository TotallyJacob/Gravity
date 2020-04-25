//Matrices imports
#include"GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtx/transform.hpp"

#define UPVECTOR glm::vec3(0, 1, 0)

#pragma once

class Camera
{
private:

	//Vectors
	glm::vec3 position = glm::vec3(0.f);
	glm::vec3 viewDirection = glm::vec3(0.f, 0.f, -1.0f);
	glm::mat4 viewMatrix = glm::mat4(1.0f);
	const glm::vec3 upVector = UPVECTOR;

public:

	Camera() = default;

	void setRotation(glm::vec2 mouseDelta);
	void setMovementVector(glm::vec3 vector);
	void setLocation(glm::vec3 location);
	void updateViewMatrix();

	operator glm::mat4() const {
		return viewMatrix;
	}

	//Getters
	const glm::vec3 getViewDirection() const {
		return viewDirection;
	}

	const glm::vec3 getLocation() const {
		return position;
	}

	const glm::mat4 getViewMatrix() const {
		return viewMatrix;
	}
};

