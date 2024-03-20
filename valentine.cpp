#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define INF 10000000000099ll
#define ll long long

ll n,m,a[5005],b[5005], dp[5005][5005];
ll f(ll i, ll j){
    if(i==n) {return 0;}
    if(j==m) {return INF;}
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int op1 = abs(a[i]-b[j]) + f(i+1,j+1);
    int op2 = f(i,j+1);
    return dp[i][j] = min(op1,op2);
}
int main(){
    memset(dp, -1, sizeof (dp));
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);

    ll ans = f(0,0);
    cout<<ans<<endl;
    return 0;
}
