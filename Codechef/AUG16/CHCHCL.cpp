#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		long long ans = n*m-1;
		if(ans&1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}