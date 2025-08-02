#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "conta.h"
  
int main(void)
{
  Client_t *maria = newCliente();
  maria->setNome(maria->obj, "Maria Silva");
  maria->setCPF(maria->obj, "222.222.222-22");

  Conta_t *contaMaria = newConta();
  contaMaria->setSaldo(contaMaria->obj, 234.77);
  contaMaria->setAgencia(contaMaria->obj, 121);

  contaMaria->setTitular(&contaMaria->obj, maria);

  printf("Nome: %s\n", contaMaria->titular->getNome(maria->obj));
  printf("CPF: %s\n", contaMaria->titular->getCPF(maria->obj));

  printf("Agencia: %d\n", contaMaria->getAgencia(contaMaria->obj));
  printf("Saldo: %.2f\n",contaMaria->getSaldo(contaMaria->obj));

  return 0;
}
