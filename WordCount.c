#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countChars(const char *filename);
void countWords(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        countChars(argv[2]);
    } else if (strcmp(argv[1], "-w") == 0) {
        countWords(argv[2]);
    } else {
        printf("Invalid parameter: %s\n", argv[1]);
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    return 0;
}

void countChars(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int charCount = 0;
    int currentChar;
    while ((currentChar = fgetc(file)) != EOF) {
        charCount++;
    }

    fclose(file);
    printf("×Ö·ûÊý£º%d\n", charCount);
}

void countWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int wordCount = 0;
    char currentChar, previousChar = ' ';
    while ((currentChar = fgetc(file)) != EOF) {
        if ((currentChar == ' ' || currentChar == ',' || currentChar == '\n' || currentChar == '\t') &&
            !(previousChar == ' ' || previousChar == ',' || previousChar == '\n' || previousChar == '\t')) {
            wordCount++;
        }
        previousChar = currentChar;
    }

    if (!(previousChar == ' ' || previousChar == ',' || previousChar == '\n' || previousChar == '\t')) {
        wordCount++;
    }

    fclose(file);
    printf("µ¥´ÊÊý£º%d\n", wordCount);
}


