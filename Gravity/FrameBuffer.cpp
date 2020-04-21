#include "FrameBuffer.h"

void FrameBuffer::createFBOTexture(unsigned int &texture, Texture::Dimensions dim, unsigned int type) {
	
	Texture::create(texture, dim, type);
}

void FrameBuffer::bindTextureToFBO(unsigned int& texture, unsigned int& fbo, unsigned int type) {
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glFramebufferTexture2D(GL_FRAMEBUFFER, type, GL_TEXTURE_2D, texture, 0);
	
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}