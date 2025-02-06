#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}


char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return -1;
}


void displayStack() {
    if (top == -1) {
        printf("Empty");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%c", stack[i]);
        }
    }
}


int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}


void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    printf("\n%-10s%-20s%-20s\n", "Step", "Stack", "Postfix");
    printf("-----------------------------------------------\n");
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isdigit(c) || isalpha(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop the '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        
       
        printf("%-10d", i + 1);
        displayStack();
        printf("%20s\n", postfix);
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter a fully parenthesized infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    
    printf("\nPostfix expression: %s\n", postfix);

    return 0;
}
