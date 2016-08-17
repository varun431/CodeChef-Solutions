#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

inline ll modcheck(ll n)
{
    if(n>=mod)
        return n%mod;
    return n;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        ll sum=0,ans=0,game;
        scanf("%d",&n);
        int a[n+1];
        for(int i=0; i<n+1; i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        sum = modcheck(sum);
        for(int i=1; i<n+1; i++)
        {
            ans += modcheck(sum*a[i]);
        }
    }
}
