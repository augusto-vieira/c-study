
// https://www.embarcados.com.br/encapsulamento-em-c/
 
 /*
  _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
 |     Usuario                | Classe Usuario
 |_ _ _ _ _ _ _ _ _ _ _ _ _ _ | 
 | - nome                     |  
 | - login		              | Atributos
 | - senha	                  |
 |_ _ _ _ _ _ _ _ _ _ _ _ _ _ | 
 |                            |
 | + autenticar(login, senha) | Métodos	
 |_ _ _ _ _ _ _ _ _ _ _ _ _ _ | 

 */


#include <stdio.h>
#include "usuario.h"

int main()
{
 struct usuario* usr;
 usr = usuario_new();
 usuario_setSenha(usr, "testando");
 printf("Senha: %s\n",usuario_getSenha(usr));

/* A linha abaixo ocasiona em erro de compilacao, o main nao conhece os atributos de usuario */
// printf("Senha: %s\n",usr->senha);

 return 0;
}


