#include<stdio.h>

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
    if(n%2==0)
    {
        r=1.00*(a[n/2]+a[(n/2)-1])/2;
        printf("%f",r);
    }
    else
    {
        r1=a[(n-1)/2];
        printf("%d",r1);
    }

}
