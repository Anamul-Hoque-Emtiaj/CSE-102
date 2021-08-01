#include<stdio.h>

struct complex
{
    double x,y;
};

void print(struct complex X)
{
    if(X.y>0)
        printf("%.2lf+%.2lfi\n",X.x,X.y);
    else
        printf("%.2lf%.2lfi\n",X.x,X.y);
}

struct complex multiply(struct complex X, struct complex Y)
{
    struct complex Z;
    Z.x=X.x*Y.x-X.y*Y.y;
    Z.y=X.x*Y.y+X.y*Y.x;
    return Z;
};

struct complex divide(struct complex X, struct complex Y)
{
    struct complex Z;
    Z.x=(X.x*Y.x+X.y*Y.y)/(Y.x*Y.x+Y.y*Y.y);
    Z.y=(X.y*Y.x-X.x*Y.y)/(Y.x*Y.x+Y.y*Y.y);
    return Z;
};

int main()
{
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    struct complex X={a,b},Y={c,d},M,D;
    M=multiply(X,Y);
    D=divide(X,Y);
    print(M);
    print(D);
}
