CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += O3
LDFLAGS = -lboost_date_time

#you can use either {} or () to contain sets of instructions

OBJS = main.o isValidInput.o menuShell.o FibonacciNR.o FibonacciR.o

SRCS = isValidInput.cpp menuShell.cpp main.cpp FibonacciNR.cpp FibonacciR.cpp

HEADERS = isValidInput.hpp menuShell.hpp FibonacciNR.hpp FibonacciR.hpp

DOCUMENTS = 

#target: dependencies
#	rules to build

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: ${OBJS}
	rm -f *.o main 

#zip: ${SRCS} ${HEADERS} ${DOCUMENTS}
#	lab9_Wellheuser_Phillip.zip ${HEADERS}${SRCS}${DOCUMENTS}

#all: clean 



