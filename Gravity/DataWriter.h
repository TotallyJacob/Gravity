#include<iostream>
#include<ostream>
#include<fstream>
#include<sstream>
#include<vector>

#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#pragma once

class DataWriter
{
protected:

	using StringBufferWriter = rapidjson::PrettyWriter <rapidjson::StringBuffer>;
	using DefaultStringBufferWriter = rapidjson::Writer <rapidjson::StringBuffer>;

	std::string filePath;

	virtual void writeJsonData(StringBufferWriter& writer);
	const void writeNestedJson(StringBufferWriter& currentWriter, void(*func)(DefaultStringBufferWriter& newWriter));

public:

	DataWriter(const char *filePath);
	~DataWriter() = default;

	void writeData();
};

