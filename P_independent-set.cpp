#include <bits/stdc++.h>
using namespace std;
#define int long long
# define mod 1000000007
int dp[100005][2];
vector<int> gr[100005];
int dfs(int cur,int cnst,int par)
{
    int ans=0;
    int w1=1;
    if(dp[cur][cnst]!=-1)
        return dp[cur][cnst];
    for(auto it: gr[cur])
    {
        if(it!=par)
        {
            int vl=dfs(it,0,cur);
            w1=(w1*vl)%mod;
        }
    }
    ans=ans+w1;
    if(cnst!=1)
    {
        int w2=1;
        for(auto it: gr[cur])
        {
            if(it!=par)
            {
                int v2=dfs(it,1,cur);
                w2=(w2*v2)%mod;
            }
        }
        ans=(ans+w2)%mod;
    }
    dp[cur][cnst]=ans;
    return ans;
}
int32_t main() {
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
    #endif

  memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    cout<<dfs(1,0,-1);
    return 0;
}
