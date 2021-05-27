#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT     8080

int main(void)
{
    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[100], client_message[100];
    int server_struct_length = sizeof(server_addr);

    // Limpando buffers:
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    
    // Criando socket
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
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Pega dado do usuario
    printf("Entre com a mensagem: ");
    fgets(client_message, sizeof(client_message), stdin);

    // Envie a mensagem para o servidor:
    if(sendto(socket_desc, client_message, strlen(client_message), 0, (struct sockaddr*)&server_addr, server_struct_length) < 0){
        printf("Erro ao enviar msg\n");
        return -1;
    }

    // Recebe a mensagem do servidor
    if(recvfrom(socket_desc, server_message, sizeof(server_message), 0, (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        printf("Erro ao receber mensagem do servidor \n");
        return -1;
    }
    
    printf("Servidor respondeu: %s\n", server_message);

    // Sair do  socket:
    close(socket_desc);
    
    return 0;
}
