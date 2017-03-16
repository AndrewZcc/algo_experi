#include "CN_socket.h"

void main_other()
{
    int server_sock;
    int client_sock;

    // 备注: sockaddr_in 在 <netinet/in.h> 头文件中定义
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    socklen_t client_address_size;

    server_sock = socket(PF_INET, SOCK_STREAM, 0);

    if (server_sock == -1)
    {
        handleError("socket error!");
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if (bind(server_sock, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
        handleError("bind error!");
    }

    if (listen(server_sock, 5) == -1)
    {
        handleError("listen error!");
    }

    while (true)
    {
        client_address_size = sizeof(client_address);
        client_sock = accept(server_sock, (struct sockaddr*)&client_address, &client_address_size);

        if (client_sock == -1)
        {
            handleError("accept error!");
        }

        requestHandling(&client_sock);
    }

    close(server_sock);
}