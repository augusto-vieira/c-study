#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT     8080

int main (void)
{
    int socket_desc;
    struct sockaddr_in server_addr, client_addr;

    char server_message[100], client_message[100];
    int client_struct_length = sizeof(client_addr);

    // Limpa o buffer:
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    // Cria UDP socket:
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if(socket_desc < 0)
    {
        printf("Error para criar socket\n");
        return -1;
    }
    printf("Socket criado com sucesso \n");

    // Set porta e IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
   // server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_addr.s_addr = inet_addr("192.168.15.9");

    // Vinculando a porta e IP
    if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Nao foi possivel conectar a porta. \n");
        return -1;
    }
    printf("Concluido vinculacao\n");
    printf("Ouvindo mensagens... \n\n");

    // Recebendo mensagem do cliente
    if(recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr*)&client_addr, &client_struct_length) < 0)
    {
        printf("Nao foi possivel receber\n");
        return -1;
    }
    printf("Mensagem recebida do IP: %s e porta: %i \n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    printf("Msg do client: %s\n", client_message);

    // Mudar para maiúsculas:
    for(int i = 0; client_message[i]; ++i)
        client_message[i] = toupper(client_message[i]);
    
    // Responde ao client
    strcpy(server_message, client_message);

    if(sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr, client_struct_length) < 0)
    {
        printf("Nao pode enviar\n");
        return -1;
    }
    
    // Sair do  socket:
    close(socket_desc);
   
    return 0;
}
