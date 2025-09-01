#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char opStack[MAX];
int topOp = -1;

void pushOp(char c) {
    if (topOp == MAX - 1) {
        printf("Operator Stack Overflow\n");
        exit(1);
    }
    opStack[++topOp] = c;
}

char popOp() {
    if (topOp == -1) {
        printf("Operator Stack Underflow\n");
        exit(1);
    }
    return opStack[topOp--];
}

char peekOp() {
    if (topOp == -1) return '\0';
    return opStack[topOp];
}

int valStack[MAX];
int topVal = -1;

void pushVal(int val) {
    if (topVal == MAX - 1) {
        printf("Value Stack Overflow\n");
        exit(1);
    }
    valStack[++topVal] = val;
}

int popVal() {
    if (topVal == -1) {
        printf("Value Stack Underflow\n");
        exit(1);
    }
    return valStack[topVal--];
}

int precedence(char op) {
    switch (op) {
        case '/': return 3;
        case '*': return 3;
        case '+': return 2;
        case '-': return 2;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            pushOp(ch);
        }
        else if (ch == ')') {
            while (topOp != -1 && peekOp() != '(') {
                postfix[k++] = popOp();
            }
            popOp(); 
        }
        else { 
            while (topOp != -1 && precedence(peekOp()) >= precedence(ch)) {
                postfix[k++] = popOp();
            }
            pushOp(ch);
        }
    }

    while (topOp != -1) {
        postfix[k++] = popOp();
    }

    postfix[k] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            pushVal(ch - '0'); 
        } else {
            int b = popVal();
            int a = popVal();
            switch (ch) {
                case '+': pushVal(a + b); break;
                case '-': pushVal(a - b); break;
                case '*': pushVal(a * b); break;
                case '/': pushVal(a / b); break;
            }
        }
    }
    return popVal();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <infix_expression>\n", argv[0]);
        return 1;
    }

    char postfix[MAX];
    infixToPostfix(argv[1], postfix);

    int result = evaluatePostfix(postfix);

    printf("Infix Expression: %s\n", argv[1]);
    printf("Postfix Expression: %s\n", postfix);
    printf("Computed Value: %d\n", result);

    return 0;
}
