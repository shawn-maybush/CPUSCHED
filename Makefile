# Compiler and flags
CC = g++
CFLAGS = -Wall -I. -MMD -MP  # Include current directory for headers, enable dependency generation

# Executable and source files
TARGET = scheduler_simulator
SOURCES = FIFO.cpp SJF.cpp Priority.cpp Scheduler.cpp EventQueue.cpp CPU.cpp
HEADERS = Process.h ReadyQueue.h FIFO.h SJF.h Priority.h Event.h EventQueue.h CPU.h Scheduler.h

# Default target
all: $(TARGET)

# Build rule for the executable
$(TARGET): $(SOURCES:.cpp=.o)
	$(CC) $(CFLAGS) -o $@ $^

# Build rule for object files (implicit rule)
%.o: %.cpp 
	$(CC) $(CFLAGS) -c $<

# Clean target
clean:
	rm -f $(TARGET) *.o *.d  # Remove dependency files as well

# Include dependency files
-include $(SOURCES:.cpp=.d)  # Include dependency files (ignore errors if not found)

