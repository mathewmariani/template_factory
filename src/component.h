#pragma once

// C/C++
#include <string>

#define DECLARE_COMPONENT(name) \
    private: \
		static const std::string constClassName;

// # stringonizer
// ## tokenizer
#define REGISTER_COMPONENT(className, scriptName) \
	const std::string className::constClassName = #scriptName; \
	namespace { \
		Component* __CreateComponent##className() { \
			return new className(); \
		} \
		class __register##className { \
		public: \
			__register##className() { \
				ComponentFactory::RegisterComponentFactory( \
					*__CreateComponent##className, #scriptName); \
			} \
		}; \
		__register##className __g_instance##className; \
	}

class Component {
public:
	virtual ~Component() {}
};
