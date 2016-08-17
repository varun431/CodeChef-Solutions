#include <bits/stdc++.h>
using namespace std;

long long INF = LLONG_MAX;

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        int h[n],m[n];
        vector<long long> s1(n-1,-1), l1(n-1,-1), s2(n-1,-1), l2(n-1,-1);
        long long rs1,rl1,rs2,rl2;

        for(int i=0;i<n;i++) {
            scanf("%d%d",&h[i],&m[i]);
        }

        //pattern
        for(int i=0;i<n-1;i++) {
            if(m[i]<m[i+1]) {
                l1[i]=INF;
                if(h[i]<h[i+1]) {
                    s1[i]=0;
                }
                else if(h[i]>h[i+1]){
                    s1[i]=h[i]-h[i+1]+1;
                    s2[i]=0, l2[i]=h[i]-h[i+1]-1;
                }
                else {
                    s1[i]=1;
                }
            }
            else if(m[i]==m[i+1]) {
                if(h[i]<h[i+1]) {
                    l1[i]=INF, s1[i]=0;
                }
                else if(h[i]>h[i+1]) {
                    l2[i]=INF, s2[i]=0;
                }
            }
            else if(m[i]>m[i+1]) {
                l2[i]=INF;
                if(h[i]<h[i+1]) {
                    s1[i]=0, l1[i]=h[i+1]-h[i]-1;
                    s2[i]=h[i+1]-h[i]+1;
                }
                else if(h[i]>h[i+1]) {
                    s2[i]=0;
                }
                else {
                    s2[i]=1;
                }
            }
        }

        for(int i=0;i<n-1;i++) {
            if(i&1){
                swap(s1[i],s2[i]);
                swap(l1[i],l2[i]);
            }
        }
        //Range
        rs1=s1[0], rs2=s2[0];
        rl1=l1[0], rl2=l2[0];
        //cout<<rs1<<" "<<rl1<<endl;
        int flag1=1,flag2=1;
        if(rs1==-1)
            flag1=0;
        if(rs2==-1)
            flag2=0;
        for(int i=1; i<n-1;i++) {
            if(flag1 && s1[i]!=-1) {
                if(rs1<s1[i]) {
                    if(s1[i]<=rl1) {
                        rs1 = s1[i];
                        rl1 = min(rl1,l1[i]);
                    }
                    else
                        flag1=0;
                }
                else {
                    if(rs1>l1[i])
                        flag1=0;
                    else
                        rl1=min(rl1,l1[i]);
                }
            }
            else {
                flag1=0;
            }
            if(flag2 && s2[i]!=-1) {
                if(rs2<s2[i]) {
                    if(s2[i]<=rl2) {
                        rs2 = s2[i];
                        rl2 = min(rl2,l2[i]);
                    }
                    else
                        flag2=0;
                }
                else {
                        if(rs2>l2[i])
                            flag2=0;
                        else
                            rl2=min(rl2,l2[i]);
                }
            }
            else {
                flag2=0;
            }
            //cout<<rs1<<" "<<rl1<<endl;
        }

        if(flag1==0 && flag2==0)
            printf("0\n");
        else if(flag1==0) {
            printf("1\n");
            if(rl2==INF)
                printf("%lld Inf\n",rs2);
            else
                printf("%lld %lld\n",rs2,rl2);
        }
        else if(flag2==0) {
            printf("1\n");
            if(rl1==INF)
                printf("%lld Inf\n",rs1);
            else
                printf("%lld %lld\n",rs1,rl1);
        }
        else {
            printf("2\n");
            if(rs1<rs2) {
                if(rl1==INF)
                    printf("%lld Inf\n",rs1);
                else
                    printf("%lld %lld\n",rs1,rl1);
                if(rl2==INF)
                    printf("%lld Inf\n",rs2);
                else
                    printf("%lld %lld\n",rs2,rl2);
            }
            else {
                if(rl2==INF)
                    printf("%lld Inf\n",rs2);
                else
                    printf("%lld %lld\n",rs2,rl2);
                if(rl1==INF)
                    printf("%lld Inf\n",rs1);
                else
                    printf("%lld %lld\n",rs1,rl1);
            }
        }
    }
}
