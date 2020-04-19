#include "Gravity.h"

Gravity::Gravity() : Renderer("Gravity", 1280, 720){

}

//Main
void Gravity::init() {

}

void Gravity::loop() {
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.f, 0.f, 0.f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//Drawing


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Gravity::cleanUp() {
	glfwTerminate();
}