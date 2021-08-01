#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i,mx=0,j;
    for(i=0; i<n; i++)
    {
         scanf("%d",&a[i]);
         if(mx<a[i])
            mx=a[i];
    }
    for(i=0;i<mx;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i+a[j])>=mx)
                printf("** ");
            else
                printf("   ");
        }
        printf("\n");
    }
}

