///2d pointer & 2d dynamic memory allocation
#include<stdio.h>
#include<stdlib.h>

void takeInput(int **p,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",*(p+i)+j);
    }
}

void printOutput(int **p,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",*(*(p+i)+j));
        printf("\n");
    }
}

void addition(int **p1,int **p2,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            *(*(p1+i)+j)+=*(*(p2+i)+j);
    }
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

void multiplication(int **p1,int **p2,int r1,int c2,int r2,int **p3)
{
    int i,j,k,s=0;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(k=0;k<r2;k++)
                s+=(*(*(p1+i)+k)) * (*(*(p2+k)+j));
            (*(*(p3+i)+j))=s;
            s=0;
        }
    }

}

int main()
{
    int r1,c1,r2,c2,i,j;
    printf("Matrix 1\n");
    scanf("%d%d",&r1,&c1);
    int **row1;
    row1=(int **)malloc(sizeof(int*)*r1);
    for(i=0;i<r1;i++)
    {
        row1[i]=(int*)malloc(sizeof(int)*c1);
    }
    takeInput(row1,r1,c1);

    printf("Matrix 2\n");
    scanf("%d%d",&r2,&c2);
    int **row2;
    row2=(int **)malloc(sizeof(int*)*r2);
    for(i=0;i<r2;i++)
    {
        row2[i]=(int*)malloc(sizeof(int)*c2);
    }
    takeInput(row2,r2,c2);

    printf("Print Matrix 1\n");
    printOutput(row1,r1,c1);
    printf("Print Matrix 2\n");
    printOutput(row2,r2,c2);

    printf("Addition\n");
    if(r1==r2&&c1==c2)
    {
        addition(row1,row2,r1,c1);
        printOutput(row1,r1,c1);
    }
    else
        printf("Addition is not possible\n");

    printf("Subtraction\n");
    if(r1==r2&&c1==c2)
    {
        subtraction(row1,row2,r1,c1);
        printOutput(row1,r1,c1);
    }
    else
        printf("Subtraction is not possible\n");

    printf("Multiplication\n");
    int **row3;
    row3=(int **)malloc(sizeof(int*)*r1);
    for(i=0;i<r1;i++)
    {
        row3[i]=(int*)malloc(sizeof(int)*c2);
    }
    if(r2==c1)
    {
        multiplication(row1,row2,r1,c2,r2,row3);
        printOutput(row3,r1,c2);
    }
    else
        printf("Multiplication is not possible\n");


    for(i=0;i<r1;i++)
        free(row1[i]);
    free(row1);
    for(i=0;i<r2;i++)
        free(row2[i]);
    free(row2);
    for(i=0;i<r1;i++)
        free(row3[i]);
    free(row3);
}
