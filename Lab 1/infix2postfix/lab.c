#include <stdio.h>

int top1 = -1, top2 = -1, top3 = -1;
char infix[20], postfix[20], stack[20];

void push(char a, char b[], int c) {
    if (c == 1) {
        b[++top1] = a;
    } else if (c == 2) {
        b[++top2] = a;
    }
}

char pop(char b[]) {
    if (top2 == -1) {
        printf("Underflow\n");
        return '\0';
    } else {
        return b[top2--];
    }
}

void main() {
    printf("Enter infix expression: ");
    gets(infix);

    for (top3 = 0; infix[top3] != '\0'; top3++) {
        char a = infix[top3];

        if (a != '(' && a != ')' && a != '+' && a != '-' && a != '*' && a != '/') {
            push(a, postfix, 1);
        }
        else if (a == '(') {
            push(a, stack, 2);
        }
        else if (a == ')') {
            while (stack[top2] != '(') {
                char b = pop(stack);
                push(b, postfix, 1);
            }
            pop(stack); 
        }
        else if (a == '*' || a == '/') {
            if (stack[top2] == '*' || stack[top2] == '/') {
                char b = pop(stack);
                push(b, postfix, 1);
            }
            push(a, stack, 2);
        }
        else if (a == '+' || a == '-') {
            while (top2 != -1 && (stack[top2] == '*' || stack[top2] == '/' ||
                                  stack[top2] == '+' || stack[top2] == '-')) {
                char b = pop(stack);
                push(b, postfix, 1);
            }
            push(a, stack, 2);
        }
    }
    while (top2 != -1) {
        char b = pop(stack);
        push(b, postfix, 1);
    }

    postfix[++top1] = '\0';
    printf("Postfix: ");
    puts(postfix);
}
