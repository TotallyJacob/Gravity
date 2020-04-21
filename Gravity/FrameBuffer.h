#define GLEW_STATIC
#include"GL/glew.h"
#include"GLFW/glfw3.h"

//My imports
#include"Texture.h"

#pragma once

class FrameBuffer
{
public:

	static void createFBOTexture(unsigned int &texture, Texture::Dimensions dim, unsigned int type = GL_DEPTH_COMPONENT);
	inline static void genFBO(unsigned int& fbo) {
		glGenFramebuffers(1, &fbo);
	}
	static void bindTextureToFBO(unsigned int& texture, unsigned int& fbo, unsigned int fboType = GL_DEPTH_ATTACHMENT);

	inline static void bind(unsigned int& fbo) {
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	}
	inline static void unbind() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
};

