#include<stdio.h>
#include<stdlib.h>

void createOddNumber(int *p,int n)
{
    int i=1;
    while(n--)
    {
        *p=i;
        p++;
        i+=2;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int *p,*a;
    p= (int*) malloc(sizeof(int)*n);
    createOddNumber(p,n);
    a=p;
    while(n--)
    {
        printf("%d ",*a);
        a++;
    }
    printf("\n");
    free(p);
}
