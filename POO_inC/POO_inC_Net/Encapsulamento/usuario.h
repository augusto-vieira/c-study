/*
os objetos do tipo “Usuario” devem poder ser utilizados por todos que o desejarem. Por isso uma declaração 
da nossa estrutura de dados é feita no nosso arquivo usuario.h, porém é declarado como uma estrutura opaca, 
ninguém sabe o que realmente tem dentro dela a não ser nosso .c
*/

struct usuario;

/* retorna um objeto do tipo usuario */
struct usuario* usuario_new(void);

/* deleta o objeto do tipo usuario */
int usuario_del(struct usuario* usr);

/* verifica se a senha eh igual */
int usuario_autentica(struct usuario* usr,char* senha);

/* retorna a senha do usuario */
char* usuario_getSenha(struct usuario* usr);

/* retorna o login do usuario */
char* usuario_getLogin(struct usuario* usr);

/* retorna o nome do usuario */
char* usuario_getNome(struct usuario* usr);

/* seta a senha do usuario */
int usuario_setSenha(struct usuario* usr, char* senha);

/* seta o login do usuario */
int usuario_setLogin(struct usuario* usr,char* login);

/* seta o nome do usuario */
int usuario_setNome(struct usuario* usr, char* nome);