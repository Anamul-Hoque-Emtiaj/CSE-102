#include<stdio.h>
#include<stdlib.h>

int stringLength(char *s)
{
    char *p;
    p=s;
    while(*p!='\0')
        p++;
    return p-s;
}

void fillOutput(char *p1,char *p2)
{
    char *p;
    p=p2;
    while(*p1!='\0')
    {
        *p = *p1;
        p++;
        p1++;
    }
    *p='\0';
}

int compare(char *s1,char *s2)
{
    int f=0;
    char *p1,*p2;
    p1=s1;
    p2=s2;
    while(*p1!='\0'&&*p2!='\0')
    {
        if(*p1>*p2)
        {
            return 1;
        }
        else if(*p1<*p2)
        {
            return 0;
        }
        p1++;
        p2++;
    }
    if(*p1!='\0')
    {
        return 1;
    }
    else
        return 0;
}

void sort(char **str,int n)
{
    int i,j;
    char *t;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(compare(*(str+i),*(str+j))==1)
            {
                t=*(str+i);
                *(str+i)=*(str+j);
                *(str+j)=t;
            }
        }
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    char **str,a[25];
    str=(char **) malloc(sizeof(char *)*n);
    for(i=0; i<n; i++)
    {
        scanf("%s",a);
        int l=stringLength(a);
        *(str+i)= (char *) malloc(sizeof(char)*l);
        fillOutput(a,*(str+i));
    }
    printf("Before sort\n");
    for(i=0; i<n; i++)
        puts(*(str+i));
    sort(str,n);
    printf("After sort\n");
    for(i=0; i<n; i++)
        puts(*(str+i));
    for(i=0; i<n; i++)
        free(*(str+i));
    free(str);
}
