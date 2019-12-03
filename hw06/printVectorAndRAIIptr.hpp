#pragma once

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <vector>
#include <iostream>

//Declarations
template <typename T>
void printVector(std::ostream& os, const std::vector<T> vec);


//Definitions
template <typename T>
void printVector(std::ostream& os, const std::vector<T> vec) {
	for (const auto n : vec) {
		os << n << '\n';
	}
	return;
}

#endif // !TEMPLATE_HPP

