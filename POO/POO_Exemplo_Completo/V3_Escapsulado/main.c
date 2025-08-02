#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "conta.h"
  
int main(void)
{
  
  Cliente *maria = newCliente();
  maria->setNome(maria, "Maria Silva");
  maria->setCpf(maria, "111.333.222-77");

  Conta *contaMaria = newConta();
  contaMaria->setSaldo(contaMaria, 234.23);
  contaMaria->setAgencia(contaMaria, 111);

  contaMaria->setTitular(contaMaria, maria);

  printf("Nome: %s\n", contaMaria->titular->getNome(maria));
  printf("CPF: %s\n", contaMaria->titular->getCpf(maria));

  printf("Agencia: %d\n", contaMaria->getAgencia(contaMaria));
  printf("Saldo: %.2f\n",contaMaria->getSaldo(contaMaria));
  
  return 0;
}
