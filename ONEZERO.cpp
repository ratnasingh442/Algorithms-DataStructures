#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    int T,t;long long int n;
    scanf("%d",&T);
    for(t = 0;t<T;t++)
    {
        scanf("%lld",&n);
        queue<long long int>q;
        q.push(1);
        while(!q.empty())
        {
            long long int r = q.front();
            q.pop();
            if((r>=n) && (r%n==0))
            {
                cout<<r<<endl;
                break;
            }
            q.push(r*10);
            q.push((r*10)+1);
        }
    }
    return 0;
}
