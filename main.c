#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#define    BUFFERLENGTH 256
int main(int argc, char *argv[])
{
	HANDLE hComm;                           // Identificador para a porta serial
	DWORD MORO;
	char   *pcCommPort = "COM1";            // Nome da porta serial a ser aberta,
	BOOL Write_Status;
	DCB dcbSerialParams;					// Inicializando a estrutura do DCB
	COMMTIMEOUTS timeouts = { 0 };
	BOOL  Read_Status;                      // Status das várias operações
	DWORD dwEventMask;						// Máscara de evento para acionar
	char  TempChar = "";                    // Caráter temporário
	char  *SerialBuffer[BUFFERLENGTH+1];    // Buffer contendo dados Rxed
	DWORD NoBytesRead;                      // Bytes lidos por ReadFile ()
	int i = 0;


	printf("\n\n +==========================================+");
	printf("\n |  Transmissao Serial (Win32 API)         |");
	printf("\n +==========================================+\n");

	hComm = CreateFileA(pcCommPort,
		GENERIC_READ | GENERIC_WRITE,
		0,    // deve ser aberto com acesso exclusivo
		NULL, // sem atributos de segurança
		OPEN_EXISTING, // deve usar OPEN_EXISTING
		0,    // sem sobreposição de E / S
		NULL  // O modelo deve ser NULL para dispositivos de comunicação
	);

	if (hComm == INVALID_HANDLE_VALUE)
	{

		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			puts("nao pode abrir a porta!");
			return;
		}

		puts("valor de identificador invalido!");
		return;
	}
	else
	  printf("Porta serial aberta com Sucesso");

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	Write_Status = GetCommState(hComm, &dcbSerialParams);     //recupera as configurações atuais

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

	Write_Status = SetCommState(hComm, &dcbSerialParams);  //Configurando a porta de acordo com as configurações no DCB

	if (Write_Status == FALSE)
	{
		printf("\n   Erro! na configuração da estrutura do DCB");
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

	// Definir as configurações de tempo limite da porta COM
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
	char lp[] = "augusto\r\n";		// lpBuffer deve ser uma matriz char ou byte, caso contrário, a escrita falhará

	DWORD  NumWritten;
	DWORD  dNoOFBytestoWrite;              // Não de bytes para gravar na porta
	DWORD  dNoOfBytesWritten = 0;          // Nenhum dos bytes gravados na porta

	dNoOFBytestoWrite = sizeof(lp); // Calculando o número de bytes para gravar na porta


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

	/*------------------------------------ Configurando Máscara de Recebimento----------------------------------------------*/

	Read_Status = SetCommMask(hComm, EV_RXCHAR); // Configurar o Windows para monitorar o dispositivo serial para recepção de caractere
	if (Read_Status == FALSE)
		printf("\n\n    Erro! na configuracao CommMask");
	else
		printf("\n\n    Definindo o CommMask com exito");


	/*------------------------------------ Definindo o evento WaitComm()   ----------------------------------------*/

	printf("\n\n    Aguardando a recepcao de dados");

	Read_Status = WaitCommEvent(hComm, &dwEventMask, NULL); //Aguarde até que o caractere a ser recebido

	 /*-------------------------- Programa vai esperar aqui até que um caracter seja recebido ------------------------*/

	if (Read_Status == FALSE)
	{
		printf("\n    Erro! na configuração WaitCommEvent ()");
	}
	else //Se WaitCommEvent () == True Ler os dados RXed usando ReadFile();
	{
		printf("\n\n    Caracteres recebidos \t");



		do
		{
			Read_Status = ReadFile(hComm, &TempChar, sizeof(TempChar), &NoBytesRead, NULL);
			if (!ReadFile(hComm, SerialBuffer, BUFFERLENGTH, &NoBytesRead, NULL))
			{
				printf("caracter errado");
			}
			SerialBuffer[i] = TempChar;
			printf("%c", SerialBuffer[i]);
			i++;
		} while (NoBytesRead > 0);



		/*------------Printing the RXed String to Console----------------------*/

		printf("\n\n    ");
		int j = 0;
		for (j = 0; j < i - 1; j++)		// j < i-1 to remover o último caractere duplicado
			printf("%c",SerialBuffer[j]);

	}


	CloseHandle(hComm);// Fechando a porta serial
	printf("\n ==========================================\n");


	return 0;
}

