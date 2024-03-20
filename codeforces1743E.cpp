#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<ll> dp (6001, 0);
ll get_time(ll h, vector<ll> p, vector<ll> t, vector<ll> c, ll s) {
if(h <= 0)
return 0;

ll both = max(t[0]-c[0], t[1]-c[1])+ ((h < p[0] + p[1] - s)? : dp[h-p[0]-p[1]+s]);
int first (t[1]-c[1]<t[0]-c[0]); ll delta = t[first]-c[first];
c[1-first] += delta;

c[first] = 0;

ll one = get_time(h-p[first] + s, p, t, c, s) + delta;

return min(one, both);
}
int main() {

ll p1, t1, p2, t2, h, s;
cin>>p1>>t1>>p2>>t2>>h>>s;

for (int i = 1; i <= h; i++)
{
    dp[i]= get_time(i, {p1, p2}, {t1, t2}, {0, 0}, s);

} 
cout << dp[h] << "\n";

}