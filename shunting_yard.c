/*
 * Öðrenci Adý Soyadý: Ömer ERDOÐAN
 * Öðrenci Numarasý: 2010213005
 * Ödev Konusu: Shunting Yard algoritmasý ile infix ifade postfix’e çevirme.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}


int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    return 0;
}

int main() {
    char exp[100]; 
    char *e, x;
    
    printf("Infix ifadeyi giriniz (Orn: a+b*(c^d-e)^(f+g*h)-i): ");
    scanf("%s", exp);
    
    printf("\nPostfix Ifade: ");
    e = exp;

    while (*e != '\0') {
        
        if (isalnum(*e)) {
            printf("%c", *e);
        }
        else if (*e == '(') {
            push(*e);
        }
        else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else {
            
            while (top != -1 && precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    
    while (top != -1) {
        printf("%c", pop());
    }
    
    printf("\n");
    return 0;
}
