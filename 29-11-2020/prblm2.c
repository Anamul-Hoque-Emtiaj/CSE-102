#include<stdio.h>
#include<stdlib.h>

void findNumber(int **p,int r,int c,int k)
{
    int f=-1,i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(*(*(p+i)+j)==k)
            {
                f=1;
                printf("%d %d\n",i+1,j+1);
            }
        }
    }
    if(f==-1)
        printf("-1\n");
}

int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int **row,i,t,j,d;
    row=(int**) malloc(sizeof(int*)*r);
    for(i=0;i<r;i++)
    {
        *(row+i)=(int*)malloc(sizeof(int)*c);
        for(j=0;j<c;j++)
        {
            scanf("%d",(*(row+i)+j));
        }
    }
    scanf("%d",&d);
    findNumber(row,r,c,d);
    for(i=0;i<r;i++)
    {
        free(*(row+i));
    }
    free(row);
}
