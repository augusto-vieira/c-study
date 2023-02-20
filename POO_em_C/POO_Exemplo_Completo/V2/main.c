#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "conta.h"
  
int main(void)
{
  Cliente *maria = newCliente();
  setNome(maria, "Maria Silva");
  setCpf(maria, "111.333.555-77");
  
  Conta *contaMaria = newConta();
  setSaldo(contaMaria, 765);
  setAgencia(contaMaria, 111);

  printf("Nome: %s\n",getNome(maria));
  printf("CPF: %s\n",getCpf(maria));

  printf("Agencia: %d\n", getAgencia(contaMaria));
  printf("Saldo: %.2f\n", getSaldo(contaMaria));
  
  return 0;
}
