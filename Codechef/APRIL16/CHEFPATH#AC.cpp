#include <bits/stdc++.h>
#define yes printf()
#define ll long long
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,m;
        scanf("%lld %lld",&n,&m);
        if(n==1 || m==1)
        {
            if(n==2 || m==2)
            {
                cout<<"Yes\n";
                continue;
            }
            else
            {
                cout<<"No\n";
                continue;
            }
        }
        else if(n%2==0 || m%2==0)
        {
            cout<<"Yes\n";
            continue;
        }
        else
            cout<<"No\n";
    }
}
