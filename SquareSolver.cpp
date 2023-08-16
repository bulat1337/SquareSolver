#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,c,x1,x2,d;
    char ch;
    printf("Hi! U wanna solve a quadratic equation?(enter \"y\" if u do):");
    while((ch = getchar()) == 'y')
    {
        printf("To solve a quadratic equation enter coefficient a:");
        scanf("%lf",&a);
        printf("coefficient b:");
        scanf("%lf",&b);
        printf("and coefficient c:");
        scanf("%lf",&c);
        d = b * b - 4 * a * c;
        if(d > 0)
        {
            x1 = (-b + sqrt(d)) / 2 / a;
            x2 = (-b - sqrt(d)) / 2 / a;
            printf("x1 = %.6lf\nx2 = %.6lf\n",x1,x2);
        }
        else if(d == 0)
        {
            x1 = x1 = (-b + sqrt(d)) / 2 / a;
            printf("x = %.6lf\n",x1);
        }
        else
        {
            printf("no root\n");
        }
        while(getchar() != '\n');
        printf("U wanna solve another?\n");
    }
    printf("Thats it! Bye!");


    return 0;
}
