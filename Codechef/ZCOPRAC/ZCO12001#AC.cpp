#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int br[n],temp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if(temp==1)
            br[i]=1;
        else
            br[i]=-1;
    }
    int depth=0,dpos,len=0,lpos,cnt=0,temppos;
    for(int i=0;i<n;i++)
    {
        if(br[i]>0)
        {
            if(cnt==0)
            {
                temppos=i;
            }
            cnt++;
            if(depth<cnt)
            {
                depth=cnt;
                dpos=i;
            }
        }
        else
        {
            cnt--;
            if(cnt==0)
            {
                if(len<(i-temppos+1))
                {
                    len=i-temppos+1;
                    lpos=temppos;
                }
            }
        }
    }
    printf("%d %d %d %d",depth,dpos+1,len,lpos+1);
}
