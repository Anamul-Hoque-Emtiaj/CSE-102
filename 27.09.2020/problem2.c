#include<stdio.h>

int main()
{
    int lcm;
    scanf("%d",&lcm);
    printf("LCM of all numbers up to now is %d\n",lcm);
    while(1)
    {
        int current,i,maxi;
        scanf("%d",&current);
        if(current>lcm) maxi=current;
        else maxi=lcm;
        for(i=maxi;;i++)
        {
            if(i%current==0&&i%lcm==0)
            {
                lcm=i;
                break;
            }
        }
        printf("LCM of all numbers up to now is %d\n",lcm);
        if(lcm>10000) break;
    }
}

