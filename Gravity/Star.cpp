#include "Star.h"

Star::Star(const char* filePath) : Body(filePath) {
	readData();
}

//Draw passes
void Star::draw() {
	draw();
	//alphaPass();
}

void Star::alphaPass() {

}

void Star::shadowMapPass() {

}

//Data
void Star::readParsedData(rapidjson::Document& doc) {

}