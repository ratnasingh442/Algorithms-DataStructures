#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
    int h,w,i,j;
    scanf("%d%d",&h,&w);int k = 1;
    while(h!=0 || w!= 0)
    {
        char mat[h+1][w+1];
    for(i = 1;i<=h;i++)
    {
        for(j = 1;j<=w;j++)
        {
            scanf(" %c",&mat[i][j]);
        }
    }
    queue<pair<int,int> >q; int visit[h+1][w+1];
     for(i = 1;i<=h;i++)
    {
        for(j = 1;j<=w;j++)
        {
            visit[i][j] = 0;
        }
    }
     int x[8] = {0,0,-1,1,-1,1,1,-1};
                   int y[8] = {1,-1,0,0,-1,1,-1,1}; int x1,y1,xx1,yy1,s; int max1 = 0;
                   for(i = 1;i<=h;i++)
                   {
                       for(j = 1;j<=w;j++)
                       {
                           if(mat[i][j] == 'A')
                            max1 = 1;
                           break;
                       }
                       if(max1 == 1)break;
                   }
    for(i = 1;i<=h;i++)
    {
        for(j = 1;j<=w;j++)
        {
            if(visit[i][j] == 0 && mat[i][j] == 'A')
            {

                q.push(make_pair(i,j));
                visit[i][j] = 1;
                while(!q.empty())
                {
                    x1 = q.front().first;
                    y1 = q.front().second;
                    q.pop();
                    for(s = 0;s<8;s++)
                    {
                        xx1 = x1+x[s];
                        yy1 = y1+y[s];
                        if(xx1>=1 && xx1<=h && yy1>=1 && yy1<=w)
                        {
                            if((visit[xx1][yy1] == 0) && (mat[xx1][yy1] == (mat[x1][y1]+1)) && (mat[xx1][yy1]<='Z'))
                            {
                                q.push(make_pair(xx1,yy1));
                                visit[xx1][yy1] = visit[x1][y1]+1;
                                max1 = max(visit[xx1][yy1],max1);
                            }
                        }
                    }

                }
            }
        }
    }
    printf("Case %d: %d\n",k,max1);k++;
    scanf("%d%d",&h,&w);
}
return 0;
}
