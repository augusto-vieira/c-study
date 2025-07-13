# 📘 Projeto de Testes Unitários e Cobertura de Código em C

Projeto organizado com `Makefile`, testes unitários usando **`CMocka`** e **`CUnit`** e cobertura de código com **`lcov` e `gcovr`.**

## ⚙️ Ferramentas Explicadas
#### 🧪 `libcunit1-dev`
- **O que é:** Biblioteca **CUnit** para testes em C.
- **Para que serve:** Criar **testes unitários simples** para funções em C.
- **Aplicação:** Verificar se funções retornam os valores esperados.
- **Exemplo:** Testar se `soma(2, 2)` retorna `4`.

🆚 **Mais antigo e básico**, ideal para projetos simples.

---
#### 🧪 `libcmocka-dev`
- **O que é:** Biblioteca **CMocka**, também para C.
- **Para que serve:** Criar **testes unitários mais avançados**, com suporte a **mocks** e melhores asserts.
- **Aplicação:** Testar funções complexas, isolando dependências (como arquivos, rede, banco de dados).
- **Exemplo:** Testar uma função que acessa o banco simulando a resposta do banco (mock).

🚀 **Mais moderno e poderoso** que CUnit.

---
#### 📊 `lcov`
- **O que é:** Ferramenta de **análise de cobertura de testes** para C/C++.
- **Para que serve:** Mostrar **quais partes do código foram executadas** durante os testes.
- **Aplicação:** Gerar relatórios de cobertura em HTML.
- **Exemplo:** Ver se todas as linhas da função `calculaDesconto()` foram testadas.

✅ Usa dados gerados pelo `gcov`.

---
#### 📊 `gcovr`
- **O que é:** Ferramenta **mais simples e automatizada** para gerar relatórios de cobertura a partir do `gcov`.
- **Para que serve:** Criar relatórios de cobertura de forma rápida, em texto, XML ou HTML.
- **Aplicação:** Integrar cobertura de código em pipelines CI/CD.
- **Exemplo:** Gerar um relatório `.xml` para o Jenkins ou GitLab CI mostrar a cobertura dos testes.

⚙️ **Mais leve** e fácil de automatizar que `lcov`.

---
### 🔍 Resumo Comparativo

| Ferramenta       | Linguagem | Função                                | Tipo de Saída            |
|------------------|-----------|----------------------------------------|---------------------------|
| `libcunit1-dev`  | C         | Testes unitários simples               | Saída de testes (texto)   |
| `libcmocka-dev`  | C         | Testes unitários avançados com mocks  | Saída de testes (texto)   |
| `lcov`           | C/C++     | Análise de cobertura (baseado em gcov)| HTML                      |
| `gcovr`          | C/C++     | Análise de cobertura automatizada     | Texto, HTML, XML, JSON    |

---
## 🔍 Sobre os Arquivos de Cobertura

| Extensão | Gerado por | Finalidade                            |
|----------|------------|----------------------------------------|
| `.gcno`  | gcc        | Guarda o **mapa de instrumentação** do código           |
| `.gcda`  | executável | Armazena **dados de cobertura** em tempo de execução                      |
| `.gcov`  | gcov       | Gera um **relatório legível** da cobertura por linha          |

---
## 🔧 Instalando as Dependências

Instale os pacotes necessários com:

```bash
sudo apt install build-essential libcmocka-dev lcov gcovr xdg-utils
```
---
## 📁 Estrutura de Diretórios

```bash
.
├── Makefile                   ← Comandos de build, teste e cobertura
├── README.md                  ← Documentação do projeto
├── cobertura_html/            ← Relatórios HTML de cobertura
├── cobertura.info             ← Arquivo gerado pelo lcov
├── gcov/                      ← Relatórios .gcov gerados pelo gcov
├── include/                   ← Arquivos header (.h)
│   ├── divisao.h
│   ├── soma.h
│   └── subtracao.h
├── obj/                       ← Objetos compilados e arquivos de cobertura (.o, .gcda, .gcno)
├── src/                       ← Código-fonte principal
│   ├── divisao.c
│   ├── soma.c
│   └── subtracao.c
├── tests/                     ← Testes unitários
│   ├── bin/                   ← Binários dos testes
│   │   ├── test_divisao
│   │   ├── test_soma
│   │   └── test_subtracao
│   ├── test_divisao.c
│   ├── test_soma.c
│   └── test_subtracao.c
```
---
## ⚙️ Comandos do Makefile

| Comando             | Descrição                                                              |
|---------------------|------------------------------------------------------------------------|
| `make`              | Compila os arquivos da pasta `src/` e gera o binário `main`            |
| `make test`         | Compila os testes e gera binários em `tests/bin/`                      |
| `make run_test_xyz` | Executa o teste `test_xyz` individualmente                             |
| `make coverage`     | Gera arquivos `.gcov` em `gcov/` usando `gcov`                         |
| `make lcov-html`    | Gera relatório HTML com `lcov` em `cobertura_html/` e abre no navegador|
| `make gcovr-html`   | Gera relatório HTML com `gcovr` e abre no navegador                    |
| `make gcovr-cli`    | Exibe cobertura direto no terminal                                     |
| `make clean`        | Remove arquivos de build, cobertura e testes                           |
| `lcov --capture --directory . --output-file cobertura.info`   | Captura dados de cobertura para gerar um arquivo de informações.         |
| `genhtml cobertura.info --output-directory cobertura_html`    | Gera relatórios de cobertura em HTML a partir do arquivo de informações. |
| `xdg-open cobertura_html/index.html`                          | Abre automaticamente o relatório HTML no navegador (para sistemas Linux).

---
## 🧪 Execução com Makefile

1. Compile os testes:
   ```bash
   make test
   ```
3. Execute um teste:
   ```bash
   make run_test_soma
   make run_test_divisao
   ```
4. Gere relatório com `gcovr` (CLI)
   ```bash
   make gcovr-cli
   ```
5. Gere relatório com `gcovr` (HTML):
   ```bash
   make gcovr-html
   ```
6. Gere relatório HTML com `lcov`:
   ```bash
   make lcov-html
   ```
7. Limpe todos os arquivos gerados:
   ```bash
   make clean
   ```
---
## 📜 Licença das Ferramentas

**`libcunit1-dev` — LGPL (Lesser General Public License)**
- **Uso:** Você pode usar, modificar e distribuir a biblioteca, inclusive em projetos fechados.
- **Regras:** Se modificar a própria biblioteca, precisa liberar essas modificações. Mas seu código que usa a biblioteca pode ser fechado.
- **Resumo:** Permissiva para uso em projetos abertos ou fechados, mas alterações na biblioteca devem ser abertas.

---
**`libcmocka-dev` — Apache License 2.0**
- **Uso:** Modificação e distribuição livres, inclusive para uso comercial.
- **Regras:** Precisa dar crédito aos autores, incluir a licença e avisar sobre mudanças. Permite uso em software proprietário.
- **Resumo:** Muito permissiva, inclusive para projetos fechados e comerciais.

---
**`lcov` — GPL (General Public License)**
- **Uso:** Você pode usar, modificar e distribuir, mas qualquer software derivado deve ser também GPL (código aberto).
- **Regras:** Se modificar e distribuir, precisa liberar o código-fonte dessas modificações.
- **Resumo:** Só pode ser usado em projetos fechados se não modificar o lcov; se modificar e distribuir, tem que abrir o código.

---
**`gcovr` — BSD License**
- **Uso:** Modificação e distribuição livres, inclusive para uso comercial.
- **Regras:** Só precisa manter o aviso de copyright e a licença.
- **Resumo:** Extremamente permissiva, pode usar em qualquer projeto, aberto ou fechado.

---
