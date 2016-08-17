#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lli",&n);
        ll prize[n+1];
        int index=0;
        string correct, chef;
        cin>>correct;
        cin>>chef;
        for(int i=0;i<=n;i++)
        {
            scanf("%lli",&prize[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(correct[i] == chef[i])
            {
                index++;
            }
        }
        printf("%lli\n",prize[index]);
    }
}
