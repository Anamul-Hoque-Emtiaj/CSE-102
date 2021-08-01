#include<stdio.h>

int stringLength(char *s)
{
    char *p;
    p=s;
    while(*p!='\0')
        p++;
    return p-s;
}

void stringConcat(char *s1,char *s2)
{
    char *p1,*p2;
    p1=s1;
    p2=s2;
    while(*p1!='\0')
        p1++;
    while(*p2!='\0')
    {
        *p1=*p2;
        p1++;
        p2++;
    }
    *p1='\0';
}

void stringCopy(char *s1,char *s2)
{
    char *p1,*p2;
    p1=s1;
    p2=s2;
    while(*p2!='\0')
    {
        *p1=*p2;
        p1++;
        p2++;
    }
    *p1='\0';
}

void stringNCopy(char *s1,char *s2,int n)
{
    char *p1,*p2;
    p1=s1;
    p2=s2;
    while(n--)
    {
        *p1=*p2;
        p1++;
        p2++;
    }
    *p1='\0';
}

int stringCompare(char *s1,char *s2)
{
    char *p1,*p2;
    int f=1;
    p1=s1;
    p2=s2;
    while(*p1!='0' && *p2!='\0')
    {
        if(*p1!=*p2)
        {
            f=0;
            break;
        }
        p1++;
        p2++;
    }
    if(f==0)
        return 0;
    else
    {
        if(*p1=='\0'&&*p2=='\0')
            return 1;
        else
            return 0;
    }
}

int stringNCompare(char *s1,char *s2,int n)
{
    int f=1;
    char *p1,*p2;
    p1=s1;
    p2=s2;
    while(n--)
    {
       if(*p1!=*p2)
        {
            f=0;
            break;
        }
        p1++;
        p2++;
    }
    if(f==0)
        return 0;
    else
        return 1;
}

void stringReverse(char *s)
{
    char *p1,*p2,t;
    p1=s;
    p2=s;
    while(*p1!='\0')
        p1++;
    int n;
    n=(p1-p2)/2;
    p1--;
    while(n--)
    {
       t=*p1;
       *p1=*p2;
       *p2=t;
       p1--;
       p2++;
    }
}

void stringLower(char *s)
{
    char *p;
    p=s;
    while(*p!='\0')
    {
        if(*p>='A'&&*p<='Z')
            *p='a'+*p-'A';
        p++;
    }
}

void stringUpper(char *s)
{
    char *p;
    p=s;
    while(*p!='\0')
    {
        if(*p>='a'&&*p<='z')
            *p='A'+*p-'a';
        p++;
    }
}

int main()
{
    char s1[100],s2[100],s3[100];
    gets(s1);
    gets(s2);
    printf("stringLength %d\n",stringLength(s1));
    stringConcat(s1,s2);
    puts(s1);
    stringCopy(s3,s1);
    puts(s3);
    printf("stringCompare %d\n",stringCompare(s3,s1));
    stringNCopy(s3,s1,4);
    puts(s3);
    printf("stringCompare %d\n",stringCompare(s3,s1));
    printf("stringNCompare %d\n",stringNCompare(s3,s1,4));
    stringLower(s1);
    puts(s1);
    stringUpper(s1);
    puts(s1);
    stringReverse(s1);
    puts(s1);
}
