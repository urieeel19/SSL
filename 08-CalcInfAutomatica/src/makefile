CC = gcc
TARGET = $(BIN_DIR)/Calculator
OBJ_DIR = ../obj
BIN_DIR = ../bin
INC_DIR = ../inc
TEST_DIR = ../test
RUL_DIR = ../rules
SRC_DIR = .

OBJS = $(OBJ_DIR)/calc.o \
		$(OBJ_DIR)/parser.o \
		$(OBJ_DIR)/scanner.o \
		$(OBJ_DIR)/errors.o \
		$(OBJ_DIR)/memory.o

FLEX_RULES = $(RUL_DIR)/scanner.l
BISON_RULES = $(RUL_DIR)/parser.y
FLEX_C = $(SRC_DIR)/scanner.c
BISON_C = $(SRC_DIR)/parser.c
BISON_H = $(INC_DIR)/token.h
CFLAGS = -I$(INC_DIR)

ARCHIVO_ENTRADA = $(TEST_DIR)/entrada.txt
ARCHIVO_ESPERADO = $(TEST_DIR)/esperado.txt
ARCHIVO_OBTENIDO = $(TEST_DIR)/obtenido.txt
# -----------------------------------------

$(TARGET): $(FLEX_C) $(BISON_C) $(OBJS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(OBJS) $(CFLAGS) -o $@
	@echo Compilacion y ejecutable listo

$(FLEX_C): $(FLEX_RULES)
	@flex -o"$(FLEX_C)" "$(FLEX_RULES)"

$(BISON_C): $(BISON_RULES)
	@bison -yd -o"$(BISON_C)" "$(BISON_RULES)" --defines="$(BISON_H)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c -MD $(CFLAGS) $< -o $@

-include $(OBJ_DIR)*.d

.PHONY : clean
clean :
	@rm -r $(OBJ_DIR) $(BIN_DIR)
	@rm -f $(ARCHIVO_OBTENIDO)
	@rm -f $(TARGET)
	@rm -r $(FLEX_C)
	@rm -r $(BISON_C)
	@rm -r $(BISON_H)
	@echo Archivos Borrados
	
test : $(TARGET)
	@$(TARGET) < $(ARCHIVO_ENTRADA) > $(ARCHIVO_OBTENIDO)
	@diff -q -s $(ARCHIVO_ESPERADO) $(ARCHIVO_OBTENIDO)

run : $(TARGET)
	@echo Inicio de calculadora Automatica -! para finalizar-
	@./$(TARGET)