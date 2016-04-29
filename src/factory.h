#pragma once

// C/C++
#include <map>
#include <string>

// still a work in progress
#define DECLARE_FACTORY(className) \
	namespace { \
		struct __register : \
			public template_factory_register<className::className##Function, __register> { \
		}; \
		__register begin; \
	}

template <class T, class Node>
struct template_factory_register {
	// for function pointers just use a quick dynamic list
	// curtosiy of some post i can't find on stackoverflow
	T function;
	std::string name;

	Node* next;
};

template <class T, class D>
inline void ConvertListToMap(T *begin, std::map<std::string, D> &map) {

	// begin will always be null
	auto* current = begin->next;
	while (current != nullptr) {
		T* temp = current;

		// add to the map
		map.insert(std::pair<std::string, D>(
			temp->name,
			temp->function
			));

		// iterate
		current = current->next;

		// free the memory
		delete temp;
	}

	begin->next = nullptr;
}

template <class R, class F>
inline void RegisterFactory(R* begin, F function, const std::string& name) {
	R* r = new R;
	r->function = function;
	r->name = name;
	r->next = nullptr;

	auto* itr = begin;
	while (itr->next != nullptr) {
		itr = itr->next;
	}

	itr->next = r;
}