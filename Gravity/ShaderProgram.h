#include"GL/glew.h"

#include<iostream>
#include<vector>
#include <fstream>
#include <sstream>

#pragma once

class ShaderProgram
{
private:
	unsigned int program = 0;

	//Util
	inline std::string split(const char*line, unsigned int split, const char* splitBy) {

		std::stringstream ss(line);
		std::string splitString;

		const char* value;

		unsigned int splitSoFar = 0;

		while (getline(ss, splitString, *splitBy)) {
			if (splitSoFar == split) {
				return splitString;
			}

			splitSoFar++;
		}
			

		return nullptr;
	}
	inline static const unsigned int getShaderType(std::string type) {
		if (type == "frag") 
			return GL_FRAGMENT_SHADER;
		
		if (type == "vert")
			return GL_VERTEX_SHADER;

		if (type == "geo")
			return GL_GEOMETRY_SHADER;
	}

	int getShader(const char* fileName);
public:

	ShaderProgram(std::vector<const char*> shaders);

	operator unsigned int() const { return program; }

};

