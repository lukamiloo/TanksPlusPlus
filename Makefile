CXX=g++
TARGET=TanksPlusPlus
INCLUDE=-I"C:/SFML/include"
LIB=-L"C:/SFML/lib"
LIBS=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network
CLASSES=Game.cpp Player.cpp Wall.cpp MainMenu.cpp Button.cpp

all: $(TARGET)
$(TARGET): main.cpp
	$(CXX) -o $(TARGET) main.cpp $(CLASSES) $(INCLUDE) $(LIB) $(LIBS)