#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,k,i;
    scanf("%d",&t);
    for(k = 0;k<t;k++)
    {
        int N; int C;
        scanf("%d%d",&N,&C);
        int arr[N];
        for(i = 0;i<N;i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr, arr+N);
        int left = 0; int right = (arr[N-1]-arr[0])+1;int mid = 0; int flag = 0; int count = 1;
        while(left<right-1)
        {
            mid = (left+right)/2; flag = 0; count = 1;
             int last_pos = arr[0];
            for(i = 1;i<N;i++)
            {
                if((arr[i]-last_pos)>=mid)
                {
                    if(++count == C)
                    {   flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                    last_pos = arr[i];
                }
            }
            ((flag == 1)?left:right) = mid;
    }
    printf("%d\n",left);
}
return 0;
}
