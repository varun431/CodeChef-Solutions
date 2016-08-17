#include <bits/stdc++.h>
#define limit 1000007
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;

typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;
ll lazy[limit] = {0};
ll tree[limit] = {0};

matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int fib(ll N)
{
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;

    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    if (N == 1)
        return 1;
    T = pow(T, N-1);

    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}

void update(int currind, int start, int end, int qstart, int qend, int add)
{
    if(lazy[currind] != 0)
    {
        tree[currind] += (end-start+1)*lazy[currind];
        if(start != end)
        {
            lazy[2*currind+1] += lazy[currind];
            lazy[2*currind+2] += lazy[currind];
        }
        lazy[currind] = 0;
    }
    if(start > end || qstart > end || qend < start)
        return ;
    if(qstart <= start and qend >= end)
    {
        tree[currind] += (end-start+1)*add;
        if(start != end)
        {
            lazy[2*currind+1] += add;
            lazy[2*currind+2] += add;
        }
        return;
    }
    int mid = (start+end)/2;
    update(2*currind+1, start, mid, qstart, qend, add);
    update(2*currind+2, mid+1, end, qstart, qend, add);

    tree[currind] = tree[2*currind+1] + tree[2*currind+2];
}

int sum(int currind, int start, int end, int qstart, int qend)
{
    if(lazy[currind] != 0)
    {
        tree[currind] += (end-start+1)*lazy[currind];
        if(start != end)
        {
            lazy[2*currind+1] += lazy[currind];
            lazy[2*currind+2] += lazy[currind];
        }
        lazy[currind] = 0;
    }
    if(start > end || qstart > end || qend < start)
        return 0;
    if(start >= qstart && end <= qend)
        return tree[currind];
    int mid = (start + end)/2;
    return sum(2*currind+1, start, mid, qstart, qend) + sum(2*currind+2, mid+1, end, qstart, qend);
}

void construct(int arr[], int currind, int start, int end)
{
    if(start > end)
        return;
    if(start == end)
    {
        tree[currind] = arr[start];
        return ;
    }
    int mid = (start + end)/2;
    construct(arr, 2*currind+1, start, mid);
    construct(arr, 2*currind+2, mid+1, end);
    tree[currind] = tree[2*currind+1] + tree[2*currind+2];
}

int main()
{
    clock_t t = clock();
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    construct(arr, 0, 0, n-1);
    while(m--)
    {
        int x,y;
        ll ans=0;
        char type;
        cin>>type;
        scanf("%d %d",&x,&y);
        if(type == 'C') {
            x -= 1;
            int current = sum(0, 0, n-1, x, x);
            update(0, 0, n-1, x, x, y-current);
        }
        else
        {
            x -= 1, y -= 1;
            for(int j=1; j<=(y-x+1); j++)
            {
                int o = y-x+1;
                vector<bool> v(o);
                fill(v.begin()+o-j, v.end(), true);
                do
                {
                    int tsum=0;
                    for (int i = 0; i < o; ++i) {
                        if (v[i]) {
                            tsum += sum(0, 0, n-1, i+x, i+x);
                        }
                    }
                    ans = (ans + fib(tsum))%MOD;
                } while(next_permutation(v.begin(), v.end()));
            }
            printf("%lld\n",ans);
        }
    }
    cout<<std::fixed<<std::setprecision(9)<<double(clock() - t)/CLOCKS_PER_SEC<<" ms\n";
}
