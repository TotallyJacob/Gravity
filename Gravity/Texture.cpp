#include "Texture.h"

void Texture::create(const char *path, unsigned int &textureId) {

	glGenTextures(1, &textureId);
	bind(textureId, GL_TEXTURE_2D);

	setParameters();

	int width, height, channel;

	stbi_set_flip_vertically_on_load(true);
	unsigned char *image = stbi_load(
		path, &width, &height, &channel, 0
	);

	if (image) {//if image loads correctly
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(image);
}

