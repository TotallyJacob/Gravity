#pragma once
class Body
{
protected:
	unsigned int vao = 0;

public:
	struct BodyData {

	};

	Body(BodyData data);
	~Body() = default;

	virtual void draw() = 0;
};

