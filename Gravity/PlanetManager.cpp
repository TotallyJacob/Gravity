#include "PlanetManager.h"

PlanetManager::PlanetManager() 
	: active_planets(0), planets(0), transformingPlanets(0), data{ glm::vec3(0.f, 0.f, 0.f) }{
	std::cout << sizeof(Planet) << std::endl;
}

//OpenGL
void PlanetManager::drawPlanets() {
	for (Planet planet : active_planets) {
		glBindVertexArray(planet.vao);

		glDrawArrays(GL_TRIANGLES, 0, planet.num_vertices);
	}

	for (TransformingPlanet planet : transformingPlanets) {
		glBindVertexArray(planet.vao);
		glDrawArrays(GL_TRIANGLES, 0, planet.num_vertices);

		glBindVertexArray(planet.newVao);
		glDrawArrays(GL_TRIANGLES, 0, planet.newNum_vertices);

		planet.update_num++;
	}

	glBindVertexArray(0);
}
void PlanetManager::drawPlanet(unsigned int id) {

	Planet planet = active_planets.at(id);

	glBindVertexArray(planet.vao);

	glDrawArrays(GL_TRIANGLES, 0, planet.num_vertices);

	glBindVertexArray(0);
}
void PlanetManager::updateActivePlanets() {

	for (Planet planet : active_planets) {
		if (glm::distance(planet.position, data.playerPosition) >= 10) {
			
			transformingPlanets.push_back(planet);
		}
	}

}

//Data
void PlanetManager::readPlanetsData(const char** dataFileNames, unsigned int num_dataFiles) {

	using Document =  rapidjson::Document;
	Document *docs = new Document[num_dataFiles];

	JsonData::read(docs, dataFileNames, num_dataFiles);

	for (int i = 0; i < num_dataFiles; i++) {

		if (!docs[i].HasParseError()) {

			const rapidjson::Value& val = docs[i]["Model"];
			val.GetString();

		}

	}
}
void PlanetManager::savePlanetsToDisk() {
	for (Planet planet: planets) {
		using Writer = rapidjson::PrettyWriter <rapidjson::StringBuffer>;
		using Buffer = rapidjson::StringBuffer;
		
		Buffer buffer;
		//buffer.Reserve();

		Writer writer(buffer);
		writer.StartObject();
		writer.Key("Model");
		writer.String("sphere.obj");
		writer.EndObject();

		JsonData::write(buffer, "");
	
	}
}