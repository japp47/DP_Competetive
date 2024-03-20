#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1001][1001];

int numWays(int R, int C){
    if(dp[0][0] == -1){
        return 0;
    }

    for(int i=0;i<C;i++){
        if(dp[0][i] ==-1){
            break;
        }
        dp[0][i]=1;
    }
     for(int i=0;i<R;i++){
        if(dp[i][0] ==-1){
            break;
        }
        dp[i][0]=1;
    }

    for(int i=1; i<R;i++){
        for(int j=1;j<C;j++){
            if(dp[i][j]==-1){
                continue;
            }
            dp[i][j]=0;

            if(dp[i][j-1]!=-1){
                dp[i][j] = dp[i][j-1]%MOD;
            }
            if(dp[i-1][j]!=-1){
                dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
            }
        }
    }
    if(dp[R-1][C-1] ==-1){
        return 0;
    }
    return dp[R-1][C-1];
}

int main(){
    memset(dp,0,sizeof dp);

    int M,N,P;
    cin>>M>>N>>P;
    for(int i=0;i<P;i++){
        int x,y;
        cin>>x>>y;
        dp[x-1][y-1] = -1;
    }
    cout<<numWays(M,N)<<endl;

    return 0;
}
