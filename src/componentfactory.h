#pragma once

// C/C++
#include <string>
#include <map>

#include "component.h"

class ComponentFactory {
	static ComponentFactory instance;
	ComponentFactory();
	~ComponentFactory();

public:
	static ComponentFactory *getInstance();

	void Initialize();

	// function pointer
	typedef Component* (*ComponentFactoryFunction)();

	static void RegisterComponentFactory(
		ComponentFactoryFunction factory,
		const std::string& componentName
		);

	Component* CreateComponentByName(const std::string& componentName);

private:
	std::map<std::string, ComponentFactoryFunction> functions;
};
