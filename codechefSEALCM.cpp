#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define nn 2000005

ll t,n,m,l,r;
struct mat{
    ll sz;
    ll a[(1<<5)][(1<<5)];
};

mat matexp(mat x, mat y){
    mat ret;
    ret.sz = x.sz;
    for(ll i = 0 ; i<(1<<x.sz) ; i++){
        for(ll j = 0;j<(1<<x.sz);j++){
            ret.a[i][j] = 0;
        }
    }
    for(ll i =0;i<(1<<x.sz);i++){
        for(ll j =0;j<(1<<x.sz);j++){
            for(ll k =0;k<(1<<x.sz);k++){
                ret.a[i][j] = ( ret.a[i][j] + x.a[i][k]*y.a[k][j] )%mod;
            }
        }
    }
    return ret;
}

mat modexp( mat x, ll b){
    mat res;
    res.sz = x.sz;
    for(ll i =0;i<(1<<x.sz);i++){
        for(ll j =0;j<(1<<x.sz);j++){
            res.a[i][j] = 0;
        }
    }
    for(ll i =0;i<(1<<x.sz);i++){
        res.a[i][i] = 1;
    }
    while(b){
        if(b&1){
            res = ( matexp(res,x) );
        }
        b = b>>1;
        x = matexp(x,x);
    }
    return res;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> l >> r;
        ll ans = 0;
        for(ll d = l; d<= r; d++){
            vector <ll> vec;
            ll temp = d;
            for(ll i =2; i <= sqrt(d); i++){
                if(temp % i == 0){
                    ll val = 1;
                    while((temp % i) == 0){
                        val *= i;
                        temp/=i;
                    }
                    vec.push_back(val);
                }
            }
            if(temp != 1){
                vec.push_back(temp);
            }

            mat x;
            x.sz = vec.size();
            for(ll i =0;i<(1<<x.sz);i++){
                for(ll j =0;j<(1<<x.sz);j++){
                    x.a[i][j] = 0;
                }
            }
            for(ll i =0;i<(1<<(vec.size()));i++){
                for(ll j = 0;j<(1<<vec.size());j++){
                    bool flg = 1;
                    for(ll bit = 0; bit < vec.size(); bit++){
                        if(((1<<bit)&i) and (!((1<<bit)&j))){
                            flg = 0;
                        }
                    }
                    if(!flg){
                        x.a[i][j] = 0;
                        continue;
                    }
                    for(ll k = 1; k <= m ; k++){
                        int flg = 1;

                        for( ll bit = 0; bit < vec.size(); bit++){
                            if((!((1<<bit)&i)) and ((1<<bit)&j)){
                                if( k %(vec[bit])) flg = 0;
                            }
                            else if((!((1<<bit)&i)) and (!((1<<bit)&j))){
                                if( k % vec[bit] == 0) flg = 0;
                            }
                        }
                        x.a[i][j] += flg;
                    }
                }
            }
            x = modexp(x,n);
            ans = ( ans + x.a[0][(1<<vec.size()) - 1])%mod;
        }
        cout << ans << "\n";
    }
}