#include<stdio.h>

int main()
{
    int r1,r2,c1,c2,i,j,k,s=0;
    scanf("%d %d",&r1,&c1);
    int a[r1][c1];
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
            scanf("%d",&a[i][j]);
    }
    scanf("%d %d",&r2,&c2);
    int b[r2][c2],c[r1][c2];
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
            scanf("%d",&b[i][j]);
    }
    if(r2==c1)
    {
        printf("%d %d\n",r1,c2);
       for(i=0;i<r1;i++)
       {
           for(j=0;j<c2;j++)
           {
               for(k=0;k<r2;k++)
               {
                   s+=a[i][k]*b[k][j];
               }
               c[i][j]=s;
               s=0;
           }
       }
       for(i=0;i<r1;i++)
       {
           for(j=0;j<c2;j++)
            printf("%d ",c[i][j]);
            printf("\n");
       }
    }
    else
        printf("Multiplication not possible");
}
