#include<stdio.h>

int func(long long int n)
{
    if(n<10)
        return n;
    int v = n%10 + func(n/10);
    return v;
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    printf("%d",func(n));
}

