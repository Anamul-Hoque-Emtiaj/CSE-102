///pointer
#include<stdio.h>

int addition(int *m1,int r1,int c1,int *m2,int r2,int c2)
{
    int i,j;
    if(r1==r2&&c1==c2)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
            {
                *(m1+c1*i+j)+=*(m2+c1*i+j);///for this *
                ///m1[i][j]+=m2[i][j];///for indexing **
            }
        }
        return 1;
    }
    else
        return 0;
}

int subtraction(int *m1,int r1,int c1,int *m2,int r2,int c2)
{
    int i,j;
    if(r1==r2&&c1==c2)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
            {
                *(m1+c1*i+j)-=*(m2+c1*i+j);
            }
        }
        return 1;
    }
    else
        return 0;
}

int multiplication(int *m1,int r1,int c1,int *m2,int r2,int c2,int *m3)
{
    int i,j,k,s;
    if(r2==c1)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            {
                s=0;
                for(k=0; k<r2; k++)
                {
                    s=s+(*(m1+i*r2+k))*(*(m2+k*c2+j));
                }
                (*(m3+i*c2+j))=s;
            }
        }
        return 1;
    }
    else
        return 0;
}

void transpose(int *m,int r,int c,int *p)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            *(p+j*r+i)=*(m+i*c+j);
    }
}

int main()
{
    int r1,r2,c1,c2,i,j,add,sub;
    printf("Matrics 1:\n");
    scanf("%d %d",&r1,&c1);
    int m1[r1][c1];
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            scanf("%d",&m1[i][j]);
    }
    printf("Matrics 2:\n");
    scanf("%d %d",&r2,&c2);
    int m2[r2][c2];
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            scanf("%d",&m2[i][j]);
    }
    printf("Multiplication:\n");
    int m3[r1][c2],mul;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
            m3[i][j]=0;
    }
    mul=multiplication(m1,r1,c1,m2,r2,c2,m3);
    if(mul==1)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
                printf("%d ",m3[i][j]);
            printf("\n");
        }
    }
    else
        printf("Multiplication is not possible\n");
    printf("Addition:\n");
    add=addition(m1,r1,c1,m2,r2,c2);
    if(add==1)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
                printf("%d ",m1[i][j]);
            printf("\n");
        }
    }
    else
        printf("Addition is not possible\n");
    printf("Subtraction:\n");
    sub=subtraction(m1,r1,c1,m2,r2,c2);
    if(sub==1)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
                printf("%d ",m1[i][j]);
            printf("\n");
        }
    }
    else
        printf("Subtraction is not possible\n");
    printf("Transpose\n");
    int m4[c1][r1];
    transpose(m1,r1,c1,m4);
    for(i=0; i<c1; i++)
    {
        for(j=0; j<r1; j++)
            printf("%d ",m4[i][j]);
        printf("\n");
    }
}
