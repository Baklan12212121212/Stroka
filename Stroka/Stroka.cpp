/*
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 100;
    char str[SIZE];

    cout << "Введите строку: ";
    cin.getline(str, SIZE);

    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            str[length++] = str[i];
        }
    }
    str[length] = '\0';

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    for (int i = 2; i < length; i += 3) {
        cout << str[i] << str[i];
    }

    cout << std::endl;
    
    return 0;
}
*/
/*
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    setlocale(LC_ALL, "RU");
    char str[256];

    printf("Введите строку: ");
    fgets(str, 256, stdin);

    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            str[length++] = str[i];
        }
    }
    str[length] = '\0';
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    for (int i = 0; i < length; i++) {
        if ((i + 1) % 3 == 0) {
            putchar(str[i]);
        }
        putchar(str[i]);
    }

    printf("\n");
    return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "RU");
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Ошибка при открытии файла");
        return 0;
    }

    char str[256];
    fgets(str, 256, inputFile);

    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            str[length++] = str[i];
        }
    }
    str[length] = '\0';

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    for (int i = 0; i < length; i++) {
        if ((i + 1) % 3 == 0) {
            fputc(str[i], outputFile);
        }
        fputc(str[i], outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Обработка завершена. Результат записан в output.txt\n");
    return 0;
}
