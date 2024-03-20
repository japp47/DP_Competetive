#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[2005][2005][8];
ll n , m, a[2005],b[2005];

ll solve(ll i, ll j, ll k){
    if(i==n||j==m) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    ll res=0;
    if(a[i]==b[j]){
        res = 1+solve(i+1,j+1,k);
    }
    else{
        if(k>0){
            res = 1+solve(i+1,j+1,k-1);
        }
        res = max(res, solve(i+1,j,k));
        res = max(res, solve(i,j+1,k));

   
    }
    return dp[i][j][k]=res;
}
int main(){
    memset(dp,-1, sizeof(dp));
    ll k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    ll ans = solve(0,0,k);
    cout<<ans<<endl;

    return 0;

}