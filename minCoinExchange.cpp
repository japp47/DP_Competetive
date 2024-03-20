#include <bits/stdc++.h>
#include <climits>
using namespace std;

int minCoins(int n, int coins[], int T, int dp[]){ // top bottom
    if(n==0) return 0;
    if(dp[n]!=0) {return dp[n];}

    int ans = INT_MAX;
    for(int i=0;i<T;i++){
        if(n-coins[i]>=0){
            int subProb = minCoins(n-coins[i], coins, T, dp) + 1;
            ans= min(ans, subProb);
}
}
dp[n] = ans;
return dp[n];
}

int minCoinsBU(int N, int coins[], int T){
    int dp[100] = {0};
    for(int n=1;n<=N;n++){
        dp[n] = INT_MAX;
        for(int i=0;i<T;i++){
            if(n-coins[i]>=0){
                int subprob = dp[n-coins[i]] + 1;
                dp[n] = min(dp[n],subprob);
            }
        }
    }
    return dp[N];

} 

int main(){
    int N = 15;
    int coins[] = {1,7,10};
    int dp[100]={0};
    
    int T= sizeof(coins)/ sizeof(int);
    cout<<minCoinsBU(N, coins, T)<<endl;
    return 0;
}