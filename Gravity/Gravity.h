#include"Renderer.h"

#pragma once

class Gravity : public Renderer
{
private:

	void init() override;
	void loop() override;
	void cleanUp() override;

public:

	Gravity();
	~Gravity() = default;

};

