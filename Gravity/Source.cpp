#define GLEW_STATIC

#include<iostream>
#include"Gravity.h"

int main() {
	Gravity gravity;

	gravity.start();

	return gravity.end();
}