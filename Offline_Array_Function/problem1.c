#include<stdio.h>

int c1=0,a[1000000],c[1000000],s=0;
///globally declare 2 array one for storing number & another for their count

void mfn(int n)
{
    int i,f=0,in,maxi=-10000,c2=0;
    c1++;
    if(c1==1)///in case of 1st number
    {
        a[s]=n;
        c[s]++;
        s++;
    }
    else
    {
        for(i=0;i<s;i++)
        {
            if(a[i]==n)///check, is the number already in the array
            {
                f=1;
                in=i;
                break;
            }
        }
        if(f==1) ///if the number already in the array
        {
            c[in]++;
        }
        else
        {
            a[s]=n;
            c[s]++;
            s++;
        }
    }
    for(i=0;i<s;i++) ///finding max from the count array
    {
        if(c[i]>maxi)
            maxi=c[i];
    }
    for(i=0;i<s;i++) ///print those number whose count is equal to max count
    {
        if(c[i]==maxi)
        {
            if(c2++==0)
                printf("Most frequent number =%d",a[i]);
            else
                printf(", %d",a[i]);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        mfn(m);
    }
}
