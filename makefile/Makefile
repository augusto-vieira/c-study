# Nome do compilador
CC = gcc

# Nome do executável
TARGET = a.out

# Arquivos-fonte
SRC = inline.c

# Flags de compilação (adicione -Wall para mostrar todos os avisos)
CFLAGS = -Wall -Wextra

# Alvo padrão
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Alvo de teste
test: all
	@echo "--- Comandos com wc ---"
	@wc < /etc/shells
	@cat /etc/shells | wc
	@echo maçã | wc
# @wc <<< "123 5678"
	@wc /etc/shells
	@wc /etc/shells /etc/passwd
	@echo banana | wc /etc/shells /etc/passwd
# MEU PROGRAMA
	@echo "--- Comandos com $(TARGET) ---"
	@./$(TARGET) < /etc/shells
	@cat /etc/shells | ./$(TARGET)
	@echo maçã | ./$(TARGET)
#	@./$(TARGET) <<< "123 5678"
	@./$(TARGET) /etc/shells
	@./$(TARGET) /etc/shells /etc/passwd
	@echo banana | ./$(TARGET) /etc/shells /etc/passwd

# Alvo para limpar arquivos gerados
clean:
	rm -f $(TARGET)