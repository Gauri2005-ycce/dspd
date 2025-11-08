#include <stdio.h>
#include <string.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else {
        stack[++top] = val;
        printf("%d pushed.\n", val);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("%d popped.\n", stack[top--]);
}

void display() {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements: ");
        int i;
        for ( i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void checkPalindrome() {
    char str[50], temp[50];
    int i, len, topTemp = -1, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    for (i = 0; i < len; i++)
        temp[++topTemp] = str[i];
    for (i = 0; i < len; i++)
        if (str[i] != temp[topTemp--]) { flag = 0; break; }

    if (flag) printf("Palindrome!\n");
    else printf("Not Palindrome!\n");
}

int main() {
    int ch, val;
    do {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Check Palindrome\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: checkPalindrome(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 5);

    return 0;
}

