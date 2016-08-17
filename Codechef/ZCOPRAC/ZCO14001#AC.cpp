#include <bits/stdc++.h>
#define ll long long
#define scan(n) scanf("%lli",&n)
using namespace std;

int main()
{
    ll t_stack, m_height,crane=0;
    bool hold=false;
    scan(t_stack);scan(m_height);
    ll boxes[t_stack];
    for(int i=0;i<t_stack;i++)
    {
        scan(boxes[i]);
    }
    vector<int> inst;
    int z;
    scanf("%d",&z);
    while(z!= 0)
    {
        inst.push_back(z);
        scanf("%d",&z);
    }
    for(int i=0;i<inst.size();i++)
    {
        switch(inst[i])
        {
        case 1:
            if(crane>0)
            {
                crane--;
            }
            break;
        case 2:
            if(crane<t_stack-1)
            {
                crane++;
            }
            break;
        case 3:
            if(boxes[crane]>0 && hold==false)
            {
                boxes[crane]--;
                hold=true;
            }
            break;
        case 4:
            if(boxes[crane]<m_height && hold==true)
            {
                boxes[crane]++;
                hold=false;
            }
            break;
        }
    }
    for(int i=0;i<t_stack;i++)
    {
        printf("%lli ",boxes[i]);
    }
}
