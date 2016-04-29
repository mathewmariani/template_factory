#pragma once

// C/C++
#include <iostream>

#include "component.h"

class Body : public Component {
	DECLARE_COMPONENT(Body);

public:
	Body() {
		printf("Body Component created.\n");
	}
	~Body() {}
};

REGISTER_COMPONENT(Body, body);