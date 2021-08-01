#include<stdio.h>
#include<string.h>

int subsequence(char s1[],char s2[],int l1,int l2)
{
    int result;
    if(l2==0)
        return 1;
    if(l1==0)
        return 0;
    if(s1[l1-1]==s2[l2-1])
        result=subsequence(s1,s2,l1-1,l2-1)+subsequence(s1,s2,l1-1,l2);
    else
        result=subsequence(s1,s2,l1-1,l2);
     return result;
}

int main()
{
    int result;
    char s1[31],s2[31];
    gets(s1);
    gets(s2);
    result=subsequence(s1,s2,strlen(s1),strlen(s2));
    printf("%d\n",result);
}
