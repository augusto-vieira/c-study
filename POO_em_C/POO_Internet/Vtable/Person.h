#ifndef PERSON_H_
#define PERSON_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define Class struct
Class Person;

Class Person* newPerson(char nome[], uint8_t age, uint8_t height);

 void person_print(struct Person *this);
 int setNome(Class Person *this,char *nome);
 static int setAge(Class Person *this, uint8_t age);
 int setHeight(Class Person *this, uint8_t height);

#endif // PERSON_H_