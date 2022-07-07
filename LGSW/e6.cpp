#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
int N;
int X[MAXN + 10];
int Y[MAXN + 10];
void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> X[i] >> Y[i];
    }
}

int sum[MAXN + 10]{};
int sol = 2e9;
int Solve(){
    sum[1] = 0;
    for(int i=2; i<=N; i++){
        sum[i] = sum[i - 1] + abs(Y[i] - Y[i-1]) + abs(X[i] - X[i-1]);
    }
    for(int i=2; i < N; i++){
        sol = min(sol, sum[i - 1] + (sum[N] - sum[i + 1]) + abs(Y[i + 1] - Y[i - 1]) + abs(X[i + 1] - X[i - 1]));
    }
    return sol;
}
int main(){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 작성
    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}
