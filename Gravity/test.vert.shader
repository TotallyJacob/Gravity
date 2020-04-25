#version 410 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normals;

uniform mat4 modelMatrix;
uniform mat4 perspectiveMatrix;
uniform mat4 viewMatrix;

//Outs
out vec3 normal;

void main() {

	normal = normals;
	gl_Position = perspectiveMatrix * viewMatrix * modelMatrix * vec4(pos, 1.0f);
}