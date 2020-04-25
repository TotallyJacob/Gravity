
//My imports
#include"Body.h"
#include"Camera.h"

#pragma once

class Star : public Body
{
private:
	glm::mat4 lightProjectionMatrix;

	void shadowMapPass() override;

public:

	Star(const char *filePath);
	~Star() = default;

	glm::mat4 getLightViewMatrix(glm::vec3 lookAtPosition) const {
		return glm::lookAt(position, position, UPVECTOR);
	}

	void draw(unsigned int program) override;
	void alphaPass() override;
};

