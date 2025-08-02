#ifndef PROJETO_H_
#define PROJETO_H_

typedef struct 
{
    int codigo;
    float valor;
    char despesa_receita;
} Projeto;

int get_codigo(const Projeto *projeto);
float get_valor(const Projeto *projeto);
char get_receita(const Projeto *projeto);

void set_codigo(Projeto *projeto, int codigo);
void set_valor(Projeto *projeto, int valor);
void set_receita(Projeto *projeto, char receita);

#endif /* PROJETO_H_ */
