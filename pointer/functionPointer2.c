#include<stdio.h>
#include<stdlib.h>

int asd(int a,int b)
{
    int v=a>b? 1: 0;
    return v;
}

int dsd(int a,int b)
{
    int v=a>b? 0: 1;
    return v;
}

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

int main()
{
    int n,i,j,in;
    scanf("%d",&n);
    int *p,(*f[])(int,int)={asd,dsd};
    p=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",p+i);
    printf("For assending Sort Press 0,For Desending Sort Press 1\n");
    scanf("%d",&in);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(f[in](*(p+i),*(p+j))==1)
                swap(p+i,p+j);
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",*(p+i));
    printf("\n");
    free(p);
}
