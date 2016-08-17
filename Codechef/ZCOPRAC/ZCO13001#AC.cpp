#include <bits/stdc++.h>
#define ll long long
#define scan(n) scanf("%lld",&n)
using namespace std;

int main()
{
    ll n,profit=0;
    scan(n);
    ll power[n];
    for(ll i=0;i<n;i++)
    {
        scanf("%lli",&power[i]);
    }
    sort(power,power+n);
    for(ll i=n-1; i>=0; i--)
    {
        profit += (power[i]*i - power[i]*(n-1-i));
    }
    printf("%lli\n",profit);
}
