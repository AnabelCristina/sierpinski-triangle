TARGET = sierpinski

# Arquivo principal
SRC = main.c

# Flags do compilador
CFLAGS = -Wall -O2
LIBS_LINUX = -lSDL2 -lm
LIBS_WINDOWS = -lmingw32 -lSDL2main -lSDL2 -mwindows -lm

# Detecta o sistema operacional
ifeq ($(OS),Windows_NT)
	LIBS = $(LIBS_WINDOWS)
else
	LIBS = $(LIBS_LINUX)
endif

# Regra padrão
all: $(TARGET)

# Como gerar o executável
$(TARGET): $(SRC)
	gcc $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

# Limpar arquivos gerados
clean:
	rm -f $(TARGET)