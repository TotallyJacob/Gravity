#include "Star.h"

Star::Star(const char* filePath) : Body(filePath) {
	readData();
}

//Draw passes
void Star::draw() {

}

void Star::alphaPass() {

}

void Star::shadowMapPass() {

}

//Data
void Star::readParsedData(rapidjson::Document& doc) {

}

void Star::writeJsonData(StringBufferWriter& writer) {

}