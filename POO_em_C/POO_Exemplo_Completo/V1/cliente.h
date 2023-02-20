#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct 
{
   char nome[50];
   char cpf[20];
} Cliente;

char *getNome(Cliente *cliente);
void setNome(Cliente *cliente, char *nome);

char *getCpf(Cliente *cliente);
void setCpf(Cliente *cliente, char *cpf);

#endif /* CLIENTE_H_ */