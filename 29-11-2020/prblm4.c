#include<stdio.h>
#include<math.h>

typedef struct{
    double x,y;
} str;

str midPoint(str a,str b)
{
    str m;
    m.x=(a.x+b.x)/2;
    m.y=(a.y+b.y)/2;
    return m;
}

str forthPoint(str a,str b)
{
    str c;
    c.x=2*a.x-b.x;
    c.y=2*a.y-b.y;
    return c;
}

double distance(str a,str b)
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

double Area(str a,str b,str c)
{
    double l1,l2,l3,s;
    l1=distance(a,b);
    l2=distance(b,c);
    l3=distance(c,a);
    s=(l1+l2+l3)/2;
    return sqrt(s*(s-l1)*(s-l2)*(s-l3));
}

int main()
{
    str a,b,c,d,o;
    scanf("%lf%lf",&d.x,&d.y);
    scanf("%lf%lf",&a.x,&a.y);
    scanf("%lf%lf",&b.x,&b.y);
    o=midPoint(d,b);
    c=forthPoint(o,a);
    double area;
    area=2*Area(a,b,c);
    printf("Forth Point : X=%f,Y=%f\nArea :%f\n",c.x,c.y,area);
}
