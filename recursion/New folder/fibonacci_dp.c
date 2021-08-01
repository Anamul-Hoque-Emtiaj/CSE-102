#include<stdio.h>

long long int fib(long long int a,long long int b,int in,int n)
{
    if(n<2)
        return n;
    if(in==n+1)
        return b;
    int v=fib(b,a+b,in+1,n);
    return v;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld",fib(0,1,2,n));
}
