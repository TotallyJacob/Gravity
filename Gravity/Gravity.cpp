#include "Gravity.h"

Gravity::Gravity() : Renderer("Gravity", 1280, 720){

}

//Main
void Gravity::init() {

	//DataWriter::writeData("test.json");

}

void Gravity::loop() {

	ShaderProgram program({ "test.vert.shader","test.frag.shader" });
	Camera camera;
	camera.setLocation(glm::vec3(-2, 0, 0));

	glm::mat4 perspective = glm::perspective(60.f, 16.f/9.f, 0.1f, 100.f);
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.1f, 0.1f, -2));

	std::vector<float> verts(0);
	Model m("sphere.obj", verts, true, false);

	unsigned int vao = 0, vbo = 0;
	Buffers::Buffer b = { &vao, &vbo, verts };
	Buffers::createBuffers(b, true);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), (const void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (const void*)3);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.f, 0.f, 0.f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//Drawing
		glUseProgram(program);

		ShaderProgram::sendPerspectiveMatrix(program, &perspective[0][0]);
		ShaderProgram::sendViewMatrix(program, &((glm::mat4)camera)[0][0]);
		ShaderProgram::sendModelMatrix(program, &model[0][0]);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, m.getNumberOfVertices());

		glUseProgram(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Gravity::cleanUp() {
	glfwTerminate();
}