#include <bits/stdc++.h>

#define vec vector< string >
#define Map map<string, int>
#define Pair pair<string, int>
#define pb(a) push_back(a)
using namespace std;

void rest(vec words, Map check)
{
    int j=0;
    cout<<(unsigned)words.size()<<" Size of words"<<endl;
    cout<<(unsigned)check.size()<<" Size of check"<<endl;
    while(j<words.size())
    {
        int flag=0;
        for(int i=0; i<check.size(); i++)
        {
            if(check.count(words[j]) > 0)
            {
                cout<<"YES ";
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"NO ";
        }
        j++;
    }
    cout<<endl;
}

int main()
{
    int t,w,p,l,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&w,&p);

        vector<string> words;
        for(int i=0; i<w; i++)
        {
            string inp;
            cin>>inp;
            words.push_back(inp);
        }
        Map check;
        for(int i=0; i<p; i++)
        {
            scanf("%d",&num);
            for(int j=0; j<num; j++)
            {
                string inp;
                cin>>inp;
                if(check.count(inp) == 0)
                {
                    check.insert( pair<string,int>(inp,1) );
                }
            }
        }
        rest(words,check);
    }
}
