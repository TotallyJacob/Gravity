#include<iostream>

//My imports
#include"Camera.h"

#pragma once

class Player
{
private:
	glm::vec3 position = glm::vec3(0.f);
	glm::vec3 viewDirection = glm::vec3(0.f, 0.f, -1.0f);
	glm::mat4 viewMatrix = glm::mat4(1.0f);
	const glm::vec3 upVector = UPVECTOR;

public:

	Player() = default;
	~Player() = default;
};

