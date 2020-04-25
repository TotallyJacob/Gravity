#include"Body.h"

#pragma once

class Planet : public Body
{
private:

	std::string modelName;
	unsigned int program = 0;
	
public:

	Planet(const char *filePath);
	~Planet() = default;

	void draw(unsigned int program) override;
	void shadowMapPass() override;
	void alphaPass() override;

};

