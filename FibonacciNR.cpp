/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/9/19
** Description: Implements source code FibonacciNR class. 
**		Derived from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*********************************************************************/
#include "FibonacciNR.hpp"
#include <iostream>

FibonacciNR::FibonacciNR() {

}

FibonacciNR::FibonacciNR(const int &n) :n_(&n) {

}

FibonacciNR::~FibonacciNR() {}

long double FibonacciNR::Fibonacci(const int &n) {
	long double first = 0;
	long double second = 1;
	int counter = 2;
	while (counter < n) {
		long double temp = second;
		second = first + second;
		first = temp;
		++counter;
		
	}

	if (n == 0)
		return 0;
	else
		return first + second;
}
void FibonacciNR::PrintFibonacci() {
	const long double result = Fibonacci(*n_);
	std::cout << "--Fibonacci iteration "<< *n_ << " is: " << result << std::endl;
}