#include <stdio.h>

int main(int argc, char **argv)
{			
	char buffer[100] = {0};
	char name[] = "Augusto";
	int age = 26;

	char *query = "INSERT INTO  PERSON_TB (NAME, AGE)('%s', %d);";
	
	snprintf(buffer, 100, query, name, age);
	printf("%s",buffer);

	return 0; 
}
