#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normals;

uniform mat4 mvp;

//Outs
out vec3 normal;

void main() {

	normal = normals;
	gl_Position = mvp * vec4(pos, 1.0f);
}