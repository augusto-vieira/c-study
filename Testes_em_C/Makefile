# Definição das variáveis
CC=gcc
CFLAGS=-fprofile-arcs -ftest-coverage -Iinclude
LDFLAGS=-lcmocka -lgcov

OBJ_DIR=obj
GCOV_DIR=gcov
TEST_BIN_DIR=tests/bin

SRC=$(wildcard src/*.c)
OBJ=$(SRC:src/%.c=$(OBJ_DIR)/%.o)

TESTS=$(wildcard tests/test_*.c)
TEST_NAMES=$(notdir $(TESTS:.c=))
TEST_BINS=$(TEST_NAMES:%=$(TEST_BIN_DIR)/%)

# Regra padrão
all: main

# Compila o programa principal
main: $(OBJ)
	$(CC) -o $@ $^ -lgcov

# Compila arquivos .c da src em obj/
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compila todos os testes (sem executar)
test: $(TEST_BINS)

# Compila testes individualmente
$(TEST_BIN_DIR)/test_%: tests/test_%.c $(OBJ_DIR)/%.o
	@mkdir -p $(TEST_BIN_DIR)
	$(CC) -o $@ $^ $(LDFLAGS) -Iinclude

# Executa um teste individual manualmente: make run_test_<nome>
run_test_%: $(TEST_BIN_DIR)/test_%
	$<

# Geração de cobertura com gcov
coverage:
	@mkdir -p $(GCOV_DIR)
	gcov -o $(OBJ_DIR) -b src/*.c > /dev/null
	mv *.gcov $(GCOV_DIR)/

# Limpeza
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.gcda $(OBJ_DIR)/*.gcno
	rm -rf $(GCOV_DIR)/ $(TEST_BIN_DIR)/
	rm -rf cobertura_html/*
	rm -f cobertura.info main

# Relatórios
lcov-html:
	lcov --capture --directory . --output-file cobertura.info
	genhtml cobertura.info --output-directory cobertura_html
	xdg-open cobertura_html/index.html

gcovr-html:
	@mkdir -p cobertura_html
	gcovr -r . obj/ --html --html-details -o cobertura_html/index.html
	xdg-open cobertura_html/index.html

gcovr-cli:
	gcovr -r . obj/

.PHONY: all test clean coverage relatorios gcovr-html run_test_%