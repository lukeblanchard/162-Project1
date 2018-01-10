CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#LDFLAGS = -lboost_date_time

OBJS = Ant.o Board.o Menu.o main.o

SRCS = Ant.cpp Board.cpp Menu.cpp main.cpp

HEADERS = Ant.hpp Board.hpp Menu.hpp

#target: dependencies 
#	rule to build

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS} 
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS}
