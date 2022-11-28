#include <stdio.h>

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double div(double a, double b) { return a / b; }

int main(void)
{
    double (*ptr2func[4])(double, double) = {add, sub, mul, div};
    int choice;
    double a, b;

    printf("1. Addition\n2. Subtraction\n");
    printf("3. Multiplication\n4. Division\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    printf("\nEnter 2 numbers : ");
    scanf("%lf %lf", &a, &b);
    printf("Result = %g\n", ptr2func[choice-1](a, b));
    return 0;
}
