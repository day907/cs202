#pragma once

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <vector>
#include <iostream>

//Declarations
template <typename T>
void printVector(std::ostream& os, const std::vector<T> vec);


template <typename T>
class RAIIPtr {
	RAIIPtr(T*);
	~RAIIPtr();
	RAIIPtr(const RAIIPtr&) = delete;
	T operator*(RAIIPtr&);
	T* operator->();
};


//Definitions
template <typename T>
void printVector(std::ostream& os, const std::vector<T> vec) {
	for (const auto n : vec) {
		os << n << '\n';
	}
	return;
}

#endif // !TEMPLATE_HPP

