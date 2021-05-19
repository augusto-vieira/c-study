#include <stdlib.h>
#include <string.h>

#include "usuario.h"

#define TAM_MAX_SENHA 10

struct usuario{
   char* nome;
   char* login;
   char* senha;
   };

struct usuario* usuario_new(void)
{
   struct usuario* usr;
   usr = malloc(sizeof(struct usuario));
   return usr;
}

int usuario_del(struct usuario* usr)
{
   free(usr);
   return 1;
}

int usuario_autentica(struct usuario* usr, char* senha)
{
  if (strncmp(usr->senha, senha, TAM_MAX_SENHA))
    return 1;
  else 
    return 0;
}

char* usuario_getSenha(struct usuario* usr)
{
   return usr->senha;
}

char* usuario_getLogin(struct usuario* usr)
{
   return usr->login;
}

char* usuario_getNome(struct usuario* usr)
{
   return usr->nome;
}

int usuario_setSenha(struct usuario* usr, char* senha)
{
   usr->senha = senha;
   return 1;
}

int usuario_setLogin(struct usuario* usr,char* login)
{
   usr->login = login;
   return 1;
}

int usuario_setNome(struct usuario* usr, char* nome)
{
   usr->nome = nome;
   return 1;
}


