#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,m,gcdV;
        scanf("%llu %llu",&n,&m);
        gcdV = gcd(n,m);
        if(gcdV == 1)
            printf("Yes\n");
        else
            printf("No %lli\n",n/gcdV);
    }
}
