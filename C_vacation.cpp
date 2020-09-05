#include<bits/stdc++.h>
using namespace std;
# define int long long
int dp[100005][3];
int a[100005][3];
int fun(int n)
{
  dp[1][0]=a[0][0];
  dp[1][1]=a[0][1];
  dp[1][2]=a[0][2];
  for(int i=2;i<=n;i++)
  {
     dp[i][0]=a[i-1][0]+max(dp[i-1][1],dp[i-1][2]);
     dp[i][1]=a[i-1][1]+max(dp[i-1][0],dp[i-1][2]);
     dp[i][2]=a[i-1][2]+max(dp[i-1][0],dp[i-1][1]);
  }
  return max(dp[n][0],max(dp[n][1],dp[n][2]));
}
int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<3;j++)
    {
        cin>>a[i][j];
    }
  }
  cout<<fun(n)<<endl;
    return 0;
}