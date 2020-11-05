// recurrence analysing we get   A[k]=A[k-1]*adjacancymatrix and A[1]=ADJACANCY MATRIX
// so can say that  ans= pow(adjacancymatrix, k)
// we use matrix exponentiation for that
#include <bits/stdc++.h>
using namespace std;
#define int long long
# define mod 1000000007

int k;

vector<vector<int> > multiply(vector<vector<int> > a1,vector<vector<int> > b1)
{
    vector<vector<int> > c1(k+1, vector<int>(k+1));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int x=1;x<=k;x++)
            {
                c1[i][j]=(c1[i][j]+(a1[i][x]*b1[x][j])%mod)%mod;
            }
        }
    }
    return c1;
}

vector<vector<int> > pow(vector<vector<int> > T, int p)
{
    if(p==1)
        return T;
    if(p&1)
        return (multiply(T,pow(T,p-1)));
    vector<vector<int> > X=pow(T,p/2);
    return multiply(X,X);
}
int calc(vector<vector<int> > T, int path,int n)
{
    vector<vector<int> > res=pow(T,path);
    int ans=0;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++)
            ans=(ans+res[i][j])%mod;
    return ans;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
    #endif
    int n,path;
    cin>>n>>path;
    k=n;
    vector<vector<int> > T(n+1,vector<int> (n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            T[i][j]=x;
        }
    }


    cout<<calc(T,path,n);
    
    return 0;
}
