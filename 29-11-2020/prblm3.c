#include<stdio.h>
#include<stdlib.h>

char *mystrstr( char *str1, char *str2)
{
    char *v=NULL,*t,*s;
    s=str2;
    int f=1;
    while(*str1!='\0')
    {
        if(*str1==*str2)
        {
            t=str1;
            t++;
            str2++;
            while(*str2!='\0')
            {
                if(*str2!=*t)
                {
                    f=0;
                    break;
                }
                t++;
                str2++;
            }
            if(f==0)
            {
               f=1;
               str2=s;
               str1++;
            }
            else
            {
                v=str1;
                break;
            }
        }
        else
            str1++;
    }
    return v;
}

int main()
{
    char str1[100],str2[100];
    gets(str1);
    gets(str2);
    char *v=mystrstr(str1,str2);
    if(v==NULL)
        printf("NULL\n");
    else
    {
        while(*v!='\0')
        {
            printf("%c",*v);
            v++;
        }
    }
}
