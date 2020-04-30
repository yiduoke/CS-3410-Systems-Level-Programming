.PHONY: clean all submission

CC=gcc
CFLAGS=-std=c99 -Wall -Werror
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=testOlist
GRADER_BINARY=graderbinary
SUBMISSION=submission # change to your netid

default: $(EXECUTABLE)

autograder_lite_binary: $(GRADER_BINARY)

$(EXECUTABLE): $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^
	@rm $(OBJECTS)

$(GRADER_BINARY): $(EXECUTABLE) 
	@mv $(EXECUTABLE) $(GRADER_BINARY)
	@echo "[INFO]: DONE!"

submission: 
	@echo "[BY HAND]: Follow the instruction on the webpage and submit your work to CMS."

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) $(GRADER_BINARY)

