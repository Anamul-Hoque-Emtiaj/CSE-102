#include<stdio.h>
#include<stdlib.h>

void takeInput(int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",p+i);
}

void printOutput(int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",*(p+i));
    printf("\n");
}

void sort(int *p,int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(p+i)>*(p+j))
            {
                t=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=t;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int *p;
    p=(int *) malloc(sizeof(int)*n);
    takeInput(p,n);
    printf("Before sort\n");
    printOutput(p,n);
    sort(p,n);
    printf("After sort\n");
    printOutput(p,n);
    free(p);
}
