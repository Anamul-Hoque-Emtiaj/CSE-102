#include<stdio.h>

int result(int n,int m,int p)
{
    int i,r=1;
    for(i=1;i<=m;i++)
    {
        r=(r*(n%p))%p;
    }
    return r;
}

int main()
{
    int n,m,p,r;
    scanf("%d%d%d",&n,&m,&p);
    r=result(n,m,p);
    printf("%d",r);
}
