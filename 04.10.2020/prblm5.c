#include<stdio.h>

int n,b[10000],c1=0;

void countx(int x)
{
    c1++;
    int c=0,m;
    m=n;
    while(m%x==0)
    {
        c++;
        m=m/x;
    }
    b[x]=c;
    if(c1>1) printf(" X ");
    printf("%d^%d",x,c);
}

void primediv(int x)
{
    int f=1,i;
    if(x<2) f=0;
    else if(x==2) f=1;
    else if(x%2==0) f=0;
    else
    {
        for(i=3; i*i<=x; i+=2)
            if(x%i==0)
            {
                f=0;
                break;
            }
    }
    if(f==1)
        countx(x);
}

void div()
{
    int i;
    for(i=2; i<=n; i++)
        if(n%i==0)
            primediv(i);
}

int main()
{
    int in,i=0;
    scanf("%d",&n);
    div();
    printf("\n");
    while(1)
    {
        scanf("%d",&in);
        if(in==-1)
            break;
        else
        {
            printf("%d\n",b[in]);
        }
    }

}
