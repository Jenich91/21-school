#include "s21_smartCalc.h"

void push(stack_char *stack, char value) {
    if (stack->size < 256) {
        stack->data[stack->size] = value;
        stack->size++;
    }
}

char pop(stack_char *stack) {
    if (stack->size > 0) {
    stack->size--;
    return stack->data[stack->size];
    }
    return '\0';
}

char peek(stack_char *stack) {
    if (stack->size > 0) {
    return stack->data[stack->size-1];
    }
    return '\0';
}

//--------------------------//
void push_double(stack_double *stack, double value) {
    if (stack->size < 256) {
    stack->data[stack->size] = value;
    stack->size++;
    }
}

double pop_double(stack_double *stack) {
    if (stack->size > 0) {
    stack->size--;
    return stack->data[stack->size];
    }
return NAN;
}
//--------------------------//

bool isOperator(char ch) {
    char* operators = "-+/*^%u";
    if (strchr(operators, (int)ch) != NULL) {
        return true;
    }
    return false;
}

int checkPriority(char ch1) {
    int chPrior = 0;
    switch (ch1) {
    case '(':
        chPrior = LOW;
        break;
    case ')':
        chPrior = LOW;
        break;
    case '-':
        chPrior = MID;
        break;
    case '+':
        chPrior = MID;
        break;
    case '*':
        chPrior = HIGH;
        break;
    case '/':
        chPrior = HIGH;
        break;
    case '%':
        chPrior = HIGH;
        break;
    case '^':
        chPrior = ULTRA;
        break;
    case 'u':
        chPrior = ULTRA;
    default:
        break;
    }
    return chPrior;
}

stack_char ParseToPolishNotation(char * buff) {
    stack_char stack = {{"\0"}, 0};
    stack_char outputStack = {{"\0"}, 0};
    bool exitFlag = false;

    for (size_t i = 0; i < strlen(buff) && !exitFlag; i++) {
        // Число - добавляем в строку вывода
        if (isdigit(buff[i]) || buff[i] == 'x' || buff[i] == '.') {
            while (isdigit(buff[i]) || buff[i] == 'x' || buff[i] == '.') {
                push(&outputStack, buff[i]);
                i++;
            }
            push(&outputStack, ' ');
        }
        // Функция или открывающая скобка - помещаем в стек.
        if (buff[i] == '(' || (isalpha(buff[i]) && buff[i] != 'u')) {
            push(&stack, buff[i]);
        } else if (isOperator(buff[i])) {
            if (buff[i] != '^') {
                while (stack.size != 0 && checkPriority(peek(&stack)) >= checkPriority(buff[i])) {
                    push(&outputStack, pop(&stack));
                }
            }
                push(&stack, buff[i]);
        } else if (buff[i] == ')') {
            // Пока лексема на вершине стека не станет открывающей скобкой
            // перекладываем лексемы-операторы из стека в выходную очередь.
            while (stack.size > 0 && peek(&stack) != '(') {
                push(&outputStack, pop(&stack));
            }
            // Удаляем из стека открывающую скобку.
            if (stack.size != 0) {
                pop(&stack);
            }
            // Если лексема на вершине стека — функция, перекладываем её в выходную очередь.
            if (stack.size != 0 && isalpha(peek(&stack))) {
                    push(&outputStack, pop(&stack));
            }
        }
    }

    while (stack.size != 0) {
        push(&outputStack, pop(&stack));
    }

    return outputStack;
}

double Calculate(stack_char inputStack, double x) {
    stack_double doubleStack = {{0.0}, 0};

    size_t len = strlen(inputStack.data);
    for (size_t i = 0; i < len; i++) {
        char tmp[256] = "\0";
        if (inputStack.data[i] == 'x') {
            push_double(&doubleStack, x);
        } else if (isdigit(inputStack.data[i])) {
            double num = 0.0;
            int j = 0;
            while (isdigit(inputStack.data[i]) || inputStack.data[i] == '.') {
                tmp[j] = inputStack.data[i];
                j++;
                i++;
            }
            num = strtod(tmp, NULL);
            push_double(&doubleStack, num);
        } else if (isOperator(inputStack.data[i])) {
            if (inputStack.data[i] == 'u' && doubleStack.size >= 1) {
                double operand1 = pop_double(&doubleStack);
                push_double(&doubleStack, operand1*-1);
            } else if (doubleStack.size >= 2) {
                double operand1 = pop_double(&doubleStack);
                double operand2 = pop_double(&doubleStack);
                switch (inputStack.data[i]) {
                case '-':
                    push_double(&doubleStack, operand2 - operand1);
                    break;
                case '+':
                    push_double(&doubleStack, operand2 + operand1);
                    break;
                case '/':
                    push_double(&doubleStack, operand2 / operand1);
                    break;
                case '*':
                    push_double(&doubleStack, operand2 * operand1);
                    break;
                case '%':
                    push_double(&doubleStack, fmod(operand2, operand1));
                    break;
                case '^':
                    push_double(&doubleStack, pow(operand2, operand1));
                default:
                    break;
                }
            }
        } else if (isalpha(inputStack.data[i]) && doubleStack.size >= 1) {
            switch (inputStack.data[i]) {
            case 'c':
                push_double(&doubleStack, cos(pop_double(&doubleStack)));
                break;
            case 's':
                push_double(&doubleStack, sin(pop_double(&doubleStack)));
                break;
            case 't':
                push_double(&doubleStack, tan(pop_double(&doubleStack)));
                break;
            case 'C':
                push_double(&doubleStack, acos(pop_double(&doubleStack)));
                break;
            case 'S':
                push_double(&doubleStack, asin(pop_double(&doubleStack)));
                break;
            case 'T':
                push_double(&doubleStack, atan(pop_double(&doubleStack)));
                break;
            case 'Q':
                push_double(&doubleStack, sqrt(pop_double(&doubleStack)));
                break;
            case 'l':
                push_double(&doubleStack, log(pop_double(&doubleStack)));
                break;
            case 'L':
                push_double(&doubleStack, log10(pop_double(&doubleStack)));
                break;

            default:
                break;
            }
        }
    }

    return pop_double(&doubleStack);
}

bool DotCheck(char* src) {
    size_t len = strlen(src);
    if (len > 1) {
        for (size_t i = 1; i < len; i++) {
            if (src[i-1] == '.' && src[i] == '.') {
                return false;
            }
            if (src[i-1] == '.' && isOperator(src[i]) && (src[i+1] == '.' || src[i+1] == '\0')) {
                return false;
            }
        }
    }
    return true;
}

void RemoveSpace(char *arr) {
    const char *old = arr;
    while (*old) {
        if (*old != ' ') {
            *arr = *old;
            ++arr;
        }
        ++old;
    }
    *arr = '\0';
}

bool isFuncName(char* src, int i) {
    bool result = false;
    char tempStr[5] = "\0";

    for (size_t j = 0; isalpha(src[i]) && j < 4; j++) {
        tempStr[j] = src[i];
        i++;
    }

    if (strcmp(tempStr, "cos") == 0) {
        result = true;
    } else if (strcmp(tempStr, "sin") == 0) {
        result = true;
    } else if (strcmp(tempStr, "tan") == 0) {
        result = true;
    } else if (strcmp(tempStr, "acos") == 0) {
        result = true;
    } else if (strcmp(tempStr, "asin") == 0) {
        result = true;
    } else if (strcmp(tempStr, "atan") == 0) {
        result = true;
    } else if (strcmp(tempStr, "sqrt") == 0) {
        result = true;
    } else if (strcmp(tempStr, "ln") == 0) {
        result = true;
    } else if (strcmp(tempStr, "log") == 0) {
        result = true;
    }
    return result;
}

bool isMod(char* src, int i) {
    bool result = false;
    char tempStr[4] = "\0";

    for (size_t j = 0; isalpha(src[i]) && j < 4; j++) {
        tempStr[j] = src[i];
        i++;
    }

    if (strncmp(tempStr, "mod", 3) == 0) {
        result = true;
    }
    return result;
}

bool checkBracket(char* src) {
    bool result = true;
    size_t n = strlen(src);
    int open = 0;
    int close = 0;

    if (*src == ')') {
        result = false;
    }

    for (size_t i = 0; i < n; i++) {
        if (src[i] == '(') {
            open++;
        } else if (src[i] == ')') {
            close++;
        }
        if (close > open) {
            result = false;
            break;
        }
        if (src[i] == '(' && src[i+1] == ')') {
            result = false;
            break;
        } else if (src[i] == '(' && isOperator(src[i+1]) && (src[i+2] == ')'  || isOperator(src[i+2]))) {
            result = false;
        } else if (src[i] == '(' && (isOperator(src[i+1]) && src[i+1] != 'u')) {
            result = false;
        }
    }

    if (open != close) {
        result = false;
    }
    return result;
}

char* tryRealloc(char* pointer, int j) {
    pointer = (char*) realloc(pointer, j+1);
    if (pointer == NULL) {
    free(pointer);
    exit(EXIT_FAILURE);
    }

    return pointer;
}

char* AddMultBetweenBracketAndDot(char* src) {
    size_t len = strlen(src);
    char* newStr = NULL;

    int j = 0;
    for (size_t i = 0; i < len; i++) {
        newStr = tryRealloc(newStr, j);
        newStr[j++] = src[i];
        if ((src[i] == ')' && src[i+1] != ')' && !isOperator(src[i+1]))
        || (i < (len-1) && isdigit(src[i]) && isFuncName(src, i+1))
        || (i < (len-1) && isdigit(src[i]) && src[i+1] == '(')
        ) {
            newStr = tryRealloc(newStr, j);
            newStr[j++] = '*';
        } else if (src[i] == '.' && isdigit(src[i-1]) && !isdigit(src[i+1])) {
            newStr = tryRealloc(newStr, j);
            newStr[j++] = '0';
        } else if (!isdigit(src[i-1]) && src[i] == '.' && isdigit(src[i+1])) {
            newStr[j-1] = '0';
            newStr = tryRealloc(newStr, j);
            newStr[j++] = '.';
        }
    }

    newStr = tryRealloc(newStr, j);
    newStr[j] = '\0';
    return newStr;
}

void ReplaceUnarySign(char* inputStr) {
    size_t N = strlen(inputStr);
    for (size_t i = 0; i < N; i++) {
            if ( (i == 0 && isOperator(inputStr[i]) && (isdigit(inputStr[i+1])
            || inputStr[i+1] == '.' || inputStr[i+1] == '(' || isFuncName(inputStr, i+1)))
            || (i > 0 && (isOperator(inputStr[i-1]) || inputStr[i-1] == '(')
            && isOperator(inputStr[i]) && (isdigit(inputStr[i+1])
            || inputStr[i+1] == '(' || isFuncName(inputStr, i+1) || inputStr[i+1] == 'x'))) {
            if (inputStr[i] == '-') {
                inputStr[i] = 'u';
            } else if (inputStr[i] == '+') {
                inputStr[i] = ' ';
            }
        }
    }
    RemoveSpace(inputStr);
}

double GetResult(char *buff, double x) {
    double result = NAN;

    char* dotMulstr = AddMultBetweenBracketAndDot(buff);
    ReplaceUnarySign(dotMulstr);
    ReplaseModAndFunc(dotMulstr);

    stack_char outputStack = ParseToPolishNotation(dotMulstr);

    result = Calculate(outputStack, x);

    free(dotMulstr);
    return result;
}

bool IsNormalInputString(char *buff) {
    bool result = false;

    char InputStr[256] = "\0";
    strncpy(InputStr, buff, sizeof(InputStr));

    char* dotMulstr = AddMultBetweenBracketAndDot(buff);
    ReplaceUnarySign(dotMulstr);

    if (DotCheck(InputStr)
    && checkBracket(dotMulstr)
    && CheckFuncName(dotMulstr)
    && CheckOperator(dotMulstr)) {
        result = true;
    }

    free(dotMulstr);
    return result;
}

void ReplaseModAndFunc(char* arr) {
    char *old = arr;
    while (*old) {
        if (isFuncName(old, 0)) {
            char funcName[5] = "\0";
            for (size_t j = 0; isalpha(*old) && j < 4; j++) {
                funcName[j] = *old;
                ++old;
            }
            old--;

            if (strncmp(funcName, "cos", 3) == 0) {
                *arr = 'c';
            } else if (strncmp(funcName, "sin", 3) == 0) {
                *arr = 's';
            } else if (strncmp(funcName, "tan", 3) == 0) {
                *arr = 't';
            } else if (strncmp(funcName, "acos", 4) == 0) {
                *arr = 'C';
            } else if (strncmp(funcName, "asin", 4) == 0) {
                *arr = 'S';
            } else if (strncmp(funcName, "atan", 4) == 0) {
                *arr = 'T';
            } else if (strncmp(funcName, "sqrt", 4) == 0) {
                *arr = 'Q';
            } else if (strncmp(funcName, "ln", 2) == 0) {
                *arr = 'l';
            } else if (strncmp(funcName, "log", 3) == 0) {
                *arr = 'L';
            }
            arr++;
        } else if (isdigit(*old) || isOperator(*old) || isMod(old, 0)
        || *old == 'x' || *old == '(' || *old == ')' || *old == '.') {
            if (isMod(old, 0)) {
                *arr = '%';
                ++arr;
            } else {
                *arr = *old;
                ++arr;
            }
        }
        ++old;
    }
    *arr = '\0';
}

bool CheckFuncName(char* inputStr) {
    size_t n = strlen(inputStr);
    for (size_t i = 0; i < n; i++) {
        if (isalpha(inputStr[i])
        && inputStr[i] != 'x'
        && inputStr[i] != 'u'
        && !isFuncName(inputStr, i)
        && !isMod(inputStr, i)) {
            return false;
        } else {
            if (isFuncName(inputStr, i)) {
                while (isalpha(inputStr[i])) {
                    i++;
                }
                if (inputStr[i] != '(') {
                    return false;
                }
            } else if (isMod(inputStr, i)) {
                if (i > 0 && isOperator(inputStr[i-1])) {
                    return false;
                }
                i = i+3;  // смещение на следующий за mod символ
                if (i >= n || inputStr[i] == '\0') {
                    return false;
                }
                if ((isOperator(inputStr[i]) && inputStr[i]!= 'u')
                || inputStr[i] == '('|| inputStr[i] == ')') {
                    return false;
                }
                i--;  // возврат для коректной считывания на след.шаге
            }
        }
    }
    return true;
}

bool CheckOperator(char* inputStr) {
    size_t n = strlen(inputStr);

    if ((isOperator(inputStr[0]) && inputStr[0] != 'u')) {
        return false;
    }

    for (size_t i = 0; i < n; i++) {
        if ((isOperator(inputStr[i]) && inputStr[i] != 'u')
        &&  (isOperator(inputStr[i+1]) && inputStr[i+1] != 'u')) {
            return false;
        }
    }
    return true;
}

// Вход: общая сумма кредита, срок, процентная ставка, тип (аннуитетный, дифференцированный)
double CreditCalc(double totalAmount, double period, double percentageRate, int mode) {
    double res = 0;
    double percent = (percentageRate / 100) / 12;
    if (mode == 1) {
        res = totalAmount * (percent + (percent / (pow((1 + percent), period) - 1)));
    } else if (mode == 2) {
        double debtPart = totalAmount / period;
        percent = totalAmount * percent;
        res = debtPart + percent;
    }
    return res;
}
