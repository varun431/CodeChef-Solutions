#include <bits/stdc++.h>
#define ll long long
#define pr(a) printf("%lli\n",a)
#define sc(a) scanf("%lli",&a)

using namespace std;

int main()
{
    ll t,ans,sum,n1,n2,m;
    sc(t);
    while(t--)
    {
        sc(n1);sc(n2);sc(m);
        sum = (m*(m+1))/2;
        if(sum >= max(n1,n2))
            printf("0\n");
        else if(sum >= min(n1,n2))
            pr(max(n1,n2) - m);
        else
            pr(n1 + n2 - 2*sum);
    }
}
