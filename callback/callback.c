// Referência
https://github.com/NakedSolidSnake/Raspberry_mysql/blob/master/lib/db.c
https://github.com/NakedSolidSnake/C_Webserver_Registry/blob/main/src/main.c

// lib.h
int Teste_insert_(char *(*insert)(void *data), void *data);

//Lib.c
int Teste_insert_(char *(*insert)(void *data), void *data)
{
	if(insert == NULL)
	{
		printf("Erro - Insert\n");
		return -1;
	}
    
	if(data == NULL)
	{
		return -1;
		printf("Erro - data\n");
	}
	
	mysql_autocommit(con, false);
	if (mysql_query(con,insert(data)))
	{
	    fprintf(stderr, "Erro: %s\n", mysql_error(con));
		mysql_rollback(con);
        mysql_close(con);
		return false;
	}
	mysql_commit(con);
	return true;
}


// main.c
#define BUFFER 512

typedef struct
{
	int id;
	unsigned short int dia,mes,ano;
	char name[40];
    char name_table[40];
} Usuario;
char *insert_Table(void *data)
{
	static char msg[BUFFER];
    Usuario *user = (Usuario*)data;

    printf("Nome da tabela a inserir: ");
	scanf("%40s",user->name_table);
	cleanBuffer();
	
	printf("Digite o Ano: ");
	scanf("%hd",&user->ano);
	cleanBuffer(); 
		
	printf("Digite o Mes: ");
	scanf("%hd",&user->mes);
	cleanBuffer();

	printf("Digite o Dia: ");
	scanf("%hd",&user->dia);
	cleanBuffer();

	printf("Digite o nome do Usuario: ");
	scanf("%40s",user->name);
	cleanBuffer();

	printf("Digite o id: ");
	scanf("%d",&user->id);
	cleanBuffer();  
	
	snprintf(msg,BUFFER, "INSERT INTO %s VALUES (%d,%hd-%hd-%hd,'%s')",user->name_table, user->id, user->ano, user->mes, user->dia, user->name);//nome_table, id,ano,mes,dia, usuario);
	printf("%s\n",msg);

	return msg;
}

   int main(){

   
    Usuario augusto;
    menu();   

    printf("%s\n", false < Teste_insert_(query_registroTable, &augusto) ? "SUCESSO" : "ERRO" );
    // printf("Name %s\n",query_registroTable(&augusto));

    printf("Ano:%d - dia:%d - nome:%s", augusto.ano, augusto.dia, augusto.name);
   }
