#include"Body.h"

#pragma once

class Planet : public Body
{
private:
	unsigned int num_vertices = 0;

	void readParsedData(rapidjson::Document& doc) override;
	
public:

	Planet(const char *filePath);
	~Planet() = default;

	void draw() override;
	void shadowMapPass() override;
	void alphaPass() override;

};

