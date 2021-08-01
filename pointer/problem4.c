///array of pointer 1d dynamic memory allocation
#include<stdio.h>
#include<stdlib.h>

void takeInput(int *p,int c)
{
    int i;
    for(i=0; i<c; i++)
        scanf("%d",p+i);
}

void printOutput(int *p,int c)
{
    int i;
    for(i=0; i<c; i++)
        printf("%d ",*(p+i));
    printf("\n");
}

void addition(int *p1,int *p2,int c)
{
    int i;
    for(i=0; i<c; i++)
        *(p1+i)+=*(p2+i);
}

void subtraction(int **p1,int **p2,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            *(*(p1+i)+j)-=*(*(p2+i)+j);
    }
}

int main()
{
    int r1,c1,r2,c2;
    printf("Matrix 1\n");
    scanf("%d %d",&r1,&c1);
    int *p1[r1],i;
    for(i=0; i<r1; i++)
    {
        p1[i]=(int*)malloc(sizeof(int)*c1);
        takeInput(p1[i],c1);
    }

    printf("Matrix 2\n");
    scanf("%d %d",&r2,&c2);
    int *p2[r2];
    for(i=0; i<r2; i++)
    {
        p2[i]=(int*)malloc(sizeof(int)*c2);
        takeInput(p2[i],c2);
    }

    printf("Print Matrix 1\n");
    for(i=0; i<r1; i++)
    {
        printOutput(p1[i],c1);
    }

    printf("Print Matrix 2\n");
    for(i=0; i<r2; i++)
    {
        printOutput(p2[i],c2);
    }

    printf("Addition\n");
    if(r1==r2&&c1==c2)
    {
        for(i=0; i<r1; i++)
            addition(p1[i],p2[i],c1);
        for(i=0; i<r1; i++)
        {
            printOutput(p1[i],c1);
        }
    }
    else
        printf("Addition is not possible\n");

    printf("Subtraction\n");///2d pointer
    if(r1==r2&&c1==c2)
    {
        subtraction(p1,p2,r1,c1);
        for(i=0; i<r1; i++)
        {
            printOutput(p1[i],c1);
        }
    }
    else
        printf("Subtraction is not possible\n");
    for(i=0;i<r1;i++)
        free(p1[i]);
    for(i=0;i<r2;i++)
        free(p2[i]);
}
