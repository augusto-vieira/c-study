#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define    BUFFERLENGTH 256
int main(int argc, char *argv[])
{
	char *pcCommPort;

	if (argv[1] != NULL)
	{
		printf("porta: 'COM0' \n", argv[1]);
		strncpy(pcCommPort, argv[1], sizeof(argv[1])); 
	}else
	{
		printf("Informa a porta: 'COM0' ");
		return 1;
	}
	
	HANDLE hComm;                           // Identificador para a porta serial
	DWORD MORO;
	// char   *pcCommPort = "COM4";            // Nome da porta serial a ser aberta,
	BOOL Write_Status;
	DCB dcbSerialParams;					// Inicializando a estrutura do DCB
	COMMTIMEOUTS timeouts = { 0 };
	BOOL  Read_Status;                      // Status das v�rias opera��es
	DWORD dwEventMask;						// M�scara de evento para acionar
	char  TempChar;                    // Car�ter tempor�rio
	char  SerialBuffer[BUFFERLENGTH+1];    // Buffer contendo dados Rxed
	DWORD NoBytesRead;                      // Bytes lidos por ReadFile ()
	int i = 0;


	printf("\n\n +==========================================+");
	printf("\n |  Transmissao Serial (Win32 API)         |");
	printf("\n +==========================================+\n");

	hComm = CreateFileA(pcCommPort,
		GENERIC_READ | GENERIC_WRITE,
		0,    // deve ser aberto com acesso exclusivo
		NULL, // sem atributos de seguran�a
		OPEN_EXISTING, // deve usar OPEN_EXISTING
		0,    // sem sobreposi��o de E / S
		NULL  // O modelo deve ser NULL para dispositivos de comunica��o
	);

	if (hComm == INVALID_HANDLE_VALUE)
	{

		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			puts("nao pode abrir a porta!");
			return 1;
		}

		puts("valor de identificador invalido!");
		return 1;
	}
	else
	  printf("Porta serial aberta com Sucesso");

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	Write_Status = GetCommState(hComm, &dcbSerialParams);     //recupera as configura��es atuais

	if (Write_Status == FALSE) {
		printf("\n   Erro! em GetCommState()");
		CloseHandle(hComm);
		return 1;
	}


	dcbSerialParams.BaudRate = CBR_9600;      // Definindo BaudRate = 9600
	dcbSerialParams.ByteSize = 8;             // Definindo ByteSize = 8
											  //dcbSerialParams.
	dcbSerialParams.StopBits = ONESTOPBIT;    // Definindo StopBits = 1
	dcbSerialParams.Parity = ODDPARITY;       // Definindo Parity = None

	Write_Status = SetCommState(hComm, &dcbSerialParams);  //Configurando a porta de acordo com as configura��es no DCB

	if (Write_Status == FALSE)
	{
		printf("\n   Erro! na configura��o da estrutura do DCB");
		CloseHandle(hComm);
		return 1;
	}
	else
	{
		printf("\n   Definindo a estrutura do DCB bem-sucedida\n");
		printf("\n       Baudrate = %d", dcbSerialParams.BaudRate);
		printf("\n       ByteSize = %d", dcbSerialParams.ByteSize);
		printf("\n       StopBits = %d", dcbSerialParams.StopBits);
		printf("\n       Parity   = %d", dcbSerialParams.Parity);
	}

	// Definir as configura��es de tempo limite da porta COM
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;
	if (SetCommTimeouts(hComm, &timeouts) == 0)
	{
		printf("Erro ao definir tempos limite\n");
		CloseHandle(hComm);
		return 1;
	}


	/*----------------------------- Escrevendo um caractere na porta serial----------------------------------------*/
	char lp[] = "A";		// lpBuffer deve ser uma matriz char ou byte, caso contr�rio, a escrita falhar�

	DWORD  NumWritten;
	DWORD  dNoOFBytestoWrite;              // N�o de bytes para gravar na porta
	DWORD  dNoOfBytesWritten = 0;          // Nenhum dos bytes gravados na porta

	dNoOFBytestoWrite = sizeof(lp); // Calculando o n�mero de bytes para gravar na porta


	if (!WriteFile(hComm, lp, dNoOFBytestoWrite,
		&dNoOfBytesWritten, NULL))
	{
		printf("Erro ao gravar texto para %s\n", pcCommPort);
	}
	else
	{
			printf("\n\n    %d bytes escrito para %s\n",
			dNoOfBytesWritten, pcCommPort);
	}

	if (Write_Status == TRUE)
		printf("\n\n    %s - escrito para %s", lp, pcCommPort);
	else
		printf("\n\n   Erro %d Escrevendo para porta serial", GetLastError());

	/*------------------------------------ Configurando M�scara de Recebimento----------------------------------------------*/

	Read_Status = SetCommMask(hComm, EV_RXCHAR); // Configurar o Windows para monitorar o dispositivo serial para recep��o de caractere
	if (Read_Status == FALSE)
		printf("\n\n    Erro! na configuracao CommMask");
	else
		printf("\n\n    Definindo o CommMask com exito");


	/*------------------------------------ Definindo o evento WaitComm()   ----------------------------------------*/

	printf("\n\n    Aguardando a recepcao de dados");

	Read_Status = WaitCommEvent(hComm, &dwEventMask, NULL); //Aguarde at� que o caractere a ser recebido

	 /*-------------------------- Programa vai esperar aqui at� que um caracter seja recebido ------------------------*/

	if (Read_Status == FALSE)
	{
		printf("\n    Erro! na configura��o WaitCommEvent ()");
	}
	else //Se WaitCommEvent () == True Ler os dados RXed usando ReadFile();
	{
		printf("\n\n    Caracteres recebidos: \t");
		do
		{
			Read_Status = ReadFile(hComm, &TempChar, sizeof(TempChar), &NoBytesRead, NULL);
			Sleep(500); // Tempo para ler o caracter, muito baixo, ele não consegue ler corretamente 
			SerialBuffer[i] = TempChar;
			printf("%c", SerialBuffer[i]);
			i++; 
		} while (NoBytesRead > 0);
		/*------------Printing the RXed String to Console----------------------*/
	}

	CloseHandle(hComm);// Fechando a porta serial
	printf("\n ==========================================\n");
	
	return 0;
}

