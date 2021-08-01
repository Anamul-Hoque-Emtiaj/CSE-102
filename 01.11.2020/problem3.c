#include<stdio.h>
#include<string.h>

void deleted(char s[])
{
    int i,l=0,t;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u'||s[l]=='A'||s[l]=='E'||s[l]=='I'||s[l]=='O'||s[l]=='U')
        {
            if(s[i]!='a'||s[i]!='e'||s[i]!='i'||s[i]!='o'||s[i]!='u'||s[i]!='A'||s[i]!='E'||s[i]!='I'||s[i]!='O'||s[i]!='U')
            {
                t=s[l];
                s[l]=s[i];
                s[i]=t;
                l++;
            }
        }
        else
        {
            l++;
        }
    }
    if(s[l]!='a'||s[l]!='e'||s[l]!='i'||s[l]!='o'||s[l]!='u'||s[l]!='A'||s[l]!='E'||s[l]!='I'||s[l]!='O'||s[l]!='U')
    {
        l++;
    }
    for(i=l;s[i]!='\0';i++)
        s[i]='\0';
}

int main()
{
    char s[100];
    gets(s);
    deleted(s);
    puts(s);
}
