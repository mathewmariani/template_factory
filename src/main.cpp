// C/C++
#include <iostream>

#include "componentfactory.h"
#include "transform.h"
#include "body.h"

int main() {
	printf("Hello, World!\n");

	ComponentFactory::getInstance()->Initialize();

	ComponentFactory::getInstance()->CreateComponentByName("transform");
	ComponentFactory::getInstance()->CreateComponentByName("body");

	return EXIT_SUCCESS;
}