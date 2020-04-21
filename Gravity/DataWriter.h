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

private:

	static void addNestedJson(StringBufferWriter &currentWriter, void(*func)(DefaultStringBufferWriter& newWriter)) {
		rapidjson::StringBuffer stringBuffer;
		DefaultStringBufferWriter writer(stringBuffer);
		writer.StartObject();
		func(writer);
		writer.EndObject();

		currentWriter.String(stringBuffer.GetString());
	}

public:

	static void writeData(const char* filePath);

	static void writeData(StringBufferWriter& writer);

};

