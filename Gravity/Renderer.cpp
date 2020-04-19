#include "Renderer.h"

Renderer::Renderer(const char*windowName, unsigned int width, unsigned int height) {
	if (initGLFW({ windowName, width, height }) != 0 || initGLEW() != 0) {
		setup = -1;
		return;
	}
	windowData = {windowName, width, height};
}

void Renderer::start() {
	init();
	loop();
	cleanUp();
}
int Renderer::end() {
	return setup;
}

//private
int Renderer::initGLFW(WindowData data) {
	if (!glfwInit()) {
		glfwTerminate();
		return -1;
	}


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(data.width, data.height, data.windowName, NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwShowWindow(window);

	return 0;
}
int Renderer::initGLEW() {
	int code = glewInit();

	if (code != GLEW_OK) {
		LOG(glewGetErrorString(code));
		return -1;
	}

	return 0;
}