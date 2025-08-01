#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    char target_ip[100];
    printf("Enter IP address to scan: ");
    scanf("%s", target_ip);

    struct sockaddr_in server;
    int sock;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(target_ip);

    for (int port = 1; port <= 1024; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
            printf("Port %d is OPEN\n", port);
        }
        close(sock);
    }

    return 0;
}
