#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define endl ("\n")
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,s,n)        for(int i=s;i<n;i++)
int si= 2000005;
void io()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int dp[1005][1005];
char a[1005][1005];
int fun(int n,int m)
{
    if(dp[0][0]==-1)
        return 0;
    for(int i=0;i<m;i++)
    {
        if(dp[0][i]==-1)
            break;
        dp[0][i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(dp[i][0]==-1)
            break;
        dp[i][0]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(dp[i][j]==-1)
                continue;
            if(dp[i-1][j]!=-1)
                dp[i][j]=(dp[i][j]+dp[i-1][j])%1000000007;
            if(dp[i][j-1]!=-1)
                dp[i][j]=(dp[i][j]+dp[i][j-1])%1000000007;
        }
    }
    if(dp[n-1][m-1]==-1)
        return 0;
    return dp[n-1][m-1];
}
void solve()
{
    int n,m;
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='#')
            {
                dp[i][j]=-1;
            }                
        }
    }
    cout<<fun(n,m)<<endl;
}
int32_t main()
{
    io();
    solve();
    return 0;
}