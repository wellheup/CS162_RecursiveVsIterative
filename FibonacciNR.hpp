/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/9/19
** Description: Specifies the FibonacciNR class.
**		Derived from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*********************************************************************/


#ifndef FIBONACCINR_H_
#define FIBONACCINR_H_
class FibonacciNR {
public:
	FibonacciNR(const int &n);
		virtual ~FibonacciNR();
		void PrintFibonacci();
private:
	FibonacciNR();
	long double Fibonacci(const int &n);
	const int* n_;
};
#endif /* FIBONACCINR_H_ */