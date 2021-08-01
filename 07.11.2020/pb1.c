#include<stdio.h>
#include<string.h>
#include<math.h>

void inputModification(char input[])
{
    char modifyInput[10];
    int in=0,i;
    strlwr(input);
    for(i=0; input[i]!='\0'; i++)
    {
        if(input[i]!=' ')
            modifyInput[in++]=input[i];
    }
    for(i=0; input[i]!='\0'; i++)
        input[i]='\0';
    for(i=0; modifyInput[i]!='\0'; i++)
        input[i]=modifyInput[i];
}

void print(int r,int c,int mata[r][c],int f)
{
    int i,j;
    if(r!=0&&c!=0)
    {
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
                printf("%d ",mata[i][j]);
            printf("\n");
        }
    }
    else
    {
        if(f==1)
            printf("No A matrix found\n");
        else
            printf("No B matrix found\n");
    }
}

void addition(int r1,int c1,int matA[r1][c1],int r2,int c2,int matB[r2][c2])
{
    int i,j;
    if(r1==0)
        printf("No A matrix found\n");
    else if(r2==0)
        printf("No B matrix found\n");
    else if(r1==r2&&c1==c2)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
                printf("%d ",matA[i][j]+matB[i][j]);
            printf("\n");
        }
    }
    else
        printf("Addition not possible\n");
}

void subtraction(int r1,int c1,int matA[r1][c1],int r2,int c2,int matB[r2][c2],int f)
{
    int i,j;
    if((r1==0&&f==1)||(r2==0&&f==2))
        printf("No A matrix found\n");
    else if((r2==0&&f==1)||(r1==0&&f==2))
        printf("No B matrix found\n");
    else if(r1==r2&&c1==c2)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
            {
                printf("%d ",matA[i][j]-matB[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Subtraction not possible\n");
}

void  multiplication(int r1,int c1,int matA[r1][c1],int r2,int c2,int matB[r2][c2],int f)
{
    int i,j,k,s=0;
    if((r1==0&&f==1)||(r2==0&&f==2))
        printf("No A matrix found\n");
    else if((r2==0&&f==1)||(r1==0&&f==2))
        printf("No B matrix found\n");
    else if(r2==c1)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            {
                for(k=0; k<r2; k++)
                {
                    s+=matA[i][k]*matB[k][j];
                }
                printf("%d ",s);
                s=0;
            }
            printf("\n");
        }
    }
    else
        printf("Multiplication not possible\n");
}

void divide(int r,int c,int mat[r][c],int n,int f)
{
    int i,j;
    double v;

    if(r==0)
    {
        if(f==1)
            printf("No A matrix found\n");
        else
            printf("No B matrix found\n");
    }
    else
    {
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                v=(mat[i][j]*1.00)/(n*1.00);
                printf("%.2f ",v);
            }
            printf("\n");
        }
    }

}

void transpose(int r,int c,int mat[r][c],int f)
{
    if(r==0)
    {
         if(f==1)
            printf("No A matrix found\n");
        else
            printf("No B matrix found\n");
    }
    else
    {
        int t[r][c],i,j;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                t[j][i]=mat[i][j];
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%d ",t[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    char input[10];
    int r1=0,r2=0,c1=0,c2=0,mata[5][5],matb[5][5],i,j,n=0,t,c=0;
    while(1)
    {
        gets(input);
        inputModification(input);
        if(input[0]=='e'&&input[1]=='x'&&input[2]=='i'&&input[3]=='t')
            break;
        else if(input[0]=='i'&&input[1]=='n'&&input[2]=='a')
        {
            scanf("%d %d",&r1,&c1);
            for(i=0; i<r1; i++)
            {
                for(j=0; j<c1; j++)
                    scanf("%d",&mata[i][j]);
            }
        }
        else if(input[0]=='i'&&input[1]=='n'&&input[2]=='b')
        {
            scanf("%d %d",&r2,&c2);
            for(i=0; i<r2; i++)
            {
                for(j=0; j<c2; j++)
                    scanf("%d",&matb[i][j]);
            }
        }
        else if(input[0]=='o'&&input[1]=='u'&&input[2]=='t'&&input[3]=='a')
            print(r1,c1,mata,1);
        else if(input[0]=='o'&&input[1]=='u'&&input[2]=='t'&&input[3]=='b')
            print(r2,c2,matb,2);
        else if(input[0]=='a'&&input[1]=='+'&&input[2]=='b')
            addition(r1,c1,mata,r2,c2,matb);
        else if(input[0]=='b'&&input[1]=='+'&&input[2]=='a')
            addition(r1,c1,mata,r2,c2,matb);
        else if(input[0]=='a'&&input[1]=='-'&&input[2]=='b')
            subtraction(r1,c1,mata,r2,c2,matb,1);
        else if(input[0]=='b'&&input[1]=='-'&&input[2]=='a')
            subtraction(r2,c2,matb,r1,c1,mata,2);
        else if(input[0]=='a'&&input[1]=='*'&&input[2]=='b')
            multiplication(r1,c1,mata,r2,c2,matb,1);
        else if(input[0]=='b'&&input[1]=='*'&&input[2]=='a')
            multiplication(r2,c2,matb,r1,c1,mata,2);
        else if((input[0]=='a'||input[0]=='b')&&input[1]=='/')
        {
            n=0;
            for(i=strlen(input)-1;i>=2;i--)
            {
                t=input[i]-'0';
                n+=pow(10,c)*t;
                c++;
            }
            if(input[0]=='a')
            {
                divide(r1,c1,mata,n,1);
            }
            else
                divide(r2,c2,matb,n,2);
        }
        else if(input[0]=='t'&&input[1]=='r'&&input[2]=='a'&&input[3]=='n'&&input[4]=='s'&&input[5]=='a')
            transpose(r1,c1,mata,1);
        else if(input[0]=='t'&&input[1]=='r'&&input[2]=='a'&&input[3]=='n'&&input[4]=='s'&&input[5]=='b')
            transpose(r2,c2,matb,1);
    }
}
