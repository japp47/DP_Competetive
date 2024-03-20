#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int i=0;i<=m;i++)
        dp[0][i]=i;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i+1][j+1]=dp[i][j];
            }
            else
                dp[i+1][j+1]=min(dp[i+1][j],min(dp[i][j+1],dp[i][j]))+1;
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}