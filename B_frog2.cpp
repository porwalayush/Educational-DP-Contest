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
int dp[200005];
int a[200005];
int k;
int abc(int n)
{
    dp[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;i++)
    {
        int g=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
             g=min(g,dp[i-j]+abs(a[i-j]-a[i]));
            }
        }
        dp[i]=g;
    }
    return dp[n-1];
}
void solve()
{
  int n;
  cin>>n;
  cin>>k;
  f(i,0,n)
  cin>>a[i];
  memset(dp,0,sizeof(dp));
  cout<<abc(n)<<endl;
}
int32_t main()
{
    io();
    solve();
    return 0;
}