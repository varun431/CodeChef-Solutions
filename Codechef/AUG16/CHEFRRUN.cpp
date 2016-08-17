#include <bits/stdc++.h>
using namespace std;

struct Node{
    int tst;
    int starter=-1;
    struct Node* next=NULL;
};
typedef struct Node node;

int main()
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int cnt=0,taste;
		node** nodes = new node*[n];
		for(int i=0; i<n; i++)
            nodes[i] = new node();
		for(int i=0; i<n; i++) {
			cin>>taste;
			nodes[i]->tst = taste;
			nodes[i]->next = nodes[(i+taste+1)%n];
		}
		for(int i=0; i<n; i++) {
            node* tmp = nodes[i];
            while(tmp->starter == -1) {
                tmp->starter = i;
                tmp = tmp->next;
            }
            if(tmp->starter==i) {
                cnt++;
                node* tmper = tmp->next;
                while(tmper->starter==i && tmper != tmp) {
                    cnt++;
                    tmper = tmper->next;
                }
            }
		}
		cout<<cnt<<endl;
	}
}
