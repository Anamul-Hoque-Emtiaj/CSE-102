#include<stdio.h>
#include<math.h>
int main()
{
    double x,y,s=0,f=1;
    int i,j;
    scanf("%lf",&x);
    y=x*(3.1416/180);
    for(i=0;i<30;i++)
    {
        for(j=1;j<=2*i+1;j++)
            f=f*j;
        s=s+((pow(-1,i)*pow(y,2*i+1))/f);
        f=1;
    }
    printf("%.6lf",s);
}

