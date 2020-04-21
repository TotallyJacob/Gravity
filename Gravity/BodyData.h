#include"DataReader.h"
#include"DataWriter.h"

#pragma once

class BodyData : public DataReader, public DataWriter 
{
public:

	BodyData(const char* filePath);
	~BodyData() = default;

};

