#include<bits/stdc++.h>
using namespace std;
int  dp[3005][3005];  //globally declare so that we can use this in any where
int topdownlcs(string s1,string s2,int n ,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                int v1= dp[i-1][j];
                int v2= dp[i][j-1];
                dp[i][j]=max(v1,v2);
            }
        }
    }
    return dp[n][m];
}

void printlcs(string s1,string s2,int n,int m)
{
    string ans;
     int i=n,j=m;
     while(i>0 && j>0)
     {
        if(s1[i-1]==s2[j-1])
        {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
               j--;
            }
        }
     }
     reverse(ans.begin(),ans.end()); //for reversing the result 
     cout<<ans<<endl;
}

int main()
{
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  

    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    memset(dp,0,sizeof(dp)); // for implement topdown approach
    topdownlcs(s1,s2,n,m);
    printlcs(s1,s2,n,m);
    return 0;
}