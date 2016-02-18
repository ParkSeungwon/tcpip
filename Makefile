CFLAG = -g -std=c++11 
CC = g++
SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, %.o, $(SRC))

all : cl sv

cl : cl.o tcpip.o
	g++ -o cl cl.o tcpip.o -lpthread

sv : sv.o tcpip.o
	g++ -o sv sv.o tcpip.o -lpthread
	
%.o : %.cc
	$(CC) -c $< $(CFLAG)


clean : 
	rm *.o sv cl
#	./$@
