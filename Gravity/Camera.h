//Matrices imports
#include"GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtx/transform.hpp"

#pragma once

class Camera
{
private:

	//Vectors
	glm::vec3 position = glm::vec3(0.f);
	glm::vec3 viewDirection = glm::vec3(0.f, 0.f, -1.0f);
	const glm::vec3 upVector = glm::vec3(0, 1, 0);;

public:

	Camera();

	//Updates every time called
	operator glm::mat4() const {
		return glm::lookAt(position, position + viewDirection, upVector); 
	}

	void setRotation(glm::vec2 mouseDelta);
	void setMovementVector(glm::vec3 vector);
	void setLocation(glm::vec3 location);

	//Getters
	const glm::vec3 getViewDirection() const {
		return viewDirection;
	}

	const glm::vec3 getLocation() const {
		return position;
	}
};

