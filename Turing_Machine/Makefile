# @File: Makefile

PROGNAME = pda
CXXFLAGS = -g -Wall
LDFLAGS = -g
# For C++ programs
CXX = g++
# For C programs
#CC = gcc

SRCS =  Commands.cpp Configuration_Settings.cpp \
		Final_States.cpp Input_Strings.cpp input_alphabet.cpp \
		Main.cpp States.cpp stack_alphabet.cpp stack.cpp \
		Transition.cpp Transition_Function.cpp \
		pushdown_automaton.cpp Uppercase.cpp 
OBJS = $(SRCS:.cpp=.o)



default: $(PROGNAME) 

clean:
	rm -f $(OBJS) *~ 

immaculate: clean
	rm -f $(PROGNAME)

%.o: %.cpp Commands.h Configuration_Settings.h \
		Direction.h Final_States.h Input_Strings.h \
		input_alphabet.h States.h stack_alphabet.h \
		stack.h Transition.h Transition_Function.h \
		pushdown_automaton.h Uppercase.h
	$(CXX) -c $(CXXFLAGS) $<

depend:
	makedepend $(SRCS) 

# example of a multi-line make command that runs as a single shell command
listsrcs:
	@for file in $(SRCS) ;\
	do \
	    echo "$$file is a file" ;\
	done

$(PROGNAME): $(OBJS) #$(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4)
	$(CXX) $(LDFLAGS) -o $@ $^
