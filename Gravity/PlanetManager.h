#include<iostream>
#include<vector>

//External APIs
#include"GL/glew.h"
#include"GLFW/glfw3.h"
#include"GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtx/transform.hpp"

//My imports
#include"JsonData.h"

#pragma once

class PlanetManager
{
private:

	struct PlanetManagerData {
		glm::vec3 playerPosition;
	};

	PlanetManagerData data;

	//Standard planet
	struct Planet { //84 bytes
		unsigned int vao;
		unsigned int num_vertices;
		glm::vec3 position;
		glm::mat4 modelMatrix;
	};

	//Used when updating a planets mesh smoothly
	struct TransformingPlanet {
		unsigned int newVao;
		unsigned int newNum_vertices;
		unsigned int update_num;
		unsigned int vao;
		unsigned int num_vertices;
		glm::vec3 position;
		glm::mat4 modelMatrix;
	};

	std::vector<TransformingPlanet> transformingPlanets;
	std::vector<Planet> active_planets;
	std::vector<Planet> planets;
	

public:
	PlanetManager();
	~PlanetManager() = default;

	//OpenGL functions
	void drawPlanet(unsigned int id);

	void drawPlanets();

	//Updates
	void updateActivePlanets();

	// @TODO remove the inline
	inline void updateData(glm::vec3 cameraPosition) {
		data.playerPosition = cameraPosition;
	}

	// @TODO remove the inline
	inline void addPlanetToUpdate(unsigned int id) {
		active_planets.push_back(planets.at(id));
	}
	inline void removePlanetFromUpdate(unsigned int id) {
		active_planets.erase(active_planets.begin() + id);
	}

	void readPlanetsData(const char **planets, unsigned int num_planets);
	void savePlanetsToDisk();
};

