/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/9/19
** Description: Specifies the FibonacciR class.
**		Derived from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*********************************************************************/
#ifndef FIBONACCIR_H_
#define FIBONACCIR_H_

class FibonacciR {
public:
	FibonacciR(const int &n);
	virtual ~FibonacciR();
	void PrintFibonacci();
private:
	FibonacciR();
	long double Fibonacci(const int &n);
	const int *n_;
};

#endif /* FIBONACCIR_H_ */