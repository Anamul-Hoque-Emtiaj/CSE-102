#include<stdio.h>

int check(int n)
{
    int i,s=0;
    for(i=1; i<n; i++)
    {
        if(n%i==0)
        {
            s+=i;
        }
    }
    if(s==n)
        return 1;
    else
        return 0;
}

int main()
{
    int n,s=0,i;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        if(check(i)==1)
        {
            s+=i;
        }
    }
    printf("%d",s);
}

