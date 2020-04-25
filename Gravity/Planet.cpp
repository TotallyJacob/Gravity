#include "Planet.h"
Planet::Planet(const char* filePath) : Body(filePath), modelName("nah") {

	Model m(modelName.c_str(), vertices, true, false);
	num_vertices = m.getNumberOfVertices();

	//Create vao, vbo etc
	Buffers::Buffer buffer = {
		&vao,
		&vbo,
		vertices
	};

	Buffers::createBuffers(buffer, true);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 6, (const void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(float) * 6, (const void*)3);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	Buffers::unbindBuffer();

	setModelMatrix(glm::vec3(0.f, 0.1f, -1.f));
}

//Render passes
void Planet::draw(unsigned int _program) {
	program = _program;

	glBindVertexArray(vao);

	ShaderProgram::sendModelMatrix(program, &modelMatrix[0][0]);
	glUniform4f(glGetUniformLocation(program, "color"), 1.0f, 1.0f, 1.0f, 1.0f);

	glDrawArrays(GL_TRIANGLES, 0, num_vertices);

	glBindVertexArray(0);
}

void Planet::alphaPass() {

	glm::mat4 tempModelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.01f)) * modelMatrix;

	glBindVertexArray(vao);

	ShaderProgram::sendModelMatrix(program, &tempModelMatrix[0][0]);
	glUniform4f(glGetUniformLocation(program, "color"), 0.0f, 0.0f, 1.0f, 0.5f);

	glDrawArrays(GL_TRIANGLES, 0, num_vertices);

	glBindVertexArray(0);
	
}

void Planet::shadowMapPass() {

}
