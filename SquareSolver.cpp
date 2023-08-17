#include <stdio.h>
#include <math.h>

void read_coefs(double * a, double * b, double * c);
double solve_discriminant(double a, double b, double c);
void linear(double * b, double * c);
void quadratic(double * a, double * b, double * discriminant);

int main()
{
    double a = 0.0, b = 0.0, c = 0.0, discriminant = 0.0;
    char answer = 'n';

    printf("Hi! U wanna solve a quadratic equation?(enter \"y\" if u do):");

    while((answer = getchar()) == 'y')
    {
        read_coefs(&a, &b, &c);

        if(a == 0)
        {
            linear(&b, &c);
        }
        else
        {
            discriminant = solve_discriminant(a, b, c);
            quadratic(&a, &b, &discriminant);
        }

        while(getchar() != '\n');

        printf("U wanna solve another?\n");
    }
    printf("Thats it! Bye!");

    return 0;
}

void read_coefs(double * a,double * b,double * c)
{
    printf("To solve a quadratic equation enter coefficient a:");
        scanf("%lf", a);
        printf("coefficient b:");
        scanf("%lf", b);
        printf("and coefficient c:");
        scanf("%lf", c);
}

double solve_discriminant(double a, double b,double c)
{
    double discriminant = 0.0;
    discriminant = (b * b) - (4 * a * c);

    return discriminant;
}

void linear(double * b, double * c)
{
    double x = 0.0;
    if(*b == 0)
    {
        printf("The equation with such coefs is impossible!\n");
    }
    else
    {
        x = -(*c / *b);
        printf("x = %.6lf\n", x);
    }
}

void quadratic(double * a, double * b, double * discriminant)
{
    double x1 = 0.0, x2 = 0.0;
    if((*discriminant) > 0)
            {
                x1 = (-(*b) + sqrt((*discriminant))) / (2 * (*a));
                x2 = (-(*b) - sqrt((*discriminant))) / (2 * (*a));
                printf("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
            }
            else if((*discriminant) == 0)
            {
                x1 = (-(*b) + sqrt((*discriminant))) / (2 * (*a));
                printf("x = %.6lf\n", x1);
            }
            else
            {
                printf("no root\n");
            }
}
