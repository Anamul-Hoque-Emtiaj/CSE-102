#include<stdio.h>

int main()
{
    int w,h,i,j,c=0,k=0;
    scanf("%d %d",&h,&w);
    while(k<2)
    {
        for(i=1; i<=w; i++)
        {
            printf("* ");
        }
        printf("\n");
        k++;
    }
    for(i=3; i<=h; i+=2)
    {
        c++;
        k=0;
        while(k<2)
        {
            for(j=1; j<=(c+1)*w; j++)
            {
                printf("* ");
            }
            printf("\n");
            k++;
        }

    }
    for(i=h-2; i>=1; i-=2)
    {
        c--;
        k=0;
        while(k<2)
        {
            for(j=1; j<=(c+1)*w; j++)
            {
                printf("* ");
            }
            printf("\n");
            k++;
        }

    }

}

