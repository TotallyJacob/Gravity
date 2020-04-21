#include "Body.h"

Body::Body(const char* dataFilePath)
	: BodyData(dataFilePath), position(1.f), modelMatrix(1.f), vertices(0) {
}
