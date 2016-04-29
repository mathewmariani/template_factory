#pragma once

// C/C++
#include <iostream>

#include "component.h"

class Transform : public Component {
	DECLARE_COMPONENT(Transform);

public:
	Transform() {
		printf("Transform Component created.\n");
	}
	~Transform() {}
};

REGISTER_COMPONENT(Transform, transform);