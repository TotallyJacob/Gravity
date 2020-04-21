#include "DataWriter.h"

DataWriter::DataWriter(const char *filePath) : filePath(filePath) {

}

void DataWriter::writeData() {

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

void DataWriter::writeJsonData(StringBufferWriter& writer) {

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

//Protected
const void DataWriter::writeNestedJson(StringBufferWriter& currentWriter, void(*func)(DefaultStringBufferWriter& newWriter)) {
	rapidjson::StringBuffer stringBuffer;
	DefaultStringBufferWriter writer(stringBuffer);
	writer.StartObject();
	func(writer);
	writer.EndObject();

	currentWriter.String(stringBuffer.GetString());
}
