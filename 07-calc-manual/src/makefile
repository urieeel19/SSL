TARGET = $(BIN_DIR)/calculadoraManual
OBJ_DIR = ../obj
BIN_DIR = ../bin
INC_DIR = ../inc
SRC_DIR = .
TEST_DIR = ../test
ARCHIVO_ENTRADA = $(TEST_DIR)/entrada.txt
ARCHIVO_ESPERADO = $(TEST_DIR)/esperado.txt
ARCHIVO_OBTENIDO = $(TEST_DIR)/obtenido.txt

OBJS = $(OBJ_DIR)/calc.o \
		$(OBJ_DIR)/parser.o \
		$(OBJ_DIR)/scanner.o \
		$(OBJ_DIR)/memory.o
CC = gcc
CFLAGS = -I$(INC_DIR)

$(TARGET) : $(OBJS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@echo Compilacion y ejecutable listo

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c -MD $(CFLAGS) $< -o $@

-include $(OBJ_DIR)*.d

.PHONY : clean
clean: 
	@rm -r $(OBJ_DIR) $(BIN_DIR)
	@rm -f $(ARCHIVO_OBTENIDO)
	@rm -f $(TARGET)
	@echo Archivos Borrados

test : $(TARGET)
	@$(TARGET) < $(ARCHIVO_ENTRADA) > $(ARCHIVO_OBTENIDO)
	@diff -q -s $(ARCHIVO_ESPERADO) $(ARCHIVO_OBTENIDO)

run : $(TARGET)
	@echo Inicio de calculadora Manual -"!" para finalizar-
	@./$(TARGET)
