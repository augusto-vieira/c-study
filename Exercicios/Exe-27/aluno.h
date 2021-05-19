#ifndef ALUNO_H_INCLUDE
#define ALUNO_H_INCLUDE


typedef struct _aluno Aluno;
typedef struct _turma Turma;
typedef struct _registros Registros;




void setTurma(Turma *turma, const char *id, int semestre, int ano, int *count);
void setAluno(Registros *dados ,const char *nome, float *nota, int size_nota);

void writeTurma(Turma *write, int *count);
void editarTurma(Registros *dado, int count);
void getTurma(Turma *turma, int count);

Registros *criar(void);
void *newTurma(Registros **new_turma, int *count);

#endif // ALUNO_H_INCLUDE