#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define N 300005
#define mod 1000000007
ll n, q;
ll arr[N];
vector<vector <pair<ll,ll>>> queries(N);
ll fans[N];
int main(){
    cin>>n>>q;
    for(ll i = 1; i<=n; i++) {
        cin>>arr[i];
    }
    for(ll i=1;i<=q;i++){
        ll l,x;
        cin>>l>>x;
        queries[l].push_back({x,i});
    }
    set<ll> s;
    s.insert(0);
    ll ans = 1;
    for(ll i =1;i<=n;i++){

        if(s.find(arr[i])!=s.end()) 
            ans = (ans*2)%mod;
        else
        {
            vector<ll> temp;
            for(auto x: s){
                temp.push_back(x^arr[i]);
            }
            for(auto it: temp){
                s.insert(it);
            }
        }
        for(auto it: queries[i]){
            if(s.find(it.first)!=s.end()) 
                fans[it.second] = ans;
            else{
                fans[it.second] = 0;
            }
        }
    }
    for(ll i =1;i<=q;i++){     
        cout<<fans[i]<<endl;
    }
}
        

    
