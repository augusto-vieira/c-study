#ifndef ALUNO_H_INCLUDE
#define ALUNO_H_INCLUDE


typedef struct _aluno Aluno;
typedef struct _turma Turma;




void setTurma(Turma *turma, const char *id, int semestre, int ano, int *count);
void setAluno(Turma *turma , const char *nome, float nota, int n_turma, int n_aluno, int n_nota);

void writeTurma(Turma *write, int *count);
void editarTurma(Turma *dado, int count);
void getTurma(Turma *turma, int count);


void getAluno(Turma *turma, size_t n_turma, size_t n_alunos);


Turma *criar(void);
void alocaTurmas(Turma **aloca_turmas, const int *size_turma);


void alocaAlunos(Turma *aloca_alunos, const int n_turma, size_t n_alunos);
void alocaNotas(Turma *aloca_notas, const int n_turma, const int n_aluno,  size_t n_notas);

#endif // ALUNO_H_INCLUDE