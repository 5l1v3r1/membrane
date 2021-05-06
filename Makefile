CXX       = g++
CXXFLAGS  = -Iinclude -std=c++17 -Wall -Wextra -pedantic-errors

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	LDFLAGS = --static
else
	LDFLAGS =
endif

Q         = @
TARGET    = membrane.bin

SRCS      := $(wildcard src/*.cc)
OBJS      := $(patsubst %.cc, %.o, $(SRCS))

.PHONY: membrane.bin

all: membrane.bin

membrane.bin: $(OBJS)
	$(Q) echo Linking... $@
	$(Q) $(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)
	$(Q) echo Done.

%.o: %.cc
	$(Q) echo Compiling... $<
	$(Q) $(CXX) -c $< -o $@ $(CXXFLAGS)
