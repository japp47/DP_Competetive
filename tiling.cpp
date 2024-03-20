#include <bits/stdc++.h>
using namespace std;

int tiling(int n, int m){
    int dp[n+1]= {0};
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1];
        if(i-m>=0){
            dp[i]+=dp[i-m];
        }
        dp[i] = dp[i];
    }
    return dp[n];
    
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<tiling(n,m);
}