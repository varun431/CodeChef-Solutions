#include <bits/stdc++.h>
#include <ctime>
#define max 10000007
#define pb push_back
#define sf scanf
#define pf printf
using namespace std;

//const ll mod = 1000000007;

inline int read()
{
    int input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

inline void write(int n)
{
    char out[32],i=0;
    if(n==0)
        putchar('0');
    while(n!=0)
    {
        out[i++] = n%10 + '0';
        n /= 10;
    }
    while(i!=0)
    {
        putchar(out[--i]);
    }
    putchar('\n');
}

int main()
{
    //clock_t time = clock();
    int t;
    t = read();
    while(t--)
    {
        int n,k,e,m;
        n = read(), k = read(), e = read(), m = read();
        int total[n] = {0};
        for(int i=0; i<n; i++)
        {
            if(i == n-1)
            {
                for(int j=0; j<e-1; j++)
                {
                    int temp = read();
                    total[i] += temp;
                }
            }
            else
            {
                for(int j=0; j<e; j++)
                {
                    int temp = read();
                    total[i] += temp;
                }
            }
        }
        sort(total, total+n-1);
        int diff = total[k-1]-total[n-1]+1;
        //cout<<"TEST SAMPLE:  "<<total[k-1]<<"\t"<<total[n-1]<<"\t"<<diff<<endl;
        if(diff <= 0)
            write(0);
        else if(diff > m)
            printf("Impossible\n");
        else
            write(diff);
    }
    //cout<<std::fixed<<std::setprecision(9)<<1000*double(clock() - time)/CLOCKS_PER_SEC<<" ms\n";
}
