#ifndef CLIENTE_H_
#define CLIENTE_H_

// Encapsular os dados de cliente
typedef struct cliente Cliente;

// Constructor
Cliente *newCliente();

// Representa os Métodos
char *getNome(Cliente *cliente);
void setNome(Cliente *cliente, char *nome);

char *getCpf(Cliente *cliente);
void setCpf(Cliente *cliente, char *cpf);

#endif /* CLIENTE_H_ */