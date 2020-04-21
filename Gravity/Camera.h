//Matrices imports
#include"GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtx/transform.hpp"

#define UPVECTOR glm::vec3(0, 1, 0)

#pragma once

class Camera
{
protected:

	//Vectors
	glm::vec3 position = glm::vec3(0.f);
	glm::vec3 viewDirection = glm::vec3(0.f, 0.f, -1.0f);
	const glm::vec3 upVector = UPVECTOR;

public:

	Camera();

	//Updates every time called
	virtual operator glm::mat4() const {
		return glm::lookAt(position, position + viewDirection, upVector); 
	}

	virtual void setRotation(glm::vec2 mouseDelta);
	virtual void setMovementVector(glm::vec3 vector);
	virtual void setLocation(glm::vec3 location);

	//Getters
	const glm::vec3 getViewDirection() const {
		return viewDirection;
	}

	const glm::vec3 getLocation() const {
		return position;
	}
};

