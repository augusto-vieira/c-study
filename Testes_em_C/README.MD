# Testes em C

O **CMocka** é uma biblioteca de testes unitários para a linguagem C,open source e licenciada sob a MIT License. Projetada para ser simples, leve e eficiente. Ela permite escrever testes automatizados para verificar o comportamento de funções e componentes de código, oferecendo recursos como "mocks" (substituições de funções) e diversas funções de assertivas. CMocka é ideal para projetos pequenos, sistemas embarcados ou ambientes com recursos limitados, já que não possui dependências externas e é fácil de integrar. Embora tenha funcionalidades mais restritas em comparação com outras bibliotecas de testes, é uma escolha prática para projetos C.

O **GCov** é uma ferramenta de análise de cobertura de código para programas em C e C++. Ele permite identificar quais partes do código foram executadas durante os testes, ajudando a garantir que o código esteja bem testado. O GCov é usado em conjunto com o compilador GCC, que gera dados de cobertura ao compilar o código com as flags -fprofile-arcs -ftest-coverage. Após a execução do programa, o GCov gera relatórios que mostram as linhas de código cobertas e não cobertas, ajudando a melhorar a qualidade e a cobertura dos testes.

| Comando                                                         | Descrição                                               |
|----------------------------------------------------------------|---------------------------------------------------------|
| `make clean`                                                  | Remove arquivos compilados e de cobertura.              |
| `make`                                                        | Compila o projeto, gerando o executável principal.      |
| `make test`                                                   | Compila e executa os testes, mostrando resultados no terminal. |
| `make coverage`                                               | Gera relatórios de cobertura usando gcov.               |
| `lcov --capture --directory . --output-file cobertura.info`  | Captura dados de cobertura para gerar um arquivo de informações. |
| `genhtml cobertura.info --output-directory cobertura_html`    | Gera relatórios de cobertura em HTML a partir do arquivo de informações. |
| `xdg-open cobertura_html/index.html`                          | Abre o relatório HTML no navegador (para sistemas Linux). |

