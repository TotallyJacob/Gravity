#include "Model.h"

Model::Model(const char *path, std::vector<float>& verts, bool usingNormals, bool usingUvs) 
	: verts(verts), OBJReader(path, usingNormals, usingUvs) {

	setData(path);

	vertices.clear();
}

/*
	PROTECTED
*/
void Model::addIndex(split_string string) {

	//Getting data from indexs
	split_string vertex_data[3];
	split(vertex_data[0], string[1], "/");
	split(vertex_data[1], string[2], "/");
	split(vertex_data[2], string[3], "/");

	//data
	unsigned int vertIndex = 0, uvIndex = 0, normalIndex = 0, type;
	//Push back a whole triangle/primitive to verts
	for (int i = 0; i < 3; i++) {
		//push vertex
		vertIndex = getIntegerValue(vertex_data[i].at(VERTEX)) - 1;
		verts.push_back(vertices.at(vertIndex).x);
		verts.push_back(vertices.at(vertIndex).y);
		verts.push_back(vertices.at(vertIndex).z);

		//push Uvs
		if (usingUvs) {
			uvIndex = getIntegerValue(vertex_data[i].at(UV)) - 1;
			verts.push_back(uvs.at(uvIndex).x);
			verts.push_back(uvs.at(uvIndex).y);
		}

		//Push normals
		if (usingNormals) {
			normalIndex = getIntegerValue(vertex_data[i].at(NORMAL)) - 1;
			verts.push_back(normals.at(normalIndex).x);
			verts.push_back(normals.at(normalIndex).y);
			verts.push_back(normals.at(normalIndex).z);
		}

	}

	num_verts += 3;
}