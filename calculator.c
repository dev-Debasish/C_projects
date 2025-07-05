#include <stdio.h>
#include <math.h>

void print_menu();
double division(double, double);
double modulus(int, int);

void print_menu()
{
    printf("\n\n---------------------------------\n");
    printf("\nWelcome to the Simple Calculator\n");
    printf("\nChoose one of the following options:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");
}

double division(double a, double b)
{
    if (b == 0)
    {
        fprintf(stderr, "Invalid argument for division");
        return NAN;
    }
    else
    {
        return a / b;
    }
}

double modulus(int a, int b)
{
    if (b == 0)
    {
        fprintf(stderr, "Invalid argument for modulus");
        return NAN;
    }
    else
    {
        return a % b;
    }
}

int main()
{
    int choice;
    double num1, num2, result;
    while (1)
    {
        print_menu();

        printf("Now, Enter your choice:");
        scanf("%d", &choice);

        if (choice == 7)
        {
            break;
        }
        if (choice < 1 || choice > 7)
        {
            fprintf(stderr, "Invalid menu choice");
            continue;
        }

        printf("Enter the First number:");
        scanf("%lf", &num1);
        printf("Enter the Second number:");
        scanf("%lf", &num2);

        switch (choice)
        {
        case 1: //* Add
            result = num1 + num2;
            break;
        case 2: //* Subtract
            result = num1 - num2;
            break;
        case 3: //* Multiply
            result = num1 * num2;
            break;
        case 4: //* Divide
            result = division(num1, num2);
            break;
        case 5: //* Modulus
            result = modulus(num1, num2);
            break;
        case 6: //* Power
            result = pow(num1, num2);
            break;
        }

        if (!isnan(result))
        {
            printf("Result is = %.2f", result);
        }
    }
    return 0;
}