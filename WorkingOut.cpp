#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

const int NN = 1005;

long long boy_start[NN][NN];
long long boy_end[NN][NN];
long long girl_start[NN][NN];
long long girl_end[NN][NN];
long long calorie[NN][NN];

long long maxCalorie(int M, int N){
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            boy_start[i][j] = calorie[i][j] + max(boy_start[i-1][j],boy_start[i][j-1]);
        }
    }
    for(int i=M;i>=1;i--){
        for(int j=1;j<=N;j++){
            girl_start[i][j] = calorie[i][j] + max(girl_start[i+1][j],girl_start[i][j-1]);
        }
    }
    for(int i=M;i>=1;i--){
        for(int j=N;j>=1;j--){
            boy_end[i][j] = calorie[i][j] + max(boy_end[i+1][j],boy_end[i][j+1]);
        }
    }
    for(int i=1;i<=M;i++){
        for(int j=N;j>=N;j--){
            girl_end[i][j] = calorie[i][j] + max(girl_end[i-1][j],girl_end[i][j+1]);
        }
    }

    long long ans = 0;

    for(int i=2; i< M;i++){
        for(int j=2;j<N;j++){
            long long op1= boy_start[i-1][j] + girl_start[i][j-1] + boy_end[i+1][j] + girl_end[i][j+1];
            long long op2= boy_start[i][j-1] + girl_start[i+1][j] + boy_end[i][j+1] + girl_end[i-1][j];

            ans= max(ans, max(op1,op2));

        }
    }
    return ans;
}

int main(){
    memset(boy_start, 0, sizeof boy_start);
    memset(girl_start, 0, sizeof girl_start);
    memset(boy_end, 0, sizeof boy_end);
    memset(girl_end, 0, sizeof girl_end);
    memset(calorie, 0, sizeof calorie);

    int M, N;
    cin>>M>>N;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> calorie[i][j];
        }
    }

    long long result = maxCalorie(M, N);
    cout << result << endl;

    return 0;
}
