#include "DataReader.h"

DataReader::DataReader(const char *filePath) : filePath(filePath) { }

void DataReader::readData() {

	std::vector<std::string> data(0);
	std::string line;
	std::ifstream file(filePath.c_str());

	if (file.is_open()) {

		while (getline(file, line))
			data.push_back(line);

		rapidjson::Document doc;
		doc.Parse(data.data()->c_str());

		readParsedData(doc);

	}

	file.close();
}

rapidjson::Document DataReader::getNestedJson(const char* data) {

	//Gets data
	rapidjson::Document doc;
	doc.Parse(data);

	return doc;
}

void DataReader::readParsedData(rapidjson::Document& doc) {}