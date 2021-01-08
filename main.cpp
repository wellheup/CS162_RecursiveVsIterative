
/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/9/19
** Description: Runs a recursive and an iterative Fibonacci sequence
**		generator and measures the time it takes to run each. Code 
**		derived from  https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <cmath>
#include <iomanip>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"
#include "menuShell.hpp"
using namespace std;

double recursiveFib(int userIn);
double nonRecursiveFib(int userIn);
int runAlgoNTimes = 1;

int main() {
	std::cout << "Please provide numbers at which you'd like to start and stop \n\tdisplaying Fibonacci calculation times." << std::endl;
	const int startSequencesAt = chooseIntInRange("Start at sequence number: ", 0, 100);	
	const int endSequencesAt = chooseIntInRange("End at sequence number: ", 0, 100);
	runAlgoNTimes = chooseIntInRange("Please enter a number of times to average the algorithm run time over: ", 0, 100);
	//int n = 0;
	std::vector<std::vector <long double>> resultsTable; 
	resultsTable.resize(4);
	for (int i = startSequencesAt; i < endSequencesAt+1; i++) {
		try {
			cout << "Finding Fibonacci iteration "<< i <<":" << endl;
			resultsTable[0].push_back(i);
			resultsTable[1].push_back(recursiveFib(i));
			resultsTable[2].push_back(nonRecursiveFib(i));
			double temp = resultsTable[1][resultsTable[1].size()-1] - resultsTable[2][resultsTable[2].size()-1];
			resultsTable[3].push_back(temp);
		}
		catch (...) {
			cout << "Oops an error occured!" << endl;     
			std::cout << "Iteration       Recursive       Iterative       (R-!R)ns" << std::endl;
			for (unsigned int i = 0; i < resultsTable[1].size(); i++) {
				for (unsigned int j = 0; j < resultsTable.size(); j++) {
					std::cout << resultsTable[j][i] << "\t\t";
				}
				std::cout << "\n";
			}
			cout << "Press Enter to end program...";
			cin.ignore();
			return 1;
		}
	}

  //print final results
	std::cout << "N\t\t\tRecursive\tIterative\tRecursive-Iterative(ns)" << std::endl;
	for (unsigned int i = 0; i < resultsTable[1].size(); i++) {
		for (unsigned int j = 0; j < resultsTable.size(); j++) {
			std::cout << std::fixed << std::setprecision(2) << resultsTable[j][i] << "\t\t";
		}
		std::cout << "\n";
	}
	cout << "Done!!!!\n"<< endl;
	cout << "Press Enter to end program...";
	cin.ignore();
	return 0;
}

/*********************************************************************
** Description: Runs a recursive Fibonacci sequencer, timer based on
**		https://www.geeksforgeeks.org/chrono-in-c/
*********************************************************************/
double recursiveFib(int userIn) {
	double totalTime = 0,
		avgTime = 0,
		toNano(1*std::chrono::nanoseconds::period::den / std::chrono::nanoseconds::period::num);
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<double> elapsed;

	cout << "Calling Recursive Fibonacci implementation" << endl;
	FibonacciR fr(userIn);
	fr.PrintFibonacci();
	for (int j = 0; j < runAlgoNTimes; j++) {
		start = std::chrono::high_resolution_clock::now();
		FibonacciR fr(userIn);
		end = std::chrono::high_resolution_clock::now();

		elapsed = end - start;

		totalTime += elapsed.count();
	}
	avgTime = totalTime / ((double)runAlgoNTimes);
	cout << "\tRecursive took on average " << avgTime*toNano << " ns(run for " << runAlgoNTimes << " times) ("<< avgTime << " sec)\n" << endl;
	return avgTime * toNano;
}

/*********************************************************************
** Description: Runs an iterative Fibonacci sequencer, timer based on
**		https://www.geeksforgeeks.org/chrono-in-c/
*********************************************************************/
double nonRecursiveFib(int userIn) {
	double totalTime = 0,
		avgTime = 0,
		toNano(1 * std::chrono::nanoseconds::period::den / std::chrono::nanoseconds::period::num);
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed;

	cout << "Calling Iterative Fibonacci implementation" << endl;
	FibonacciNR fnr(userIn);
	fnr.PrintFibonacci();
	for (int j = 0; j < runAlgoNTimes; j++) {
		start = std::chrono::system_clock::now();
		FibonacciNR fnr(userIn);
		end = std::chrono::system_clock::now();

		elapsed = end - start;

		totalTime += elapsed.count();
	}
	avgTime = totalTime / ((double)runAlgoNTimes);
	cout << "\tIterative took on average " << avgTime * toNano << " ns(run for "<<runAlgoNTimes<<" times) (" << avgTime << " sec)\n" << endl;
	return avgTime * toNano;
}