#include<stdio.h>

double result(int a[],int n)
{
    double r;
    if(n%2==0)
    {
        r=1.00*(a[n/2]+a[(n/2)-1])/2;
    }
    else
    {
        r=a[(n-1)/2];
    }
    return r;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i,j,t,r1;
    double r;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    r=result(a,n);
    printf("%f",r);
}

