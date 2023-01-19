TARGET = $(BIN_DIR)/game
OBJ_DIR = ./obj
BIN_DIR = ./bin
INC_DIR = ./inc
SRC_DIR = ./src
#definir todos los archivos *.o del programa
OBJS = $(OBJ_DIR)/Main.o\
       $(OBJ_DIR)/Partida.o\
       $(OBJ_DIR)/Juego.o\
       $(OBJ_DIR)/Nivel.o\
       $(OBJ_DIR)/Tablero.o\
       $(OBJ_DIR)/Reportes.o

CPPFLAGS = -Wall -I$(INC_DIR)

$(TARGET) : $(OBJS)
	mkdir -p $(BIN_DIR)
	g++ $(CPPFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	g++ -c $(CPPFLAGS) $< -o $@

clean :
	@rm -r $(OBJ_DIR) $(BIN_DIR)