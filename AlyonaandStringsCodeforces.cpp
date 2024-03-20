#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
ll n, m, k;
ll dp[ 1005][1005][12][2];
ll solve(ll is, ll it, ll rem, ll cont){
    if(is == n || it == m){
        return ((rem ==0)?0:INT_MIN);
    }
    if(rem == 0) return 0;
    if(dp[is][it][rem][cont] != -1){
        return dp[is][it][rem][cont];
    }
    ll res = INT_MIN;
    res = max(res, solve(is+1,it,rem-cont,0));
    res = max(res, solve(is,it+1,rem-cont,0));
    if(s[is]==t[it]){
        res = max(res, 1+solve(is+1,it+1,rem,1));
        res = max(res, 1 + solve(is+1,it+1,rem-1,0));
    
    }
    return dp[is][it][rem][cont] = res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n>> m>>k;
    cin>>s>>t;
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0,k,0);
}