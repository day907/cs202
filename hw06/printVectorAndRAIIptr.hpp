#pragma once

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <vector>
#include <iostream>

//	printVector
//Declaration
template <typename T>
void printVector(std::ostream& os, const std::vector<T> vec);


//Definition
template <typename T>
void printVector(std::ostream& os, const std::vector<T> vec) {
	for (const auto n : vec) {
		os << n << '\n';
	}
	return;
}


//	RAIIPtr
//Declaration
template <typename Ptrtype>
class RAIIPtr {
public:
	RAIIPtr(Ptrtype*);
	~RAIIPtr();
	RAIIPtr(const RAIIPtr&) = delete;
	Ptrtype& operator*();
	Ptrtype* operator->();
private:
	Ptrtype* _ptr;
};



//RAIIPtr member functions
template <typename Ptrtype>
RAIIPtr<Ptrtype>::RAIIPtr(Ptrtype* ptr) :  _ptr(ptr) {};

template <typename Ptrtype>
RAIIPtr<Ptrtype>::~RAIIPtr() {
	delete _ptr;
};

//RAIIPtr operator overloads
template <typename Ptrtype>
Ptrtype& RAIIPtr<Ptrtype>::operator*() {
	return *_ptr;
}

template <typename Ptrtype>
Ptrtype* RAIIPtr<Ptrtype>::operator->() {
	return _ptr;
}

#endif // !TEMPLATE_HPP

