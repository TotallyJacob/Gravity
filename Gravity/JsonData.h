#include<iostream>
#include<vector>
#include<fstream>
#include<streambuf>
#include<sstream>

//Rapid Json
#include"rapidjson/document.h"
#include"rapidjson/reader.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#pragma once

class JsonData
{
public:

	static void read(rapidjson::Document &doc, const char *file);

	static void read(rapidjson::Document *doc, const char **file, unsigned int num_files);


	static void write(rapidjson::StringBuffer &buffer, const char *file);
};

