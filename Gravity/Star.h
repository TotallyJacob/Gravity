
//My imports
#include"Body.h"
#include"Camera.h"

#pragma once

class Star : public Body
{
private:
	glm::mat4 lightProjectionMatrix;

	void shadowMapPass() override;
	void readParsedData(rapidjson::Document& doc) override;
	void writeJsonData(StringBufferWriter &writer) override;

public:

	Star(const char *filePath);
	~Star() = default;

	glm::mat4 getLightViewMatrix(glm::vec3 lookAtPosition) const {
		return glm::lookAt(position, position, UPVECTOR);
	}

	void draw() override;
	void alphaPass() override;
};

