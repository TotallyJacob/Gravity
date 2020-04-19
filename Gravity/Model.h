#include"OBJReader.h"

#pragma once

class Model : public OBJReader
{

protected:
	//Data
	std::vector<float>& verts;
	unsigned int num_verts = 0;

	//Main methods
	void addIndex(split_string string) override;

public:

	Model(const char* path, std::vector<float>& verts,
		bool usingNormals = false, bool usingUvs = false);

	const unsigned int getNumberOfVertices() const {
		return num_verts;
	}
};

