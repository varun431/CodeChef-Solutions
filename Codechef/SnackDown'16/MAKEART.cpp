#include <bits/stdc++.h>
#define pb push_back
#define sf scanf
#define pf printf
#define ll long long
using namespace std;

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

int main()
{
    int t;
    t = read();
    while(t--)
    {
        int n;
        n = read();
        int c[n],colors=1,first=1,last=1;
        for(int i=0; i<n; i++)
        {
            c[i] = read();
            if(i!=0 && c[i-1] != c[i])
                colors++;
            if((i>=1 && i<=2) && (c[i]==c[i-1]))
                first++;
            if(n>3 && (i>=n-2 && i<=n-1) && (c[i] == c[i-1]))
                last++;
        }
        if(n==3 && colors>1)
        {
            puts("No");
            continue;
        }
        if(first!=3 && last!=3)
        {
            puts("No");
            continue;
        }
        puts("Yes");
    }
}
