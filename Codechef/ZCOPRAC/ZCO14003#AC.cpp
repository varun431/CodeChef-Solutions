#include <bits/stdc++.h>
#define ll long long
#define scan(n) scanf("%lli",&n)
using namespace std;

int main()
{
    ll n;
    scan(n);
    ll budget[n],revenue=0;
    for(int i=0;i<n;i++)
        scan(budget[i]);
    sort(budget,budget+n);
    for(int i=0;i<n;i++)
    {
        revenue = max(budget[i]*(n-i),revenue);
    }
    printf("%lli\n",revenue);
}
