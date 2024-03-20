#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i = a;i<=b;i++)
int arr[1000];
ll dp[1000][1000];
ll sum(int s, int e){
    ll ans = 0;
    rep(y,s,e){
        ans+=arr[y];
        ans%=100;
    }
    return ans;
}
ll solveMixtures(int i, int j){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=INT_MAX;
    for(int k = i;k<=j;k++){
        dp[i][j] = min(dp[i][j], solveMixtures(i,k)+ solveMixtures(k+1,j) + sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
}
int main(){
    int n;
    while((scanf("%d",&n))!=EOF){
        rep(i,0,n-1) cin>>arr[i];
        rep(i,0,n-1){
            rep(j,0,n-1){
                dp[i][j]=-1;
            }
        }
        cout<<solveMixtures(0,n-1)<<endl;
    }
}