#include "factory.h"
#include "componentfactory.h"

namespace {
	struct component_factory_register :
		public template_factory_register<ComponentFactory::ComponentFactoryFunction, component_factory_register> {
	};

	component_factory_register begin;
}

// still a work in progress
//DECLARE_FACTORY(ComponentFactory)

ComponentFactory ComponentFactory::instance;
ComponentFactory *ComponentFactory::getInstance() {
	return &instance;
}

ComponentFactory::ComponentFactory() {

}

ComponentFactory::~ComponentFactory() {

}

void ComponentFactory::Initialize() {
	ConvertListToMap(&begin, functions);
}

void ComponentFactory::RegisterComponentFactory(ComponentFactoryFunction factory, const std::string& componentName) {
	RegisterFactory(&begin, factory, componentName);
}

Component* ComponentFactory::CreateComponentByName(const std::string& componentName) {
	if (functions[componentName] == 0) {
		return nullptr;
	}

	ComponentFactoryFunction func = functions[componentName];
	return func();
}
