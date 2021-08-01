#include<bits/stdc++.h>
using namespace std;

int number_of_coin(int *c,int *a,int in,int v,int n)
{
    int i,mini=v+10,cur,value;
    if(in==v+1)
        return a[v];
    for(i=0;i<n;i++)
    {
        if(c[i]<=in)
        {
            cur=a[in-c[i]]+1;
            if(cur<mini)
                mini=cur;
        }
    }
    a[in]=mini;
    a[in+1]=number_of_coin(c,a,in+1,v,n);
}

int main()
{
    int n,result;
    cin>>n;
    int c[n],i,v;
    for(i=0;i<n;i++)
        cin>>c[i];
    cin>>v;
    int a[v+5]={0};
    result = number_of_coin(c,a,1,v,n);
    cout<<result<<endl;
}
