// login.c
#include <stdio.h>
#include <string.h>

int main() {
    char user[20];
    char pass[20];

    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "2025") == 0) {
        printf("Login successful!\n");
        return 0;
    } else {
        printf("Login failed.\n");
        return 1;
    }
}
