#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define N 300010
#define mod 1000000007
ll n, q;
int arr[N];
ll dp[25][25];
ll mindist[N][25];
int main(){
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
        cin >> arr[i];
    for( ll i = 0;i<=20;i++){
        for(ll j=0;j<=20;j++){
            if(i!=j)
                dp[i][j] = INT_MAX;
         }
    }
    for( ll i =n;i>=1;i--){
        vector<int> zeros,ones;
        for(ll j = 0;j<=20;j++){
            if((1<<j)&arr[i]){
                mindist[i][j]=0;
                ones.push_back(j);
                for(ll k=0;k<=20;k++){
                    if((1<<k)&arr[i]){
                        dp[j][k] = 0;
                    }
                }
            }
            else{
                zeros.push_back(j);
            }
        }
        for(auto it0: zeros){
            ll mi = INT_MAX;
            for(auto it1: ones){
                mi = min(mi, dp[it1][it0]);
            }
            for(auto it1: ones){
                dp[it1][it0]=mi;
            }
            mindist[i][it0] = mi;
        }
        for(ll j = 0;j<=20;j++){
            for(ll k =0; k<=20;k++){
                if(j!=k)
                    dp[j][k]++;
            }
        }
    }
    while (q--){
        ll x,y;
        cin>>x>>y;
        ll mi = INT_MAX;
        for(ll j =0;j<=20;j++){
            if(arr[y]&(1<<j)){
                mi = min(mi,mindist[x][j]);
            }
        }
        if(mi<=y-x){
            cout<<"Shi\n";
        }
        else{
            cout<<"Fou\n";
        }
    }
}