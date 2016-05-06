// C/C++
#include <iostream>

#include "componentfactory.h"
#include "transform.h"
#include "body.h"

int main() {
	printf("Hello, World!\n");

	ComponentFactory::getInstance()->Initialize();

	Transform* transform = (Transform*)ComponentFactory::getInstance()->CreateComponentByName("transform");
	Body* body = (Body*)ComponentFactory::getInstance()->CreateComponentByName("body");

	delete transform;
	delete body;
	
	return EXIT_SUCCESS;
}
