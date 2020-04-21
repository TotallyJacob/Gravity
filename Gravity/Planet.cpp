#include "Planet.h"
Planet::Planet(const char* filePath) : Body(filePath) {
	readData();

	//Set dat
	//Model m(modelName, vertices, true, false);
	//num_vertices = m.getNumberOfVertices();

	//Create vao, vbo etc
	Buffers::Buffer buffer = {
		&vao,
		&vbo,
		vertices
	};

	Buffers::createBuffers(buffer, true);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 6, (const void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(float) * 6, (const void*)3);

	Buffers::unbindBuffer();
}

//Render passes
void Planet::draw() {
	glBindVertexArray(vao);

	ShaderProgram::sendModelMatrix(0, &modelMatrix[0][0]);

	glDrawArrays(GL_TRIANGLES, 0, num_vertices);

	glBindVertexArray(0);
}

void Planet::alphaPass() {

}

void Planet::shadowMapPass() {

}

//Data
void Planet::readParsedData(rapidjson::Document &doc) {

}

void Planet::writeJsonData(StringBufferWriter &writer) {

}