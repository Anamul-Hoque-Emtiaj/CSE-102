#include<stdio.h>

int func(int a,int b)
{
    if(a%b==0)
        return b;
    int v = func(b,a%b);
    return v;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",func(max(a,b),min(a,b)));
}

