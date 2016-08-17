#include <bits/stdc++.h>
#define LL long long
#define max 10000009
#define FOR(i,a,b,inc) for(LL i=a; i<=b; i=i+inc)
using namespace std;

LL mark[max] = {0};
LL phi[max];

void sieve()
{
    LL sqt = sqrt(max);
    mark[1] = 1;
    for(int i=3;i<=10;i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i;j<=100;j+=2*i)
            {
                mark[j] = 1;
            }
        }
    }
}

void eulerSieve()
{
    FOR(i,1,max,1)
        phi[i] = i;
    for (int i = 1; i <= sqrt(max); i++) {
        if (i&1 && !mark[i])
            for (int j = i; j <= max; j += i)
                phi[j] -= phi[j] / i;
    }
}

vector<LL> divi;

void calcuDiv(int n)
{
    divi.push_back(1);
    divi.push_back(n);
    LL sqt = sqrt(n);
    FOR(i,2,sqt,1)
    {
        if(n%i==0)
        {
            divi.push_back(i);
            divi.push_back(n/i);
        }
    }
    if(sqt*sqt==n)
        divi.erase(divi.end()-1);
}

void write(LL n)
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

LL read()
{
    LL input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

int main()
{
    sieve();
    eulerSieve();
    int t;
    t = read();
    while(t--)
    {
        divi.clear();
        LL n;
        long long sum=0;
        n = read();
        calcuDiv(n);
        FOR(i,0,divi.size()-1,1)
        {
            sum += ((n*phi[n/divi[i]])/divi[i]);
        }
        write(sum);
    }
}
