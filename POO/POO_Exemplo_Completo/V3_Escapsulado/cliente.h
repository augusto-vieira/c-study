#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct 
{
  char nome[50];
  char cpf[20];

  // Ponteiro para função 
  // Métodos
  char *(*getNome)(void *cliente);
  void (*setNome)(void *cliente, char *nome);

  char *(*getCpf)(void *cliente);
  void (*setCpf)(void *cliente, char *cpf);
   
} Cliente;

// Constructor
Cliente *newCliente();

#endif /* CLIENTE_H_ */