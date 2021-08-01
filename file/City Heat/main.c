#include<stdio.h>

typedef struct{
    char name[21];
    int id;
    double max,min,avg;
} City;

int main()
{
    City c[100];
    FILE *fp;
    int i=0,n,t;
    fp=fopen("cities.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s%d",&c[i].name,&c[i].id);
        i++;
    }
    n=i;
    fclose(fp);
    fp=fopen("max.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&t);
        for(i=0;i<n;i++)
        {
            if(t==c[i].id)
            {
                fscanf(fp,"%lf",&c[i].max);
                break;
            }
        }
    }
    fclose(fp);
    fp=fopen("min.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&t);
        for(i=0;i<n;i++)
        {
            if(t==c[i].id)
            {
                fscanf(fp,"%lf",&c[i].min);
                break;
            }
        }
    }
    fclose(fp);
    fp=fopen("avg.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&t);
        for(i=0;i<n;i++)
        {
            if(t==c[i].id)
            {
                fscanf(fp,"%lf",&c[i].avg);
                break;
            }
        }
    }
    fclose(fp);
    fp=fopen("cityTemps.txt","w");
    for(i=0;i<n-1;i++)
    {
        fprintf(fp,"%s %.2lf %.2lf %.2lf\n",c[i].name,c[i].max,c[i].min,c[i].avg);
    }
    fclose(fp);
}
