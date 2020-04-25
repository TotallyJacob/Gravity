#define GLEW_STATIC
#include"GL/glew.h"
#include"GLFW/glfw3.h"
#include"GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtx/transform.hpp"

#include<iostream>

//defines
#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

#pragma once

class Renderer
{
private:

	struct WindowData;

	unsigned int setup = 0;

	int initGLFW(WindowData data);
	int initGLEW();

protected:

	glm::mat4 perspectiveMatrix;
	glm::mat4 viewMatrix;

	struct WindowData {
		const char* windowName;
		unsigned int width, height;
	};

	GLFWwindow *window;
	WindowData windowData;

	//Main loop
	virtual void init() = 0;
	virtual void loop() = 0;
	virtual void cleanUp() = 0;

public:

	explicit Renderer(const char* windowName, unsigned int width, unsigned int heights);

	void start();
	int end();
};

