#include <stdio.h>
#include <math.h>


void read_coefs(double * a,double * b,double * c);
void quadratic(double a, double b, double discriminant, double * x1, double * x2, int * flag);
void linear(double b, double c, double * x1);
void solve(double a, double b, double c, double * x1, double * x2, int * flag);
void answer(int flag, double x1, double x2);
double solve_discriminant(double a, double b, double c);

int main()
{
    double a = 0.0, b = 0.0, c = 0.0,x1 = 0.0, x2 = 0.0, discriminant = 0.0;
    int flag = 0;
    char ans = 'n';
    printf("Hi! U wanna solve a quadratic equation?(enter \"y\" if u do):");
    while((ans = getchar()) == 'y')
    {
        read_coefs(&a,&b,&c);
        solve(a, b, c, &x1, &x2, &flag);
        answer(flag, x1, x2);
        flag = 0;

        printf("U wanna solve another?\n");
        while(getchar() != '\n');
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

void solve(double a, double b, double c, double * x1, double * x2, int * flag)
{
    double discriminant;
    if(a == 0)
    {
        if(b == 0)
        {
            *flag = 3;
        }
        else
        {
            *flag = 1;
            linear(b, c, x1);
        }
    }
    else
    {
        discriminant = solve_discriminant(a, b, c);
        quadratic(a, b, discriminant, x1, x2, flag);
    }
}

void linear(double b, double c, double * x1)
{
    *(x1) = -(c / b);
}

void quadratic(double a, double b, double discriminant, double * x1, double * x2, int * flag)
{
    if(discriminant > 0)
            {
                *x1 = (-b + sqrt(discriminant)) / (2 * a);
                *x2 = (-b - sqrt(discriminant)) / (2 * a);
            }
            else if(discriminant == 0)
            {
                *flag = 1;
                *x1 = (-b + sqrt(discriminant)) / (2 * a);
            }
            else
            {
                *flag = 2;
            }
}

void answer(int flag, double x1, double x2)
{
    if(flag == 0)
    {
        printf("x1 = %.6lf\n",x1);
        printf("x2 = %.6lf\n",x2);
    }
    else if(flag == 1)
    {
        printf("x = %.6lf\n",x1);
    }
    else if(flag == 2)
    {
        printf("No root.\n");
    }
    else
    {
        printf("The equation with such coefficients is impossible.\n");
    }
}

double solve_discriminant(double a, double b, double c)
{
    double discriminant = 0.0;
    discriminant = (b * b) - (4 * a * c);

    return discriminant;
}
