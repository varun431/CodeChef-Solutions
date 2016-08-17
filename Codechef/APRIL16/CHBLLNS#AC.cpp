#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int cnt=3;
        long long r,g,b,k,ans=0;
        scanf("%lld %lld %lld",&r,&g,&b);
        scanf("%lld",&k);
        if(k>r)
            cnt--, ans += r;
        if(k>g)
            cnt--, ans += g;
        if(k>b)
            cnt--, ans += b;
        //cout<<ans<<" ANS\n"<<cnt<<" CNT\n";
        ans += (cnt*(k-1)+1);
        printf("%lld\n", ans);
    }
}
