#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        int dist[n],s,e;
        long long sum[n];
        vector<int> negpos;
        for(int i=0; i<n; i++) {
            scanf("%d",&dist[i]);
            if(dist[i]<0)
                negpos.push_back(i);
            if(i!=0)
                sum[i]=sum[i-1]+dist[i];
            else
                sum[i]=dist[i];
        }
        scanf("%d%d",&s,&e);
        if(s>e)
            swap(s,e);
        s-=1,e-=1;
        if(s==e) {
            printf("%lli\n",sum[n-1]);
            continue;
        }
        long long fwd;
        if(s>0)
            fwd=sum[e-1]-sum[s-1];
        else
            fwd=sum[e-1];
        long long bck=sum[n-1]-fwd;
        long long ans=LLONG_MAX;
        long long tsum=0;
        for(int i=0; i<negpos.size();i++) {
            if(negpos[i]>=e) {
                if(s>0)
                    tsum=2*(sum[s-1]+sum[n-1]-sum[negpos[i]-1]);
                else
                    tsum=2*(sum[n-1]-sum[negpos[i]-1]);
                //cout<<tsum<<" tsum1"<<endl;
                if(tsum<0)
                    tsum+=fwd;
                else
                    tsum=fwd;
            }
            else if(negpos[i]<s) {
                if(i>0)
                    tsum=2*(sum[s-1]-sum[negpos[i]-1]);
                else
                    tsum=2*sum[s-1];
                //cout<<tsum<<" tsum2"<<endl;
                if(tsum<0)
                    tsum+=fwd;
                else
                    tsum=fwd;
            }
            else if(negpos[i]>=s && negpos[i]<e) {
                if(s>0)
                    tsum=2*(sum[negpos[i]]-sum[s-1]);
                else
                    tsum=2*sum[negpos[i]];
                //cout<<tsum<<" tsum3"<<endl;
                if(tsum<0)
                    tsum+=bck;
                else
                    tsum=bck;
            }
            ans=min(ans,tsum);
            tsum=0;
        }
        if(negpos.size()==0)
            ans=min(fwd,bck);
        printf("%lli\n",ans);
    }
}
