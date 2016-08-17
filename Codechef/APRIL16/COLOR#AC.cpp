#include <bits/stdc++.h>
#define limit 100007
using namespace std;

int maxi(int *rgb)
{
    return max(rgb[0], max(rgb[1], rgb[2]));
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        string color;
        cin>>color;
        int rgb[3] = {0};
        for(int i=0; i<n; i++)
        {
            if(color[i]=='R')
                rgb[0]++;
            else if(color[i]=='G')
                rgb[1]++;
            else
                rgb[2]++;
        }
        printf("%d\n",n-maxi(rgb));
    }
}
