#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,c[1000]={0},f=1,*q,count=0;
    char str1[1000],str2[1000],*p1,*p2,*p;
    gets(str1);
    gets(str2);
    p1=str1;
    p2=str2;
    q=c;
    while(*p1!='\0')
    {
        if(*p1==*p2)
        {
            p=p1;
            p++;
            p2++;
            while(*p2!='\0')
            {
               if(*p!=*p2)
               {
                   f=0;
                   break;
               }
               p++;
               p2++;
            }
            if(f==1)
            {
                count++;
                *q=p1-str1;
                q++;
                p2=str2;
                p1+=strlen(str2);
            }
            else
            {
                p2=str2;
                p1++;
                f=1;
            }
        }
        else
            p1++;
    }
    p=str1;
    q=c;
    for(i=0;i<count;i++)
    {
        int l=strlen(str2);
        for(j=(*(q+i))-strlen(str2)*i;*(p+strlen(str2)+j)!='\0';j++)
            *(p+j)=*(p+strlen(str2)+j);
        *(p+j)='\0';
    }
    puts(str1);
}
