#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    int C,R,i,j,x,y,k,x1,y1,T,r;
    scanf("%d",&T);
    for(r = 0;r<T;r++)
    {
    scanf("%d%d",&C,&R);
    char m[R][C]; int v[R][C]; queue<pair<int,int> >s;
    for(i = 0;i<R;i++)
    {
            scanf(" %c",&m[i]);
    }
    for(i = 0;i<R;i++)
    {
        for(j = 0;j<C;j++)
        {   if(m[i][j] == '.')
        {
            v[i][j] = 0;
        }
        else
        {
            v[i][j] = 1;
        }
        }
    }
    int d = 0;int a[4] = {+1,-1,0,0};int b[4] = {0,0,1,-1}; pair<int,int>p(x,y); int max = 0;
  int c = 1; int flag = 0; int g,u;

    for(g= 0;g<R;g++)
    {
        for(u = 0;u<C;u++)
        {
            if(v[g][u] == 0)
            {
                v[g][u] = 1;
               x = g; y = u;
                   d = 0;
               p = make_pair(x,y);
               s.push(p);
                while(true)
                {
                   c = s.size();
                    while(c>0)
                    {
                        c--;
                        pair<int,int>h;
                    h = s.front(); x = h.first; y = h.second;
                    s.pop();

                    for(k = 0;k<4;k++)
                    {
                        x1 = x+a[k]; y1 = y+b[k];
                        if(x1>=0&&x1<R&&y1>=0&&y1<C)
                        {
                        if(v[x1][y1] == 0)
                        {
                            pair<int,int>p1;
                            p1 = make_pair(x1,y1);
                         s.push(p1);
                         v[x1][y1] = 1;
                        }
                    }}
                    if(s.empty())
                    {   flag = 1;
                        break;
                    }
                }
                if(flag == 1)
                {
                    break;
                }
                 d++;
            }
            if(max<d)
            {
                max = d;
            }
        }
    }
}
    printf("Maximum rope length is %d.\n",max);
    }

    return 0;
}
