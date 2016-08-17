#include <bits/stdc++.h>
using namespace std;

char** read()
{
    char** color = new char*[6];
    for(int i=0; i<6; i++)
    {
        color[i] = new char[6];
    }
    char c=getchar();
    for(int i=0; i<6; i++)
    {
        int j=0;
        while(c != EOF)
        {
            color[i][j++] = c;
            c = getchar();
        }
        cout<<color[i]<<"\n";
    }
    return color;
}

int main()
{
    unsigned int t;
    scanf("%u",&t);
    while(t--)
    {
        char** color = new char*[6];
        for(int i=0; i<6; i++)
        {
            color[i] = new char[6];
        }
        short count,flag=0,z,i,j;
        /*for(int i=0; i<6 ;i++)
        {
            scanf("%s",color[i]);
        }*/
        color = read();
        //cout<<color[0]<<" "<<color[1]<<"\n";
        printf("%s %s\n",color[0],color[1]);
        for(i=0; i<6; i++)
        {
            count=1;
            if(i&1)
            {
                z=i+1;
            }
            else
            {
                z=i+2;
            }
            for(j=z; j<6; j++)
            {
                //printf("%s %s %s\n",color[i],color[j],color[(j+1)%6]);
                if(strcmp(color[i],color[j]) == 0)
                {
                    if(j%2==0)
                    {
                        if(strcmp(color[j],color[j+1]) != 0)
                        {
                            //cout<<"YO\n";
                            count++;
                        }
                    }
                    else
                    {
                        //cout<<count<<"  "<<j<<" xolo\n";
                        count++;
                    }
                }
                if(count==3)
                {
                    printf("YES\n");
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(!flag)
        {
            printf("NO\n");
        }
    }
}
