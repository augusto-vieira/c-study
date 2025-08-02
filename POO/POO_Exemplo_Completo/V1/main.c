#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "conta.h"
  
   int main(void)
   {
    Cliente maria;

    setNome(&maria,"Maria Silva");
    setCpf(&maria, "222.111.333-62"); 

    Conta contaMaria;
    setSaldo(&contaMaria, 500);
    setAgencia(&contaMaria, 111);

    setTitular(&contaMaria, &maria);
    
    printf("Nome: %s\n",contaMaria.titular->nome);
    printf("CPF: %s\n", contaMaria.titular->cpf);

    printf("Agencia: %d\n", getAgencia(&contaMaria));
    printf("Saldo: %.2f\n", getSaldo(&contaMaria));

    return 0;
  }
