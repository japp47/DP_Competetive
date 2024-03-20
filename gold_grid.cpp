#include<bits/stdc++.h>
using namespace std;
int N,M,i,j;
int dp[1000][1000];
int Gold[1000][1000];
int ans=0;

int maxGoldCoin(int n)
{
dp[0][0]=Gold[0][0]; 

for(int i=1;i<n;i++)
{
	dp[i][0]=dp[i-1][0]+Gold[i][0];

}

for(int j=1;j<n;j++)
{
	dp[0][j]=dp[0][j-1]+Gold[0][j];
}

for(int i=1;i<n;i++)
{
    for(int j=1;j<n;j++)
    {
        if(Gold[i][j]==1)
        dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+1;
        else
        {
       dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+0;
        }
        
    }
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{

        int op1=dp[i][j];
        int op2=dp[i][n-1]-dp[i][j];
        int op3=dp[n-1][j]-dp[i][j];
        int op4=dp[n-1][n-1]-(op1+op2+op3);
        ans=max(ans,min(min(min(op1,op2),op3),op4));;
    }
}

return ans;
}

int main()
{

memset(dp,0,sizeof(dp));
memset(Gold,0,sizeof(Gold));
cin>>N>>M;
while(M--)
{
 cin>>i>>j;
 Gold[i-1][j-1]=1;     
}
cout<<maxGoldCoin(N);
return 0;
}