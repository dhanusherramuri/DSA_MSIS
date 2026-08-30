#include <stdio.h>

void push(int stack[], int *top, int n)
{
    int data;

    if (*top < n)
    {
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);

        stack[*top] = data;
        (*top)++;

        printf("Pushed Element: %d\n", data);
        printf("TOP: %d\n", *top);
    }
    else
    {
        printf("STACK FULL\n");
    }
}

void pop(int stack[], int *top)
{
    if (*top == 0)
    {
        printf("EMPTY STACK\n");
    }
    else
    {
        int rem = stack[*top - 1];

        (*top)--;

        printf("POPPED ELEMENT: %d\n", rem);
        printf("TOP: %d\n", *top);
    }
}

void print(int stack[], int top)
{
    if (top == 0)
    {
        printf("EMPTY STACK\n");
        return;
    }

    printf("Stack: ");

    for (int i = 0; i < top; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    int n;

    printf("Enter the size of the Stack: ");
    scanf("%d", &n);

    int stack[n];
    int top = 0;
    int choice;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            push(stack, &top, n);
        }
        else if (choice == 2)
        {
            pop(stack, &top);
        }
        else if (choice == 3)
        {
            print(stack, top);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}