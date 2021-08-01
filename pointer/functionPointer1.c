#include<stdio.h>

int add(int a,int b)
{
    return a+b;
}

int sub(int a,int b)
{
    return a-b;
}

int mul(int a,int b)
{
    return a*b;
}

int main()
{
    int a,b,i,v;
    int (*p[])(int,int)={add,sub,mul};
    scanf("%d%d",&a,&b);
    while(1)
    {
        printf("For Addition Press 0,For Subtraction Press 1,For Multiplication 2\n");
        printf("%d %d\n",a,b);
        scanf("%d",&i);
        if(i<0||i>2)
            break;
        else
            v=p[i](a,b);
        printf("%d\n",v);
    }
}
