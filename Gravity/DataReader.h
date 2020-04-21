#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<ostream>

#include"rapidjson/document.h"
#include"rapidjson/reader.h"

#pragma once

class DataReader
{
protected:
	std::string filePath;

	virtual void readParsedData(rapidjson::Document &doc);

public:

	DataReader(const char* filePath);
	~DataReader() = default;

	void readData();
	rapidjson::Document getNestedJson(const char* data);
};

