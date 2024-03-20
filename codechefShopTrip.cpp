#include <bits/stdc++.h>
using namespace std;

#define N 50

long double distance (pair<int, int> p1, pair<int, int>p2){

    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}

long double dist[N][N] = {0};
long double dp[1<<13][N];

int n,k;
vector<pair<int,int> > coordinates;
vector<int> ingredients;

long double shopTrip(int mask, int idx){
    if(mask == ((1<<k)-1) && idx==0){
        return 0;
    }

    if(dp[mask][idx]!=-1){
        return dp[mask][idx];
    }
    dp[mask][idx] = INT_MAX;

    for(int i = 0; i<=n;i++){
        if((mask|ingredients[i])!=mask || (i==0)){
            dp[mask][idx] = min(dp[mask][idx], dist[idx][i] + shopTrip(mask|ingredients[i], i));
        }

    }
    return dp[mask][idx];
}

int main(){
    int t;
    int x,y;
    string temp;
    cin>>t;
    while(t--){
        cin>>n>>k;
        coordinates.clear();
        ingredients.clear();

        coordinates.push_back(make_pair(0,0));

        for(int i=0;i<n;i++){
            cin>>x>>y;
            coordinates.push_back(make_pair(x,y));
        }
        ingredients.push_back(0);
        int possible = 0;

        for(int i=0; i<n; i++){
            cin>>temp;
            reverse(temp.begin(), temp.end());
            int temp_mask = 0;
            for(int j=0; j<temp.length(); j++){
                temp_mask |= ((1<<j)*(temp[j]-'0'));
            }
            possible|=temp_mask;
            ingredients.push_back(temp_mask);
        }
        int all = ((1<<k)-1);
        if(possible!=all){
            cout<<"-1"<<endl;
            continue;
        }

        memset(dist,0, sizeof(dist));

        for(int i = 0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dist[i][j] = distance(coordinates[i], coordinates[j]);
            }
        }

        for(int i=0;i<(1<<k); i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        long double ans = shopTrip(0,0);
        cout<<fixed <<setprecision(9)<<ans<<endl;
    }
    return 0;
}

