/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/9/19
** Description: Implements source code FibonacciR class.
**		Derived from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*********************************************************************/
#include "FibonacciR.hpp"
#include <iostream>

FibonacciR::FibonacciR() {}

FibonacciR::FibonacciR(const int &n) :n_(&n) {}

FibonacciR::~FibonacciR() {}

long double FibonacciR::Fibonacci(const int &n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
void FibonacciR::PrintFibonacci() {
	long double FibonacciNum = Fibonacci(*n_);
	std::cout << "--Fibonacci iteration " << *n_ << " is: " << FibonacciNum << std::endl;
}