#include<stdio.h>

int main()
{
    long double a,b;
    (void)scanf("%Lf", &a);
    (void)scanf("%Lf", &b);
    (void)printf("%Lf",(long double)(a+b));
    return 0;
}
