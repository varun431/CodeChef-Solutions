#include <bits/stdc++.h>
#include <ctime>
#define max 10000007
#define pb push_back
#define sf scanf
#define pf printf
#define ll long long
using namespace std;

const ll mod = 1000000007;

inline ll read()
{
    ll input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

inline void write(ll n)
{
    char out[32],i=0;
    if(n==0)
	putchar('0');
    while(n!=0)
    {
        out[i++] = n%10 + '0';
        n /= 10;
    }
    while(i!=0)
    {
        putchar(out[--i]);
    }
    putchar('\n');
}

ll pow(ll base, ll exp)
{
    ll ans = 1;
    while(exp>0)
    {
        if(exp&1)
            ans = (ans*base)%mod;
        base = (base*base)%mod;
        exp>>=1;
    }
    return ans;
}

int main()
{
    clock_t time = clock();
    int t;
    t = read();
    while(t--)
    {
        ll n,k;
        n = read(),k = read();
        printf("%lld\n",(n*pow(n-1,k-1))%mod);
    }
    cout<<std::fixed<<std::setprecision(9)<<1000*double(clock() - time)/CLOCKS_PER_SEC<<" ms\n";
}
