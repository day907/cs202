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
private:
	Ptrtype* _ptr;
};



//RAIIPtr member functions
template <typename Ptrtype>
RAIIPtr<Ptrtype>::RAIIPtr(Ptrtype* ptr) :  _ptr(ptr) {};

template <typename Ptrtype>
RAIIPtr<Ptrtype>::~RAIIPtr() {};

//RAIIPtr operator overloads
template <typename Ptrtype>
Ptrtype operator*(RAIIPtr<Ptrtype>& ptr) {
	return *_ptr;
}

//template <typename Ptrtype>
//Ptrtype* operator->() {
//	return 
//}

#endif // !TEMPLATE_HPP

