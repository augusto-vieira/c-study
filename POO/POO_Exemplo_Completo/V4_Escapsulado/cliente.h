#ifndef CLIENTE_H_
#define CLIENTE_H_

// Atributos Encapsulados
typedef struct cliente Cliente;

typedef struct 
{
  // Referência para acessar os atributos encapsulados
  Cliente *obj;

  // Métodos
  char *(*getNome)(Cliente *obj);
  void (*setNome)(Cliente *obj, char *nome); 
  char *(*getCPF)(Cliente *obj);
  void (*setCPF)(Cliente *obj, char *cpf); 

} Client_t;

// Constructor
Client_t *newCliente();

#endif /* CLIENTE_H_ */