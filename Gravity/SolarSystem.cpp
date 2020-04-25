#include "SolarSystem.h"
SolarSystem::SolarSystem(const char* dataFilePath) {
	ShaderProgram _program(
		{
			"test.vert.shader",
			"test.frag.shader"
		});
	program = _program;

	PlanetSystem system;

	planetSystems.push_back(system);

	Star star("Star.json");

	stars.push_back(star);
}

void SolarSystem::draw(Camera &camera, const float* perspective) {

	glUseProgram(program);

	ShaderProgram::sendPerspectiveMatrix(program, perspective);
	ShaderProgram::sendViewMatrix(program, &((glm::mat4)camera)[0][0]);

	for (auto star : stars)
		star.draw(program);

	for (auto planetSystem : planetSystems) 
		planetSystem.draw(program);

	glUseProgram(0);
}
