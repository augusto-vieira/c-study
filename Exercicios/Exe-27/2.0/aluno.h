#ifndef ALUNO_H_INCLUDE
#define ALUNO_H_INCLUDE


typedef struct _aluno Aluno;
typedef struct _turma Turma;
typedef struct _registro Registro;

Registro *criar(void);
void libera_registro( Registro *registro);


#endif // ALUNO_H_INCLUDE