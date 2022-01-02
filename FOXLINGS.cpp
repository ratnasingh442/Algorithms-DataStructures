#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int N,M,u,v;
int main()
{
scanf("%d%d",&N,&M);
int m = M; int c = N;int i;
 map<int,int>map1;
 map<int,int>rank1;
while(m>0)
{
    m--;
    scanf("%d%d",&u,&v);
    if(map1[u] == 0)
    {
        map1[u] = u;
    }
    if(map1[v] == 0)
    {
        map1[v] = v;
    }
    while(map1[u]!= u)
    {
        u = map1[u];
    }
    while(map1[v]!= v)
    {
        v = map1[v];
    }
    if(u!=v)
    {
        c--;
    }
    if(rank1[u]>= rank1[v])
    {
        map1[v] = u;
        if(rank1[u] == rank1[v])
        {
            rank1[u]++;
        }
    }
    else
    {

        map1[u] = v;
    }
}
printf("%d",c);
return 0;
}
