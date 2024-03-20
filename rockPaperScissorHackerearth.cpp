#include <bits/stdc++.h>
using namespace std;
#define ll double
double dp[105][105][105];
void set_dp(){
    for(int i =0;i<102;i++){
        for(int j=0;j<102;j++){
            for(int k = 0;k<102;k++){
                dp[i][j][k] = -1.0;
            }
        }
    }
}
double f1(int r, int p, int s){            //rock last survivor
    if(r==0||s==0) return 0.0;
    if(p==0) return 1.0;
    if(dp[r][p][s]!=-1) return dp[r][p][s];
    double total = r*s+p*s+r*p;
    double res = 0.0;
    res += f1(r-1,p,s)*((r*p)/total);
    res += f1(r,p-1,s)*((s*p)/total);
    res += f1(r,p,s-1)*((r*s)/total);
return dp[r][p][s] = res;
}
double f2(int r, int p, int s){            //scissor last survivor
    if(p==0||s==0) return 0.0;
    if(r==0) return 1.0;
    if(dp[r][p][s]!=-1) return dp[r][p][s];
    double total = r*s+p*s+r*p;
    double res = 0.0;
    res += f2(r-1,p,s)*((r*p)/total);
    res += f2(r,p-1,s)*((s*p)/total);
    res += f2(r,p,s-1)*((r*s)/total);
return dp[r][p][s] = res;
}
double f3(int r, int p, int s){            //paperr last survivor
    if(r==0||p==0) return 0.0;
    if(s==0) return 1.0;
    if(dp[r][p][s]!=-1) return dp[r][p][s];
    double total = r*s+p*s+r*p;
    double res = 0.0;
    res += f3(r-1,p,s)*((r*p)/total);
    res += f3(r,p-1,s)*((s*p)/total);
    res += f3(r,p,s-1)*((r*s)/total);
return dp[r][p][s] = res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int r,s,p;
        cin>>r>>s>>p;
        set_dp();
        double ans1=f1(r,p,s);
        set_dp();
        double ans2=f2(r,p,s);
       set_dp();
        double ans3=f3(r,p,s);

        cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }
    return 0;
}
