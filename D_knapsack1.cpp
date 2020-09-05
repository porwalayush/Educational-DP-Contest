#include<bits/stdc++.h>
using namespace std;
# define int long long
int knapsack(int n,int w,int wt[],int v[])
{
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wt[i]<=j)
            {
                dp[i][j]=max(dp[i-1][j],v[i]+dp[i-1][j-wt[i]]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
  return dp[n][w];
}
int32_t main()
{
     #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    int t,w;
    cin>>t>>w;
    int wt[t+1],v[t+1];
    for(int i=1;i<=t;i++)
    {
        cin>>wt[i]>>v[i];
    }
    cout<<knapsack(t,w,wt,v);
    return 0;
}