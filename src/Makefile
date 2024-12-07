CXX = g++
CXXFLAGS = -std=c++17 -I. -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
SRCS = main.cpp Composants/Cellule.cpp Composants/Grille.cpp IHM/Console.cpp IHM/Graphique.cpp Services/ServiceFichier.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = programme_executable

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	del /q $(OBJS) $(TARGET)
