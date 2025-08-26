#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_TOKEN_SIZE 100

double stack[MAX_STACK_SIZE];
int top = -1;

void push(double value) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Error: Stack overflow\n");
        exit(1);
    }
}

double pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Error: Stack underflow\n");
        exit(1);
    }
}

int is_operator(const char *token) {
    return strlen(token) == 1 && strchr("+-*/", token[0]) != NULL;
}

int main() {
    char token[MAX_TOKEN_SIZE];

    printf("Enter values ending with '=' to evaluate\n");

    while (scanf("%s", token) == 1) {
        if (strcmp(token, "=") == 0) {
            break;
        }

        double num;
        if (sscanf(token, "%lf", &num) == 1) {
            push(num);
        } else if (is_operator(token)) {
            if (top < 1) {
                printf("Error: Not enough operands for '%s'\n", token);
                exit(1);
            }

            double b = pop();
            double a = pop();
            double result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    result = a / b; break;
                default:
                    printf("Error: Unknown operator '%s'\n", token);
                    exit(1);
            }

            push(result);
        } else {
            printf("Error: Invalid token '%s'\n", token);
            exit(1);
        }
    }

    if (top != 0) {
        printf("Error: Too many operands or not enough operators\n");
        exit(1);
    }

    printf("Result: %.2lf\n", pop());
    return 0;
}
