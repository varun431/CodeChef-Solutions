#include <bits/stdc++.h>
#define FOR(I,A,B) for(LL I=(A);I<=(B);++I)
#define MAXN 10000009
using namespace std;

typedef unsigned long long LL;
const int N = 10000000;
int hi[MAXN];
int lo[MAXN];
int phi[MAXN];

void phiCal(){
	FOR(i,2,N)
	{
		if(!lo[i])
		{
			int j = 1;
			while(1)
			{
				if( LL(j)*LL(i) > LL(N) )
					break;
				j *= i;
				for(int k=j;k<=N;k+=j)
				{
					hi[k] = j;
					lo[k] = i;
				}
				//cout<<j<<"   Value of j\n";
			}
			//cout<<i<<"   Value of i\n";
		}
	}
	phi[1] = 1;
	FOR(i,2,N)
	{
		phi[i] = phi[i/hi[i]] * (hi[i]/lo[i]*(lo[i]-1));
	}
}

vector<LL> divi;

void calcuDiv(int n)
{
    LL sqt = sqrt(n);
    FOR(i,1,sqt)
    {
        if(n%i==0)
        {
            divi.push_back(i);
            divi.push_back(n/i);
        }
    }
    if(sqt*sqt==n)
        divi.erase(divi.end()-1);
}

void write(LL n)
{
    char out[32],i=0;
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

LL read()
{
    LL input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

int main()
{
    phiCal();
    int t;
    t = read();
    while(t--)
    {
        divi.clear();
        LL n;
        long long sum=0;
        n = read();
        calcuDiv(n);
        FOR(i,0,divi.size()-1)
        {
            sum += ((n*phi[n/divi[i]])/divi[i]);
        }
        write(sum);
    }
}
