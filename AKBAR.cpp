#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    long long int T,t,i,k,s;
    scanf("%lld",&T);
    for(t = 0;t<T;t++)
    {
        long long int n,r,m,u,v; int flag = 0;
        scanf("%lld%lld%lld",&n,&r,&m);
        vector<long long int>arr[n+1];
        while(r>0)
        {
            r--;
            scanf("%lld%lld",&u,&v);
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        int visit[n+1]; int color[n+1];
        for(i = 1;i<=n;i++)
        {
            visit[i] = 0;
            color[i] = 0;
        }
        queue<pair<long long int,long long int> >q;
        vector<pair<int,int> >arr2;
        //queue<pair<long long int,long long int> >q2;
        while(m>0)
        {
            m--;
            scanf("%lld%lld",&k,&s);
            arr2.push_back(make_pair(k,s));
            visit[k] = 1;
            color[k] = 1;
        }
        for(int a = 0;a<arr2.size();a++)
        {
            q.push(arr2[a]);
            visit[arr2[a].first] = a+1;
        while(!q.empty())
        {
            long long int x = q.front().first;
            long long int w = q.front().second;
            q.pop();
            if(w!=0)
            {
                for(long long int j = 0;j<arr[x].size();j++)
                {
                    if(visit[arr[x][j]] == a && color[arr[x][j]] == 0)
                    {
                        q.push(make_pair(arr[x][j],w-1));
                        visit[arr[x][j]] = a+1; color[arr[x][j]] = 1;
                    }
                    else if(visit[arr[x][j]] == a && color[arr[r][j]] == 1)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 1)break;
        }
        }
        for(i = 1;i<=n;i++)
        {
            if(color[i]!=1)
            {
                flag = 1;break;
            }
        }
        if(flag == 0)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
