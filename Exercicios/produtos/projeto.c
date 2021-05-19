#include "projeto.h"

int get_codigo(const Projeto *projeto)
{
    return projeto->codigo;
}

float get_valor(const Projeto *projeto)
{
    return projeto->valor;
}

char get_receita(const Projeto *projeto)
{
    return projeto->despesa_receita;
}

void set_codigo(Projeto *projeto, int codigo)
{
    projeto->codigo = codigo;
}

void set_valor(Projeto *projeto, int valor)
{
    projeto->valor = valor;
}

void set_receita(Projeto *projeto, char receita_dispesa)
{
    projeto->despesa_receita = receita_dispesa;
}