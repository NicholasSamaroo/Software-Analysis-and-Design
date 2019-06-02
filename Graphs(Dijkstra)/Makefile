########################################
##
## Makefile
## LINUX compilation 
##
##############################################





CXX=g++
CXXFLAGS=-g -Wall -MMD -std=c++11

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.





#Rule for .cpp files
# .SUFFIXES : .cc.o 

.cc.o:
	g++ $(CXXFLAGS) $(INCLUDES)  -c $< -o $@




#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#ZEROTH PROGRAM
ALL_OBJ0=CreateGraphAndTest.o
PROGRAM_0=CreateGraphAndTest
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(CXXFLAGS) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

ALL_OBJ1=FindPaths.o
PROGRAM_1=FindPaths
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(CXXFLAGS) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)





#Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0); rm -f $(PROGRAM_1))



(:
