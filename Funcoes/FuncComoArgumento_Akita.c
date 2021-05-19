// https://www.youtube.com/watch?v=Gp2m8ZuXoPg&ab_channel=FabioAkita

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define Class struct


/*
struct Person{
	char nome[10];
	uint8_t age;
	uint8_t height;
};
															// Ponteiro para função que não recebe nada
void createPerson(char nome[], uint8_t age, uint8_t height, void (*function_pointer)(struct Person))
{
	struct Person person;
	strcpy(person.nome, "Fabio");
	person.age = age;
	person.height = height;
	
	//Referência para algum endereço de função, uma função que seja "void" e tenha "struct Person" como argumento
	(*function_pointer)(person);
}

// Função que vamos passar para "function_pointer"
void printPerson(struct Person person)
{
	printf("Person: %s %d %d\n", person.nome, person.age, person.height);
}

void printPerson2(struct Person person)
{
	printf("Nome: %s Age: %d height: %d\n", person.nome, person.age, person.height);
}

int main(){
	
	createPerson("Fabio", 43, 172, &printPerson);
	createPerson("Fabio", 43, 172, &printPerson2);
	return 0;
}
  */

//====================================================================================================================
//	REFATORANDO
//====================================================================================================================


Class Person{
	char nome[10];
	uint8_t age;
	uint8_t height;
				 // Passagem por referência, assim economiza espaço na pilha(Steck)
	void (*show)(Class Person*);
};


void person_print(Class Person *this)
{
	printf("Person: %s %d %d\n", this->nome, this->age, this->height);
}

			   // Instanciar um objeto 	
Class Person* newPerson(char nome[], uint8_t age, uint8_t height)
{
	Class Person *this = (Class Person*)malloc(sizeof(Class Person));
	strcpy(this->nome, "Fabio");
	this->age =  age;
	this->height = height;
	
	this->show = &person_print;
	return this;
}


int main(){
	
	Class Person *person2 = newPerson("Fabio", 43, 172);
	// show = método daquele objeto
	person2->show(person2);
	return 0;
}