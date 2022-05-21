#include "s21_cat.h"
void printNonReadableChar(char c, int *NonBlankLineCount, int *everyLineCount) {
    if (c < -96) {
    c = c + 192;
    printf("M-^%c", c);
    if ((flag.n == 1) && c == 'J') {
    printf("%6d\t", *everyLineCount += 1);
    } else if ((flag.b == 1) && c == 'J') {
    printf("%6d\t", *NonBlankLineCount += 1);
    }
    } else if (c == 9 || c == 10) {
    printf("%c", c);
    } else if (c >= 0 && c < 32) {
    printf("^%c", c + 64);
    } else if (c >= 32 && c < 127) {
    printf("%c", c);
    } else if (c == 127) {
    printf("^%c", c - 64);
    } else {
    printf("%c", c);
    }
}

void buildOutput(const char** filePathArr, size_t filesCount) {
    #ifdef __linux__
    int NonBlankLineCount = 0;
    int everyLineCount = 0;
    #endif

    for (size_t i = 0; i < filesCount; i++) {
        const char* filePath = filePathArr[i];
        FILE * file;
        if ((file = fopen(filePath, "rt")) == NULL) {
            fprintf(stderr, "cat: %s: No such file or directory", filePath);
            break;
        }

        int LineBreakCount = 0;
        int IsNumeredLine = 0;

        #ifdef __APPLE__
        int NonBlankLineCount = 0;
        int everyLineCount = 0;
        #endif

        char currentChar;
        while (!feof(file)) {
            if ((currentChar = fgetc(file)) != EOF) {
                if (flag.n == 1 && flag.b == 0 && IsNumeredLine == 0) {
                    if (flag.s == 1 && LineBreakCount > 1) {
                        /* skip squeeze-blank line */
                    } else {
                    everyLineCount++;
                    printf("%6d\t", everyLineCount);
                    IsNumeredLine = 1;
                    }
                }

                if (currentChar != '\n') {
                    if (flag.b == 1 && IsNumeredLine == 0) {
                        NonBlankLineCount++;
                        printf("%6d\t", NonBlankLineCount);
                        IsNumeredLine = 1;
                    }

                    ///  str scroller  ///
                    while (currentChar != '\n' && !feof(file)) {
                        LineBreakCount = 0;
                        if (flag.t == 1 && currentChar == '\t') {
                            printf("^I");
                        } else {
                            if (flag.v) {
                                printNonReadableChar(currentChar, &NonBlankLineCount, &everyLineCount);
                            } else {
                                printf("%c", currentChar);
                            }
                        }
                        currentChar = fgetc(file);
                    }
                    if (currentChar != EOF) {
                        if (flag.e == 1) {
                            printf("$");
                        }
                        printf("%c", currentChar);
                        IsNumeredLine = 0;
                        continue;
                    }
                }

                if (currentChar == '\n') {
                    LineBreakCount++;
                    if (flag.e == 1 && flag.s == 0) {
                        printf("$");
                    }

                    if (flag.s == 1 && LineBreakCount < 2) {
                        if (flag.e == 1) {
                            printf("$");
                        }
                        printf("%c", currentChar);
                    }

                    if (flag.s == 0 && currentChar != EOF) {
                        printf("%c", currentChar);
                    }
                    IsNumeredLine = 0;
                }
            }
        }
        fclose(file);
    }
}

void s21_cat(int argc, char const *argv[]) {
    if (argc > 1) {
        const char* filePathArr[32];
        int i = 1;
        size_t filesCount = 0;

        while (i < argc) {
            char* argStr = (char*)argv[i];
            if (argStr[0] == '-') {
                int isLongFlag = 0;
                for (size_t i = 1; i < strlen(argStr) && isLongFlag == 0; i++) {
                    switch (argStr[i]) {
                        case '-':
                            isLongFlag = 1;
                            if (strcmp(argStr, "--number-nonblank") == 0) {
                                flag.b = 1;
                            } else if (strcmp(argStr, "--number") == 0) {
                                flag.n = 1;
                            } else if (strcmp(argStr, "--squeeze-blank") == 0) {
                                flag.s = 1;
                            }
                            break;
                        case 'b':
                            flag.b = 1;
                            break;
                        case 'e':
                            flag.e = 1;
                            flag.v = 1;
                            break;
                        #ifdef __linux__
                        case 'E':
                            flag.e = 1;
                            break;
                        #endif
                        case 'n':
                            flag.n = 1;
                            break;
                        case 's':
                            flag.s = 1;
                            break;
                        case 't':
                            flag.t = 1;
                            flag.v = 1;
                            break;
                        #ifdef __linux__
                        case 'T':
                            flag.t = 1;
                            break;
                        #endif
                        default:
                            fprintf(stderr,
                            "cat: invalid option -- '%s'\nTry 'cat --help' for more information.", argv[i]);
                            exit(EXIT_FAILURE);
                            break;
                    }
                }
            } else {
                filePathArr[filesCount] = argv[i];
                filesCount++;
                    }
            i++;
        }
        buildOutput(filePathArr, filesCount);
    }
}

int main(int argc, char const *argv[]) {
    s21_cat(argc, argv);
    return 0;
}
