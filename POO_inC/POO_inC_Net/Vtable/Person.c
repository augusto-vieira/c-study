#include "Person.h"

 void Pessoa_ola() { printf("Bom dia\n"); };
 void Pessoa_bye() { printf("Adeus\n"); };
 void person_print(struct Person *this);
 static int setNome(Class Person *this,char *nome);
 int setAge(Class Person *this, uint8_t age);
 int setHeight(Class Person *this, uint8_t height);

// Definição da vtable
 typedef struct
 {
    void (*Pessoa_ola)();
    void (*Pessoa_bye)();
    void (*person_print)(Class Person *this);
    
    int (*setNome)(Class Person *this, char *nome);
    int (*setAge)(Class Person *this, uint8_t age);
    int (*setHeight)(Class Person *this, uint8_t height);

 } Vtable;

// Variavel Global, inicializa os membros de dados vtable:
 Vtable vtable =
 {
    &Pessoa_ola,
    &Pessoa_bye,
    &person_print,
   
    &setNome,
    &setAge,
    &setHeight
 };

Class Person{
	
    char nome[10];
	uint8_t age;
	uint8_t height;

    Vtable *vtable;
};
			   
Class Person* newPerson(char nome[], uint8_t age, uint8_t height)
{
	Class Person *this = (Class Person*)malloc(sizeof(Class Person));

    // inicializa os membros da vtable:
    this->vtable = (Vtable*)(&vtable);

    this->vtable->setNome(this, nome);
    this->vtable->setAge(this, age);
    this->vtable->setHeight(this, height);

	return this;
}

// Métodos 
void person_print(Class Person *this)
{
	printf("Person: %s %d %d\n", this->nome, this->age, this->height);
}

int setNome(Class Person *this,char *nome)
{
    strncpy(this->nome, nome, sizeof(this->nome));
    return 0;
}

int setAge(Class Person *this, uint8_t age)
{
    this->age = age;
    return 0;
}

int setHeight(Class Person *this, uint8_t height)
{
    this->height = 172;
    return 0;
}