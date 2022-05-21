#include "s21_grep.h"

void buildOutput(const char** filePathArr, size_t filesCount,
                 regex_t* redexArr, size_t redexCount, int emptyPatternFlag) {
    regex_t regObj;
    char lastOccurrenceStr[512] = "\0";
    int regexFromFileDone = 0;

    for (size_t i = 0; i < filesCount; i++) {  // file scroller
            const char* filePath = filePathArr[i];
            FILE * file;

            if ((file = fopen(filePath, "rt")) == NULL) {
                if (flag.s == 0) {
                  fprintf(stderr, "grep: %s: No such file or directory\n", filePath);
                }
                continue;
            }

            int succsessScore = 0;
            char * line = NULL;
            size_t len = 0;
            ssize_t read;
            int lineCount = 0;
            int over = 0;
            bool IsFileHaveOccurrence = false;

            if (flag.f == 1 && regexFromFileDone == 0) {
                while ((read = getline(&line, &len, file)) != EOF) {
                    char TempStr[512] = "\0";
                    strncpy(TempStr, line, strlen(line));
                    if (strlen(line) > 0 && (line[strlen(line)-1] == '\n')) {  // remove \n in pattern line
                        TempStr[strlen(line) - 1] = '\0';
                    }
                    if (regcomp(&regObj, TempStr, flag.regflag) == 0) {
                        redexArr[redexCount] = regObj;
                        redexCount++;
                    }
                }
            regexFromFileDone = 1;
            continue;
            }

            if (!feof(file)) {
                while ((read = getline(&line, &len, file) != EOF) && over == 0) {  // line scroller
                    lineCount++;
                    int compare = 0;
                    int succsess = 1;
                    size_t j = 0;

                    while (j < redexCount && succsess != 0) {  // patern scroller
                        succsess = regexec(&redexArr[j], line, 0, NULL, 0);
                        j++;
                    }

                    if (emptyPatternFlag == 1) {
                        succsess = 0;
                    }

                    if (flag.v == 1) {
                        compare = REG_NOMATCH;
                    }

                    if (succsess == compare) {
                        succsessScore++;
                        IsFileHaveOccurrence = true;
                    }

                    if (flag.l == 1 && succsess == compare && flag.c == 0) {
                        printf("%s\n", filePath);
                        over = 1;
                    }

                    if (succsess == compare && over == 0 && flag.c == 0) {
                        if ((filesCount > 2 && regexFromFileDone == 1) ||
                            (filesCount > 1 && flag.h == 0 && flag.f == 0)) {
                            printf("%s:", filePath);
                        }

                        if (flag.n == 1 && flag.c == 0) {
                            printf("%d:", lineCount);
                        }

                        if (flag.o == 1) {
                            regmatch_t pmatch[1] = {};
                            int occurrenceFound = 0;
                            #ifdef __linux__
                            int occurrenceOnLineCount = 0;
                            #endif
                            char *matchingLine = line;

                            while (occurrenceFound == 0) {
                                occurrenceFound = regexec(&redexArr[0], matchingLine, 1, pmatch, 0);

                                #ifdef __linux__
                                if (occurrenceFound != REG_NOMATCH) {
                                    occurrenceOnLineCount++;
                                }

                                if (filesCount > 1 && occurrenceOnLineCount > 1
                                     && occurrenceFound != REG_NOMATCH) {
                                    printf("%s:", filePath);
                                }
                                #endif

                                while (pmatch[0].rm_so < pmatch[0].rm_eo) {
                                    printf("%c", matchingLine[pmatch[0].rm_so]);
                                    pmatch[0].rm_so++;
                                }

                                if (occurrenceFound == 0) {
                                    printf("\n");
                                }
                                matchingLine += pmatch[0].rm_eo;
                            }
                        } else {
                            printf("%s", line);
                        }
                        strncpy(lastOccurrenceStr, line, strlen(line)+1);
                    }
                }
                if (flag.c == 1) {
                    if (flag.l == 1) {
                        #ifdef __APPLE__
                        printf("%d\n", IsFileHaveOccurrence);
                        #endif
                        printf("%s\n", filePath);
                    }

                    if (flag.l == 0) {
                        if (flag.f == 1) --filesCount;

                        if ((filesCount > 1 && flag.h == 0) ||
                            (filesCount > 2 && regexFromFileDone == 1)) {
                            printf("%s:", filePath);
                        }

                        printf("%d\n", succsessScore);
                    }
                }
            }

        if (IsFileHaveOccurrence && strlen(lastOccurrenceStr) > 0
             && (lastOccurrenceStr[strlen(lastOccurrenceStr)-1] != '\n')
             && flag.o == 0) {  // epmty end file fix
            printf("\n");
        }

        free(line);
        fclose(file);
    }
}

void grep(int argc, char const *argv[]) {
    if (argc > 1) {
        FILE* file;
        const char* filePathArr[32];
        regex_t redexArr[32];
        size_t currentArg = 1;
        size_t filesCount = 0;
        size_t redexCount = 0;
        regex_t regObj;
        int flagCount = 0;
        int emptyPatternFlag = 0;

        while ((int)currentArg < argc)  {
            char* argStr = (char*)argv[currentArg];
            if (argStr[0] == '-') {
                flagCount++;
                for (size_t j = 1; j < strlen(argStr); j++) {
                    switch (argStr[j])  {
                        case 'e':
                            flag.e = 1;
                            break;
                        case 'i':
                            flag.i = 1;
                            flag.regflag = REG_ICASE;
                            break;
                        case 'v':
                            flag.v = 1;
                            #ifdef __linux__
                            flag.o = 0;
                            #endif
                            break;
                        case 'c':
                            flag.c = 1;
                            break;
                        case 'l':
                            flag.l = 1;
                            flag.o = 0;
                            break;
                        case 'n':
                            flag.n = 1;
                            break;
                        case 'h':
                            flag.h = 1;
                            break;
                        case 's':
                            flag.s = 1;
                            break;
                        case 'f':
                            flag.f = 1;
                            break;
                        case 'o':
                            #ifdef __APPLE__
                            if (flag.v == 0 && flag.l == 0) {
                              flag.o = 1;
                            }
                            #elif __linux__
                              flag.o = 1;
                            #endif
                            break;
                        default:
                            fprintf(stderr, "grep: invalid option '%s'\n", argv[currentArg]);
                            exit(EXIT_FAILURE);
                            break;
                    }
                }
            }
            currentArg++;
        }

        currentArg = 1;

        while ((int)currentArg < argc) {
            char* argStr = (char*)argv[currentArg];
            if (argStr[0] == '-') {
                currentArg++;
            } else {
                if ((file = fopen(argv[currentArg], "rt")) == NULL) {
                    if (regcomp(&regObj, argv[currentArg], flag.regflag) == 0) {
                        redexArr[redexCount] = regObj;
                        redexCount++;
                    } else if (strlen(argv[currentArg]) == 0) {
                        emptyPatternFlag = 1;
                    }
                } else {
                    fclose(file);
                    --currentArg;
                }

                while ((int)++currentArg < argc && argv[currentArg][0] != '-') {
                    filePathArr[filesCount] = argv[currentArg];
                    filesCount++;
                }
            }
        }

        buildOutput(filePathArr, filesCount, redexArr, redexCount, emptyPatternFlag);

        for (size_t i = 0; i < redexCount; i++) {
            regfree(&redexArr[i]);
        }
    }
}

int main(int argc, char const *argv[]) {
    grep(argc, argv);
    return 0;
}
