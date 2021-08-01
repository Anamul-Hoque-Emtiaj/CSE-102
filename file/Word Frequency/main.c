#include<stdio.h>
#include<string.h>

typedef struct
{
    char key[21];
    int f;
} Key;

int main()
{
    FILE *fp;
    int i=0,len,n;
    char str[21];
    Key k[100];
    fp=fopen("keywords.txt","r");
    while(1)
    {
        if(feof(fp))
            break;
        fscanf(fp,"%s",&k[i].key);
        k[i].f=0;
        i++;
    }
    n=i;
    fclose(fp);
    fp=fopen("paragraph.txt","r");
    while(1)
    {
        if(feof(fp))
            break;
        fscanf(fp,"%s",str);
        if(str[0]>='A'&&str[0]<='Z')
            str[0]=str[0]-'A'+'a';
        len = strlen(str);
        if (ispunct(str[len - 1]))
            str[len - 1] = '\0';
        for(i=0;i<n;i++)
        {
            if(strcmp(str,k[i].key)==0)
            {
                k[i].f+=1;
                break;
            }
        }
    }
    fclose(fp);
    fp=fopen("freq.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s %d\n",k[i].key,k[i].f);
    }
    fclose(fp);
}
