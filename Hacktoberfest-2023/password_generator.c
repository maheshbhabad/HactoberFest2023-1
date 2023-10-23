#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generateRandomChar() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    const size_t charsetSize = sizeof(charset) - 1;
    return charset[rand() % charsetSize];
}

void generatePassword(char* password, int length) {
    for (int i = 0; i < length; i++) {
        password[i] = generateRandomChar();
    }
    password[length] = '\0';
}

int main() {
    srand(time(NULL));

    int passwordLength;
    printf("Enter the desired password length: ");
    scanf("%d", &passwordLength);

    if (passwordLength <= 0) {
        printf("Invalid password length.\n");
        return 1;
    }

    char password[passwordLength + 1];
    generatePassword(password, passwordLength);

    printf("Generated Password: %s\n", password);

    return 0;
}
