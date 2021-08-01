#include<stdio.h>

int det(int n,int A[n][n])
{
    int Minor[n-1][n-1];
    int i,j,k,c1,c2;

    int determinant=0;
    int O=1;
    if(n==1)
        return A[0][0];
    for(i = 0 ; i < n ; i++)
    {
        c1 = 0, c2 = 0;
        for(j = 0 ; j < n ; j++)
        {
            for(k = 0 ; k < n ; k++)
            {
                if(j != 0 && k != i)
                {
                    Minor[c1][c2] = A[j][k];
                    c2++;
                    if(c2==n-1)
                    {
                        c1++;
                        c2=0;
                    }
                }
            }
        }
        determinant = determinant + O*(A[0][i]*det(n-1,Minor));
        O=-1*O;
    }
    return determinant;
}

int main()
{
    int n,i,j;
    scanf("%d ",&n);
    int a[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    }
    int v=det(n,a);
    printf("%d",v);
}
