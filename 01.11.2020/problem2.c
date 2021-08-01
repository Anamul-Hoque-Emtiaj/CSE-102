#include<stdio.h>

void rotate(int n,int a[][n])
{
    int i,j,t,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>j)
            {
                t=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0,k=n-1;j<n/2;j++,k--)
        {
             t=a[i][j];
             a[i][j]=a[i][k];
             a[i][k]=t;
        }
    }
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    rotate(n,a);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
