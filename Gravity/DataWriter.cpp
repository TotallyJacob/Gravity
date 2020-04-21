#include "DataWriter.h"

void DataWriter::writeData(const char* filePath) {

	std::ofstream fileCreate(filePath);
	fileCreate.close();

	rapidjson::StringBuffer s;
	StringBufferWriter writer(s);

	//Setting data
	writer.StartObject();
	writeData(writer);
	writer.EndObject();

	//Opening file
	std::ofstream file;
	file.open(filePath);

	//Writing to file
	if (file.is_open())
		file << s.GetString();

	//Closing file
	file.close();
}

void DataWriter::writeData(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) {

	writer.Key("RenderingInfo");
	addNestedJson(writer,

		[](DefaultStringBufferWriter& newWriter) {
			newWriter.Key("modelFile");
			newWriter.Key("sphere.obj");
		});

	writer.Key("PlanetInfo");

	addNestedJson(writer,
		[](DefaultStringBufferWriter& newWriter) {

			newWriter.Key("Radius");
			newWriter.Uint(69);

		});

}