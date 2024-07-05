CC = g++
FLAGS = -pedantic -Wall -Iinclude
OBJDIR = obj
OBJS = $(OBJDIR)/main.o $(OBJDIR)/astronauta.o $(OBJDIR)/voo.o
SRCS = main.cpp astronauta.cpp voo.cpp
HEADERS = include/astronauta.hpp include/voo.hpp include/lista.hpp


ifeq ($(OS),Windows_NT)
	TARGET = main.exe
else
	TARGET = main
endif

compile: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR)/main.o: main.cpp $(HEADERS)
	$(CC) $(FLAGS) -c main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/astronauta.o: astronauta.cpp include/astronauta.hpp
	$(CC) $(FLAGS) -c astronauta.cpp -o $(OBJDIR)/astronauta.o

$(OBJDIR)/voo.o: voo.cpp include/voo.hpp
	$(CC) $(FLAGS) -c voo.cpp -o $(OBJDIR)/voo.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)