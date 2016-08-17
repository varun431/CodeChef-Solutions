#include <bits/stdc++.h>
#define ll unsigned long long
#define scani(n) scanf("%d",&n)
#define scanb(n) scanf("%lli",&n)
#define print(n) printf("%d\n",n)
using namespace std;

inline ll check(ll n)
{
    if(n<9)
        return n;
    else
    {
        ll ans;
        ans = n%9;
        if(ans==0)
            return 9;
        return ans;
    }
}

void write(ll n)
{
    char out[32],i=0;
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

ll read()
{
    ll input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

int main()
{

    unsigned long long t;
    //scani(t);
    t=read();
    while(t--)
    {
        ll a,d,l,r,nth,sum=0,dig,div;
        unsigned int store[10],mod;
        //scanb(a);scanb(d);scanb(l);scanb(r);
        a=read(),d=read(),l=read(),r=read();
        dig = r-l+1;
        mod = dig%9;
        div = dig/9;
        nth = a+(l-1)*d;
        nth = check(nth);
        unsigned int temp = 0;
        for(ll i=l;i<=min(l+8,r);i++)
        {
            temp++;
            unsigned int mul=0;
            temp>mod?(mul=0):(mul=1);
            sum += nth*(div+mul);
            nth = check(nth+d);
            //cout<<sum<<" SUM\n";
        }
        //print(sum);
        write(sum);
    }
}
