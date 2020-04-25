#version 410 core

layout(vertices = 3) out;

out vec4 tcPos[];

void main(void)
{
	if (gl_InvocationID == 0) {
		gl_TessLevelOuter[0] = 1.0f;
		gl_TessLevelOuter[1] = 100.0;
		//gl_TessLevelOuter[2] = 10.0;

		//gl_TessLevelInner[0] = 3.0;
	}

	tcPos[gl_InvocationID] = gl_in[gl_InvocationID].gl_Position;

	gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}