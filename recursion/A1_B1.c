#include<stdio.h>

int check(int *a,int in,int n,int *f)
{
    int v;
    if(in==n-1)
        return 1;
    if(f[in]==1)
        return 0;
    if(a[in]==0)
        return 0;
    f[in]=1;
    if(a[in]<=in&&a[in]+in>=n)
        v=check(a,in-a[in],n,f);
    else if(a[in]>in&&a[in]+in<n)
         v=check(a,in+a[in],n,f);
    else if(a[in]<=in&&a[in]+in<n)
        v=check(a,in+a[in],n,f)+check(a,in-a[in],n,f);
    return v;
}

int main()
{
    int n,v;
    scanf("%d",&n);
    int a[n],i,f[n];
    for(i=0;i<n;i++)
        f[i]=0;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    v=check(a,0,n,f);
   /// printf("%d\n",v);
    if(v==1)
        printf("Yes\n");
    else
        printf("No\n");
}
