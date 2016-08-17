#include <bits/stdc++.h>
#include <ctime>
#define max 1000000007
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

int main()
{
    //clock_t time = clock();
    int t;
    t = read();
    while(t--)
    {
        int n, b[10001], a[10001], t[10001], cnt=0;
        n = read();
        for(int i=0; i<n; i++) {
            a[i] = read();
            if(i!=0)
                t[i] = a[i] - a[i-1];
            else
                t[i] = a[i];
        }
        for(int i=0; i<n; i++) {
            b[i] = read();
            if(b[i]<=t[i])
                cnt++;
        }
        write(cnt);
    }
    //cout<<std::fixed<<std::setprecision(9)<<1000*double(clock() - time)/CLOCKS_PER_SEC<<" ms\n";
}
