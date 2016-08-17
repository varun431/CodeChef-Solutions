#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll flag=0,temp=0,ans;
        ll n;
        scanf("%lli",&n);
        ans = n;
        ll arr[n];
        scanf("%lli",&arr[0]);
        for(int i=1;i<n;i++)
        {
            scanf("%lli",&arr[i]);
            if(arr[i] >= arr[i-1])
            {
                temp++;
                flag=1;
            }
            else
            {
                flag=0;
                ans += ((temp+1)*temp)>>1;
                temp=0;
            }
        }
        ans += ((temp+1)*temp)>>1;
        printf("%lli\n",ans);
    }
}
