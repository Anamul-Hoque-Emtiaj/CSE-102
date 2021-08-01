#include<stdio.h>

long long int fact(int n)
{
    long long int f=1,i;
    for(i=1;i<=n;i++)
        f*=i;
    return f;
}

int main()
{
    long long int n,i,s=0,r;
    scanf("%d",&n);
    for(i=1;i<=n;i+=2)
    {
        r=fact(i);
        s+=r;
    }
    printf("%d",s);
}
