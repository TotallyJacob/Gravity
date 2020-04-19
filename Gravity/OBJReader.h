//Standard Imports
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<vector>

//Matricies
#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtx/transform.hpp"

#pragma once

class OBJReader
{

protected:
	//Data types
	struct VertexData {

		glm::vec3 vertices;
		glm::vec3 normals;
		glm::vec2 uvs;

	};
	typedef std::vector<std::string> split_string;

	//Data
	bool usingNormals = false, usingUvs = false;
	/*
	Scoped inside the constructor
	*/
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

	//Util methods
	inline static void split(split_string& splited, std::string& line, const char* splitBy) {
			std::stringstream ss(line);
			std::string split;

			while (getline(ss, split, *splitBy))
				splited.push_back(split);
		}
	inline static int getIntegerValue(std::string string) {
		return strtoul(string.c_str(), 0, 10);
	}
	inline static int getIntegerValue(split_string split_string, unsigned int index) {
		return getIntegerValue(split_string.at(index));
	}

	//Main methods
	virtual void addIndex(split_string splittedLine); //Override this

private:

	//Util methods
	void setModelData(bool normals, bool uv) {
		this->usingNormals = normals;
		this->usingUvs = uv;
	}

	//Main methods
	void readModel(std::string line);
	void addVertex(split_string line);
	void addUv(split_string line);
	void addNormal(split_string line);

public:

	OBJReader(const char* fileName, bool normals = false, bool uvs = false);

	//Methods
	void setData(const char*fileName);
};

