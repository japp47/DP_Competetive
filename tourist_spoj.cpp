#include <bits/stdc++.h>
using namespace std;

#define ll int
#define nn 200005
ll n, m;
ll dx1[4] = {1,1,0,0};
ll dy1[4] = {0,0,1,1};
ll dx2[4] = {1,0,1,0};
ll dy2[4] = {0,1,0,1};

ll dp[105][105][105];
char c[105][105];

ll solve(ll x1, ll y1, ll x2, ll y2){
    if(x1>n or y1>m or x2>n or y2>m or c[x1][y1] == '#' or c[x2][y2] == '#') return INT_MIN;
    if(x1==n and y1==m) return (c[x1][y1]=='*');
    if(dp[x1][y1][x2] != -1) return dp[x1][y1][x2];
    ll res = INT_MIN;
    for(ll i=0; i<4;i++){
        res=max(res, solve(x1+dx1[i], y1+dy1[i], x2+dx2[i], y2+dy2[i]));
    }
    res += (c[x1][y1] == '*');
    res += (c[x2][y2] == '*');
    if(x1==x2 and y1==y2 and c[x1][y1] == '*') res--;
    return dp[x1][y1][x2] = res;    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin>>m>>n;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        cout<<solve(1,1,1,1)<<"\n";
    }
}