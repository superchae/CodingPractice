#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
double D[10000+10];
double dp[10000+10];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> D[i];
    }
}

double Solve(){
    dp[0] = D[0];
    for(int i=1; i<N; i++){
        dp[i] = max(dp[i-1]*D[i], D[i]);
    }
    
    double _max = 0;
    for(int i=0; i<N; i++){
        _max = max(_max, dp[i]);
    }
    return _max;
}

int main(){
    double ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    printf("%.3lf\n", ans);// 출력하는 부분
    return 0;
}