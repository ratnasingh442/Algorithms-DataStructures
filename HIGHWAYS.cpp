#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define INF 1000000
using namespace std;
int main()
{
    int N,h,s,des,n,u,v,n1,w,i,j,weight,k,e;
    int T;
    scanf("%d",&T);
    for(e = 0;e<T;e++)
    {
    int flag = 0;
    scanf("%d%d%d%d",&N,&h,&s,&des);
    vector<pair<int,int> >arr[N+1];
    priority_queue < pair<int, int>, vector<pair<int, int> >,greater<pair <int, int> > >q;
    int d[N+1];
    n = h; n1 = N;
    while(n>0)
    {
        n--;
        pair<int,int>p;
        pair<int,int>p1;
        scanf("%d%d%d",&u,&v,&w);
        p = make_pair(v,w);
        p1 = make_pair(u,w);
        arr[u].push_back(p);
        arr[v].push_back(p1);
    }
    q.push(make_pair(0,s));
    d[s] = 0;
    for(i = 1;i<=n1;i++)
    {  pair<int,int>p2;
    p2 = make_pair(INF,i);
    if(p2.second== s)
        continue;
        q.push(p2);
        d[i] = INF;
    }
    while(!q.empty())
    {
        int t = q.top().second;
        int r = q.top().first;
        q.pop();
        for(j = 0;j<arr[t].size();j++)
        {
            weight = arr[t][j].second;
           if(d[arr[t][j].first]>d[t]+weight)
           {
              d[arr[t][j].first] = d[t]+weight;
              q.push(make_pair(d[arr[t][j].first],arr[t][j].first));
           }
        }
    }

    if(d[des] == INF)
    {
        printf("NONE\n");
    }
    else
    {
        printf("%d\n",d[des]);
    }
    }
    return 0;
}


