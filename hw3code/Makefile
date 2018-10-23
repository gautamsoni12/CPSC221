# the compiler to use
CC = clang++

# warning flags:
WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable

# compiler flags:
CXXFLAGS = -std=c++1y -stdlib=libc++ -g -O0 $(WARNINGS)
  
# the name to use for both the target source file, and the output file:
TARGET = lucky
  
all: $(TARGET)
  
$(TARGET): $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	rm -rf $(TARGET)
