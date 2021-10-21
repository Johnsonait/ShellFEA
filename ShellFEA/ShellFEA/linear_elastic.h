#pragma once

#include "matrix.h"
#include "body.h"

class LinearElastic
{
private:
	Body* body_ptr;
public:
	LinearElastic() = default;
	LinearElastic(Body* bod_ptr);
	~LinearElastic() = default;
	void Solve();
};

