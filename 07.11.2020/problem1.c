#include<stdio.h>
#include<string.h>
#include<math.h>

char input[100];
int r1=0,r2=0,c1=0,c2=0,matA[5][5],matB[5][5];

void inputModification()
{
    char modifyInput[10];
    int in=0,i;
    for(i=0; i<10; i++)
        modifyInput[i]='\0';
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
    input[i]='\0';
}

void takeInputA()
{
    int i,j;
    scanf("%d %d",&r1,&c1);
    for(i=0; i<r1; i++)
        for(j=0; j<c1; j++)
            scanf("%d",&matA[i][j]);
}

void printfA()
{
    int i,j;
    if(r1!=0&&c1!=0)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
                printf("%d ",matA[i][j]);
            printf("\n");
        }
    }
    else
        printf("No A matrix found\n");
}

void takeInputB()
{
    int i,j;
    scanf("%d %d",&r2,&c2);
    for(i=0; i<r2; i++)
        for(j=0; j<c2; j++)
            scanf("%d",&matB[i][j]);
}

void printfB()
{
    int i,j;
    if(r2!=0&&c2!=0)
    {
        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
                printf("%d ",matB[i][j]);
            printf("\n");
        }
    }
    else
        printf("No B matrix found\n");
}

void addition()
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

void subtraction(int f)
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
            {
                if(f==1)
                {
                    printf("%d ",matA[i][j]-matB[i][j]);
                }
                else
                {
                    printf("%d ",matB[i][j]-matA[i][j]);
                }
            }
            printf("\n");
        }
    }
    else
        printf("Subtraction not possible\n");
}

void  multiplication(int f)
{
    int i,j,k,s=0;
    if(r1==0)
        printf("No A matrix found\n");
    else if(r2==0)
        printf("No B matrix found\n");
    else if(r2==c1&&f==1)
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
    else if(r1==c2&&f==2)
    {
        for(i=0; i<r2; i++)
        {
            for(j=0; j<c1; j++)
            {
                for(k=0; k<r1; k++)
                {
                    s+=matB[i][k]*matA[k][j];
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

void divide()
{
    int i,j,n=0,t,c=0;
    double v;
    for(i=strlen(input)-1; i>=2; i--)
    {
        t=input[i]-'0';
        n+=pow(10,c)*t;
        c++;
    }
    if(input[0]=='a')
    {
        if(r1==0)
            printf("No A matrix found\n");
        else
        {
            for(i=0; i<r1; i++)
            {
                for(j=0; j<c1; j++)
                {
                    v=(matA[i][j]*1.00)/(n*1.00);
                    printf("%.2f ",v);
                }
                printf("\n");
            }
        }
    }
    else
    {
        if(r2==0)
            printf("No B matrix found\n");
        else
        {
            for(i=0; i<r2; i++)
            {
                for(j=0; j<c2; j++)
                {
                    v=(matA[i][j]*1.00)/(n*1.00);
                    printf("%.2f ",v);
                }
                printf("\n");
            }
        }
    }
}

void transposeA()
{
    if(r1==0)
        printf("No A matrix found\n");
    else
    {
        int t[r1][c1],i,j;
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
            {
                t[j][i]=matA[i][j];
            }
        }
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
            {
                printf("%d ",t[i][j]);
            }
            printf("\n");
        }
    }
}

void transposeB()
{
    if(r2==0)
        printf("No B matrix found\n");
    else
    {
        int t[r2][c2],i,j;
        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
            {
                t[j][i]=matB[i][j];
            }
        }
        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
            {
                printf("%d ",t[i][j]);
            }
            printf("\n");
        }
    }
}

int determinant(int n,int A[n][n])
{
    int i,j,k,p,q;
    int temp[n-1][n-1];
    int d=0;
    int sign=1;
    if(n==1)
    {
        return A[0][0];
    }
    for(i = 0 ; i < n ; i++)
    {
        p = 0, q = 0;
        for(j = 0 ; j < n ; j++)
        {
            for(k = 0 ; k < n ; k++)
            {
                if(j != 0 && k != i)
                {
                    temp[p][q++] = A[j][k];
                    if(q==n-1)
                    {
                        p++;
                        q=0;
                    }
                }
            }
        }
        d = d + sign*(A[0][i]*determinant(n-1,temp));
        sign*=-1;
    }
    return d;
}

int main()
{
    while(1)
    {
        gets(input);
        inputModification();
        if(input[0]=='e'&&input[1]=='x'&&input[2]=='i'&&input[3]=='t'&&input[4]=='\0')
            break;
        else if(input[0]=='i'&&input[1]=='n'&&input[2]=='a'&&input[3]=='\0')
            takeInputA();
        else if(input[0]=='i'&&input[1]=='n'&&input[2]=='b'&&input[3]=='\0')
            takeInputB();
        else if(input[0]=='o'&&input[1]=='u'&&input[2]=='t'&&input[3]=='a'&&input[4]=='\0')
            printfA();
        else if(input[0]=='o'&&input[1]=='u'&&input[2]=='t'&&input[3]=='b'&&input[4]=='\0')
            printfB();
        else if(input[0]=='a'&&input[1]=='+'&&input[2]=='b'&&input[3]=='\0')
            addition();
        else if(input[0]=='b'&&input[1]=='+'&&input[2]=='a'&&input[3]=='\0')
            addition();
        else if(input[0]=='a'&&input[1]=='-'&&input[2]=='b'&&input[3]=='\0')
            subtraction(1);
        else if(input[0]=='b'&&input[1]=='-'&&input[2]=='a'&&input[3]=='\0')
            subtraction(2);
        else if(input[0]=='a'&&input[1]=='*'&&input[2]=='b'&&input[3]=='\0')
            multiplication(1);
        else if(input[0]=='b'&&input[1]=='*'&&input[2]=='a'&&input[3]=='\0')
            multiplication(2);
        else if((input[0]=='a'||input[0]=='b')&&input[1]=='/')
            divide();
        else if(input[0]=='t'&&input[1]=='r'&&input[2]=='a'&&input[3]=='n'&&input[4]=='s'&&input[5]=='a'&&input[6]=='\0')
            transposeA();
        else if(input[0]=='t'&&input[1]=='r'&&input[2]=='a'&&input[3]=='n'&&input[4]=='s'&&input[5]=='b'&&input[6]=='\0')
            transposeB();
        else if(input[0]=='d'&&input[1]=='e'&&input[2]=='t'&&input[3]=='a'&&input[4]=='\0')
        {
            if(r1==0)
                printf("No A matrix found\n");
            else if(r1==c1)
                printf("%d\n",determinant(r1,matA));
            else
                printf("Determinant not possible\n");
        }
        else if(input[0]=='d'&&input[1]=='e'&&input[2]=='t'&&input[3]=='b'&&input[4]=='\0')
        {
            if(r2==0)
                printf("No B matrix found\n");
            else if(r2==c2)
                printf("%d\n",determinant(r2,matB));
            else
                printf("Determinant not possible\n");
        }
    }
}
