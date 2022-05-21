#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

enum operatorPrior {
    LOW,
    MID,
    HIGH,
    ULTRA
};

typedef struct stack_Char {
    char data[256];
    size_t size;
} stack_char;

typedef struct stack_Double {
    double data[256];
    size_t size;
} stack_double;

void push(stack_char *stack, char value);
char pop(stack_char *stack);
char peek(stack_char *stack);

void push_double(stack_double *stack, double value);
double pop_double(stack_double *stack);
double peek_double(stack_double *stack);

void printStack(stack_char *stack);
void reverseStr(char* str);
bool isOperator(char ch);
int checkPriority(char ch1);
void addToArr(char* outputStr, int* outputCount, char ch);
stack_char ParseToPolishNotation(char* buff);
double Calculate(stack_char inputStack, double x);
void ReplaceUnarySign(char* inputStr);
bool DotCheck(char* src);
void RemoveSpace(char* src);
bool isFuncName(char* src, int i);
char* AddMultBetweenBracketAndZeroAfterDot(char* src);
bool checkBracket(char* src);
double GetResult(char *buff, double x);
bool IsNormalInputString(char *buff);
void ReplaseModAndFunc(char* buff);
bool CheckFuncName(char* inputStr);
bool CheckOperator(char* inputStr);
bool IsleftAssociativeOperator(char ch);
char* tryRealloc(char* pointer, int j);

double CreditCalc(double totalAmount, double period, double percentageRate, int mode);

#endif  //  SRC_S21_SMARTCALC_H_
