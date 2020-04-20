#include"Body.h"

#pragma once

class Planet : public Body
{
public:

	Planet(BodyData data, const char *modelName);
	~Planet() = default;

	void draw() override;
	void shadowMapPass() override;

private:
	unsigned int num_vertices = 0;

	void drawPass() override;
	void alphaPass() override;

};

