CXX=g++
CXXFLAGS = -g -std=c++11 -Wall -Werror

MM: MM.o Evidence.o Player.o Room.o Suspect.o
	@$(CXX) $(CXXFLAGS) -o  MM.exe MM.o Evidence.o Player.o Room.o Suspect.o
	
clean:
	-del *.o
	-del *.exe
