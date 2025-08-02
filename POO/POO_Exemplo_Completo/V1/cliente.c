#include <string.h>
#include "cliente.h"

char *getNome(Cliente *cliente){
    return cliente->nome;
}
void setNome(Cliente *cliente, char *nome){
    strncpy(cliente->nome, nome, sizeof(cliente->nome));
}

char *getCpf(Cliente *cliente){
    return cliente->cpf;
}
void setCpf(Cliente *cliente, char *cpf){
    strncpy(cliente->cpf, cpf, sizeof(cliente->cpf));
}