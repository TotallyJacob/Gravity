#include "Body.h"

Body::Body(const char* dataFilePath)
	: DataReader(dataFilePath), position(1.f), modelMatrix(1.f), vertices(0) {
}
