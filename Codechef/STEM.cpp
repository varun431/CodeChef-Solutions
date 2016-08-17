#include <bits/stdc++.h>
#include <utility>
#define Map map<string,int>
using namespace std;

int main()
{
    int t,n,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        string word[n], srh;
        Map match;
        cin>>word[0];
        for(int i=1;i<n;i++)
        {
            flag = 0;
            cin>>word[i];
            for(int j=0; j<min(word[i].size(), word[i-1].size()); j++)
            {
                if(word[i][j] == word[i-1][j])
                {
                    flag = 1;
                    srh.push_back(word[i][j]);
                }
                else
                {
                    if(flag == 1)
                    {
                        if(match.count(srh)>0)
                        {
                            match[srh]++;
                        }
                        else
                        {
                            match[srh] = 1;
                        }
                    }
                    flag = 0;
                    srh.erase();
                }
            }
            if(flag == 1)
            {
                if(match.count(srh)>0)
                {
                    match[srh]++;
                }
                else
                {
                    match[srh] = 1;
                }
            }
            flag = 0;
            srh.erase();
        }
        Map::iterator it = match.begin();
        int ans = it->second;
        srh = it->first;
        it++;
        for(; it != match.end(); it++)
        {
            if( ans > it->second);
            else if( ans < it->second)
            {
                srh = it->first;
                ans = it->second;
            }
        }
        cout<<srh<<"\n";
    }
}
