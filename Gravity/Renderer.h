#define GLEW_STATIC
#include"GL/glew.h"
#include"GLFW/glfw3.h"

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

	virtual void start();
	virtual int end();
};

