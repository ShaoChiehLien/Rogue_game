# Compiler to use
CXX=g++
# Extra compilation arguments
CXXFLAGS=-std=c++11

# List of classes, have a cpp and a h file
CLASSES = GridChar.cpp KeyboardListener.cpp ObjectDisplayGrid.cpp
# List of all source files to compile
SOURCES = Test.cpp $(CLASSES)
# List of header files to watch
HEADERS = $(CLASSES:.cpp=.h)
# List of object files for building
OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = CurseExample

# Check if building on Windows or Linux
ifeq ($(OS),Windows_NT)
	# use PDCurses library archive when building on windows
	CURSES = lib\pdcurses.lib
	CXXFLAGS += -I./include
	# by running rm within cmd, it does not error on missing files
	RM=cmd /c del
	# Windows introduced the tar command that can make zip files
	ZIP=tar -acvf
else
	# use ncurses library when building on linux/mac
	# Linux install using "sudo apt-get install libncurses5-dev libncursesw5-dev"
	# Mac install using "brew install ncurses"
	CURSES=-lncurses
	# Have to include threads on linux
	CXXFLAGS += -pthread
	# running -f means it does not error on missing files
	RM=rm -f
	# Linux needs the zip command to do zip files, install using apt-get
	ZIP=zip
endif

# Build then run
run: ./$(EXECUTABLE)
	./$(EXECUTABLE)
.PHONY: run

# Build the project, default command
$(EXECUTABLE): $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS) $(CURSES)
	
# Compile .o files
# Cannot think of a good way to watch only the required headers for each .o file
%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) $<

# Clean the project
clean:
	$(RM) *.o
	$(RM) $(EXECUTABLE)
	$(RM) $(EXECUTABLE).exe
	$(RM) $(EXECUTABLE).zip

# Clean then build
rebuild: clean $(EXECUTABLE)
.PHONY: rebuild

# Create a zip file with all relevant files to build the project
ZIPFILES=$(SOURCES) $(HEADERS) Makefile lib/* include/* pdcurses.dll \
	PDCursesExample.sln PDCursesExample.vcxproj PDCursesExample.vcxproj.filters
zip: $(ZIPFILES)
	$(ZIP) $(EXECUTABLE).zip $(ZIPFILES)
.PHONY: zip
