#include "Star.h"

Star::Star(const char* filePath) : Body(filePath) {
	Model m("sphere.obj", vertices, true, false);
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

	setModelMatrix(glm::vec3(0.1f, 0.1f, -1.f));
}

//Draw passes
void Star::draw(unsigned int program) {
	glBindVertexArray(vao);

	ShaderProgram::sendModelMatrix(program, &modelMatrix[0][0]);
	glUniform4f(glGetUniformLocation(program, "color"), 0.5f, 0.2f, 0.2f, 1.f);

	glDrawArrays(GL_TRIANGLES, 0, num_vertices);

	glBindVertexArray(0);
}

void Star::alphaPass() {

}

void Star::shadowMapPass() {

}
