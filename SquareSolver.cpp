#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

void read_coefs_stdin(double * a,double * b,double * c);
void quadratic(double a, double b, double discriminant, double * x1, double * x2, int * answer_identifier);
void linear(double b, double c, double * x1);
void solve_equation(double a, double b, double c, double * x1, double * x2, int * answer_identifier);
void print_answer(int answer_identifier, double x1, double x2);
double solve_discriminant(double a, double b, double c);
int compare_doubles(double db1, double db2);

int main()
{
    double a = 0.0, b = 0.0, c = 0.0,x1 = 0.0, x2 = 0.0;
    int answer_identifier = 0;
    char ans = 'n';

    printf("Hi! U wanna solve a quadratic equation?(enter \"y\" if u do):");
    while((ans = getchar()) == 'y')
    {
        read_coefs_stdin(&a,&b,&c);
        solve_equation(a, b, c, &x1, &x2, &answer_identifier);
        print_answer(answer_identifier, x1, x2);
        answer_identifier = 0;

        printf("U wanna solve another?\n");
        while(getchar() != '\n');
    }
    printf("Thats it! Bye!");

    return 0;
}

void read_coefs_stdin(double * a,double * b,double * c)
{
    printf("To solve a quadratic equation enter coefficient a:");
    while(scanf("%lf", a) == 0)
    {
        printf("Coefficients must be numbers.\n");
        printf("Try entering coefficient a again:");

        while(getchar() != '\n');
    }

    printf("coefficient b:");
    while(scanf("%lf", b) == 0)
    {
        printf("Coefficients must be numbers.\n");
        printf("Try entering coefficient b again:");

        while(getchar() != '\n');
    }

    printf("and coefficient c:");
    while(scanf("%lf", c) == 0)
    {
        printf("Coefficients must be numbers.\n");
        printf("Try entering coefficient c again:");

        while(getchar() != '\n');
    }
}

void solve_equation(double a, double b, double c, double * x1, double * x2, int * answer_identifier)
{
    *x1 = 0.0;
    *x2 = 0.0;
    if(x1 == NULL)
    {
        printf("&x1 can not be NULL");
        exit(EXIT_FAILURE);
    }

    if(x2 == NULL)
    {
        printf("&x2 can not be NULL");
        exit(EXIT_FAILURE);
    }

    if(answer_identifier == NULL)
    {
        printf("&x1 can not be NULL");
        exit(EXIT_FAILURE);
    }

    double discriminant = 0.0;
    if(compare_doubles(a,0.0) == 0)
    {
        if(compare_doubles(b,0.0) == 0)
        {
            if(compare_doubles(c,0.0) == 0)
            {
                *answer_identifier = 4;
            }
            else
            {
                *answer_identifier = 3;
            }
        }
        else if(compare_doubles(c,0.0) == 0)
        {
            *answer_identifier = 1;
        }
        else
        {
            *answer_identifier = 1;
            linear(b, c, x1);
        }
    }
    else if(compare_doubles(c,0.0) == 0)
    {
        if(b == 0.0)
        {
            *answer_identifier = 1;
        }
        else
        {
            linear(a, b, x1);
        }
    }
    else
    {
        discriminant = solve_discriminant(a, b, c);
        quadratic(a, b, discriminant, x1, x2, answer_identifier);
    }
}

void linear(double b, double c, double * x1)
{
    *(x1) = -(c / b);
}

void quadratic(double a, double b, double discriminant, double * x1, double * x2, int * answer_identifier)
{
    if(compare_doubles(discriminant,0.0) == 1)
    {
        *x1 = (-b + sqrt(discriminant)) / (2 * a);
        *x2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    else if(compare_doubles(discriminant,0.0) == 0)
    {
        *answer_identifier = 1;
        *x1 = (-b + sqrt(discriminant)) / (2 * a);
    }
    else
    {
        *answer_identifier = 2;
    }
}

void print_answer(int answer_identifier, double x1, double x2)
{
    if(answer_identifier == 0)
    {
        printf("x1 = %.6lf\n",x1);
        printf("x2 = %.6lf\n",x2);
    }
    else if(answer_identifier == 1)
    {
        printf("x = %.6lf\n",x1);
    }
    else if(answer_identifier == 2)
    {
        printf("No root.\n");
    }
    else if(answer_identifier == 3)
    {
        printf("The equation with such coefficients is impossible.\n");
    }
    else
    {
        printf("The equation is always true\n");
    }
}

double solve_discriminant(double a, double b, double c)
{
    double s_discriminant = 0.0;

    s_discriminant = (b * b) - (4 * a * c);

    return s_discriminant;
}

int compare_doubles(double db1, double db2)
{
    double eps = 1e-7;
    if (!(fabs(db1 - db2) > eps))
    {
        return 0;
    }
    else if ((db1 - db2) > eps)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
