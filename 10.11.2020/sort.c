#include<stdio.h>

int factor(int n)
{
    int i,c=0;
    for(i=1; i<=n; i++)
    {
        if(n%i==0)
            c++;
    }
    return c;
}

int binary_reptn(int n)
{
    int s=0;
    while(n!=0)
    {
        s+=n%2;
        n/=2;
    }
    return s;
}

int main()
{
    int n,t;
    scanf("%d",&n);
    int a[n],i,j;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(binary_reptn(a[i])>binary_reptn(a[j]))
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
            else if(binary_reptn(a[i])==binary_reptn(a[j]))
            {
                if(factor(a[i])<factor(a[j]))
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
                else if((factor(a[i])==factor(a[j]))&&a[i]>a[j])
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
    }
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
}

