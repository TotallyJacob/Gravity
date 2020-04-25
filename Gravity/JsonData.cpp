#include "JsonData.h"

void JsonData::read(rapidjson::Document &doc, const char *fileName){
	
	std::ifstream file(fileName, std::ios::binary);
	std::streambuf* raw_buffer = file.rdbuf();


	file.seekg(0, std::ios::end);
	unsigned int length = file.tellg();
	file.seekg(0, std::ios::beg);

	char* data = new char[length];

	raw_buffer->sgetn(data, length);

	doc.Parse(data, length);

	file.close();

	delete[] data;
}

void JsonData::read(rapidjson::Document *doc, const char** filePaths, unsigned int num_files) {
	std::ifstream* files = new std::ifstream[num_files];

	unsigned int length_total = 0;
	unsigned int* lengths = new unsigned int[num_files];
	for (int i = 0; i < num_files; i++) {
		files[i] = std::ifstream(filePaths[i], std::ios::in | std::ios::binary);

		files[i].seekg(0, std::ios::end);

		//Assigning lengths
		unsigned int length = files[i].tellg();
		length_total += length;
		lengths[i] = length;

		files[i].seekg(0, std::ios::beg);
	}
	
	// @TODO Allocate one large buffer, then add 
	//seperated char buffer chunks to it(speed up)
	//void* m_start_ptr = malloc(length_total);
	//char* buffer = (char*)m_start_ptr;
	for (int i = 0; i < num_files; i++) {
		char* buffer = new char[lengths[i]];

		//Reading buffer
		std::streambuf* raw_buffer = (&files[i])->rdbuf();
		raw_buffer->sgetn(buffer, lengths[i]);

		doc[i].Parse(buffer, lengths[i]);

		delete[] buffer;
		files->close(); // @TODO look at puting this into another loop
	}

	delete[] lengths;
	delete[] files;
}

void JsonData::write(rapidjson::StringBuffer& buffer, const char* file) {

	auto myfile = std::fstream(file, std::ios::out | std::ios::binary);

	myfile.write((char*)&buffer.GetString()[0], buffer.GetSize());

	myfile.close();

}