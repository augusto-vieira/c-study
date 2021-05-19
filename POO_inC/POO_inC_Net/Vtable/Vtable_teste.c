/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define Class struct

Class Person;

void Pessoa_ola() { printf("Bom dia\n"); };
void Pessoa_bye() { printf("Adeus\n"); };
void person_print(Class Person *this);
int setNome(Class Person *this,char *nome);
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

int main(){
	
	Class Person *person2 = newPerson("Ana", 43, 172);

	person2->vtable->person_print(person2);
    person2->vtable->Pessoa_bye();
    person2->vtable->Pessoa_ola();
    
    person2->vtable->setNome(person2, "Augusto");
    person2->vtable->person_print(person2);
    
	return 0;
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
} */


/*

// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


#include "Person.h"



int main(){
	
	Class Person *person2 = newPerson("Ana", 43, 172);

    setAge(person2, 55);
    person_print(person2);


	//person2->vtable->person_print(person2);
    
/*    person2->vtable->Pessoa_bye();
    person2->vtable->Pessoa_ola();
    
    person2->vtable->setNome(person2, "Augusto");
    person2->vtable->person_print(person2);*/
  /*  
	return 0;
} */
 

// ===========================================================================
