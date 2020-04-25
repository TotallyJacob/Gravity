#version 410 core

layout(triangles, equal_spacing, ccw) in;

in vec4 tcPos[];

vec4 bezier2(vec4 a, vec4 b, float t) {
	return mix(a, b, t);
}
vec4 bezier3(vec4 a, vec4 b, vec4 c, float t) {
	return mix(bezier2(a, b, t), bezier2(b, c, t), t);
}

vec4 bezier(float u, vec4 p0, vec4 p1, vec4 p2, vec4 p3)
{
	float B0 = (1. - u) * (1. - u) * (1. - u);
	float B1 = 3. * u * (1. - u) * (1. - u);
	float B2 = 3. * u * u * (1. - u);
	float B3 = u * u * u;

	vec4 p = B0 * p0 + B1 * p1 + B2 * p2 + B3 * p3;
	return p;
}

void main()
{

	gl_Position.xyzw =
		/*(gl_in[0].gl_Position.xyzw * gl_TessCoord.x +
			gl_in[1].gl_Position.xyzw * gl_TessCoord.y +
			gl_in[2].gl_Position.xyzw * gl_TessCoord.z) **/
		bezier(gl_TessCoord.x, tcPos[0], tcPos[1], tcPos[2], tcPos[2]);
}
