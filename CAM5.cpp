#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    int N,n,i,u,v,t,j,T,k;
    scanf("%d",&T);
    for(k = 0;k<T;k++)
    {
    int d = 0;
    scanf("%d",&N);
    int visit[N];
    stack<int>s;
    scanf("%d",&n);
    vector<int>arr[N];
    while(n>0)
    {
        n--;
        scanf("%d%d",&u,&v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(i = 0;i<N;i++)
    {
       visit[i] = 0;
    }
    for(i = 0;i<N;i++)
    {
        if(visit[i] == 0)
           {
            s.push(i);
           visit[i] = 1;
    while(!s.empty())
    {
        t = s.top();
        s.pop();
        for(j = 0;j<arr[t].size();j++)
        {
            if(visit[arr[t][j]]==0)
            {
                s.push(arr[t][j]);
                visit[arr[t][j]] = 1;
            }
        }
    }
    d++;
    }}
    printf("%d\n",d);
    }
    return 0;
}
