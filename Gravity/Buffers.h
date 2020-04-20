#include"GL/glew.h"
#include<iostream>
#include<vector>
#include<array>

#pragma once

class Buffers {

public:

	//Element
	struct EboBuffers {
		unsigned int& vao;
		unsigned int& vbo;
		unsigned int& ibo;
	};
	struct Element {
		EboBuffers ebo;
		std::vector<float> vertices;
		std::vector<unsigned int> indices;
	};

	inline static Element getElement(EboBuffers ebo,
		std::vector<float> &vertices, std::vector<unsigned int> &indices){

		return Element{ebo, vertices, indices};
	}

	inline static void deleteElement(EboBuffers element) {
		glDeleteVertexArrays(1, &element.vao);
		glDeleteBuffers(1, &element.vbo);
		glDeleteBuffers(1, &element.ibo);

	}

	inline static void createElement(Element element, bool leaveBinded = false, unsigned int drawType = GL_STATIC_DRAW) {
		//Creation
		glGenVertexArrays(1, &element.ebo.vao);
		glGenBuffers(1, &element.ebo.vbo);
		glGenBuffers(1, &element.ebo.ibo);

		//bindings
		glBindVertexArray(element.ebo.vao);
		glBindBuffer(GL_ARRAY_BUFFER, element.ebo.vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element.ebo.ibo);

		//Attaching data
		glBufferData(GL_ARRAY_BUFFER, element.vertices.size() * sizeof(float), &element.vertices.front(), drawType);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, element.indices.size() * sizeof(unsigned int), &element.indices.front(), drawType);
	}

	//Normal
	struct Buffer {
		unsigned int *vao;
		unsigned int *vbo;
		std::vector<float> vertices;
	};

	inline static void createBuffers(Buffer buffer, bool leaveBinded = false, unsigned int drawType = GL_STATIC_DRAW) {
		glGenVertexArrays(1, buffer.vao);
		glGenBuffers(1, buffer.vbo);

		//bindings
		glBindVertexArray(*buffer.vao);
		glBindBuffer(GL_ARRAY_BUFFER, *buffer.vbo);

		//Attaching data
		glBufferData(GL_ARRAY_BUFFER, buffer.vertices.size() * sizeof(float), &buffer.vertices.front(), drawType);

		if (!leaveBinded)
			unbindBuffer();
		
	}

	inline static void bufferData(std::vector<float> data, unsigned int drawType = GL_STATIC_DRAW) {
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data.front(), drawType);
	}

	inline static void unbindBuffer() {
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
};

