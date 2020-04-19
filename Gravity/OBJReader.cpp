#include "OBJReader.h"

OBJReader::OBJReader(const char* path, bool normals, bool uvs) {

	//Setting boolean values
	setModelData(normals, uvs);
}

void OBJReader::setData(const char* path) {

	vertices = std::vector<glm::vec3>(0);
	normals = std::vector<glm::vec3>(0);
	uvs = std::vector <glm::vec2>(0);

	std::fstream stream(path);
	std::stringstream stringStream[1];

	std::string line;

	while (getline(stream, line))
		readModel(line);

	uvs.clear();
	normals.clear();
}

/*
PRIVATE
*/

//Reading
void OBJReader::readModel(std::string line) {

	//Splits line for each space
	split_string splitedLine;
	split(splitedLine, line, " ");

	if (splitedLine.at(0) == "v")
		addVertex(splitedLine);

	if (usingUvs && splitedLine.at(0) == "vt")
		addUv(splitedLine);

	if (usingNormals && splitedLine.at(0) == "vn")
		addNormal(splitedLine);

	if (splitedLine.at(0) == "f") 
		addIndex(splitedLine);
	
}

//Data
void OBJReader::addVertex(split_string line) {
	const float x = atof(line.at(1).c_str());
	const float y = atof(line.at(2).c_str());
	const float z = atof(line.at(3).c_str());

	vertices.push_back(glm::vec3(x, y, z));

}
void OBJReader::addNormal(split_string line) {
	const float x = atof(line.at(1).c_str());
	const float y = atof(line.at(2).c_str());
	const float z = atof(line.at(3).c_str());

	normals.push_back(glm::vec3(x, y, z));
}
void OBJReader::addUv(split_string line) {
	const float uv1 = atof(line.at(1).c_str());
	const float uv2 = atof(line.at(2).c_str());

	uvs.push_back(glm::vec2(uv1, uv2));
}

/*
	PROTECTED
*/
void OBJReader::addIndex(split_string line) {}