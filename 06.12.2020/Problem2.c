#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * prepend(char * s, char * t, int pos)
{
    int l1=strlen(s),l2=strlen(t),l,i,c=0;
    l=(l1+l2)-pos;
    char *r,*p;
    r=(char*) malloc(sizeof(char)*l);
    if(pos<l1)
    {
        p=s;
        while(pos--)
            p++;
        for(i=0;*(p+i)!='\0';i++)
        {
            *(r+i)=*(p+i);
            c++;
        }
        p=t;
        for(i=0;*(p+i)!='\0';i++)
        {
            *(r+i+c)=*(p+i);
        }
    }
    else
    {
        pos-=l1;
        p=t;
        while(pos--)
            p++;
        for(i=0;*(p+i)!='\0';i++)
        {
            *(r+i)=*(p+i);
        }
    }
    *(r+l)='\0';
    return r;
}

int main()
{
    int pos,i;
    char s[100],t[100],*r;
    gets(s);
    gets(t);
    scanf("%d",&pos);
    r=prepend(s,t,pos);
    for(i=0;*(r+i)!='\0';i++)
        printf("%c",*(r+i));
    free(r);
}
