#include <bits/stdc++.h>
using namespace std;
#define int long long
# define mod 1000000007
int32_t main() {
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
    #endif
    

    int n,k;
    cin>>n>>k;
    int v[n+1];
    for(int i=1;i<n+1;i++)
    {
        cin>>v[i];
    }
    int dp[n+2][k+2];
    for(int i=0;i<=k;i++)
    {
        dp[1][i]= (i>v[1])?0:1;
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]= (mod+ dp[i][j-1] + dp[i-1][j] - (((j-v[i]-1)>=0)?dp[i-1][j-1-v[i]]:0))%mod;
        }
    }
    cout<<dp[n][k];
    return 0;
}
