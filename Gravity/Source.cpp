#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include"stb.h"

#include<iostream>
#include"Gravity.h"

int main() {
	Gravity gravity;

	gravity.start();

	return gravity.end();
}