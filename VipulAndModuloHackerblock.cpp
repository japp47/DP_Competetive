#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nn 200005
ll dp[(1<<19)+1][101];
string s;
ll MOD;
ll solve(ll mask, ll m){
    if(mask == (1<<s.size())-1){
        return (m==0);
    }
    if(dp[mask][m]==-1){
        return dp[mask][m];
    }
    ll ans = 0;
    bool ch[10];
    memset(ch,0,sizeof(ch));
    for(ll i=0; i <s.size();i++){
        if(s[i]=='0'){
            if(mask==0){
                continue;
            }
        }
        if((!(mask&(1<<i))) and (!ch[s[i]-'0'])){
            ans = (ans+solve(mask|(1<<i), (m*10+(s[i]='0'))%MOD));
            ch[s[i]-'0']=1;
        }
    }
    return dp[mask][m] = ans;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        string s;
        cin>>s;
        cin>>MOD;
        cout<<solve(0,0)<<endl;;

    }
}