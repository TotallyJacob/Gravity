#include "PlanetSystem.h"
PlanetSystem::PlanetSystem() {
	Planet planet("Planet.json");

	bodies.push_back(planet);
}

void PlanetSystem::draw(unsigned int program) {
	for (auto body : bodies) {
		body.draw(program);
		body.alphaPass();
	}

}

void PlanetSystem::shadowMapPass() {

}