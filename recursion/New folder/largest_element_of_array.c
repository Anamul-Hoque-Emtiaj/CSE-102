#include<stdio.h>

int mx=0;

int func(int *a,int n)
{
    if(n==1)
        return a[n];

}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("%d",func(a,n));
}

