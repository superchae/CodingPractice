#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
int W[20];
void InputData(){
    cin >> N;
    for (int i=0 ; i<N ; i++){
        cin >> W[i];
    }
}

bool isUp(int a, int b){
    while(1){
        if(a == 0 || b == 0) break;
        if(a % 10 + b % 10 >= 10) return true;
        a /= 10;
        b /= 10;
    }
    return false;
}

int sol = 0;
void Solve(int s, int cnt, int sum){
    sol = max(sol, cnt);
    
    if(s == N) return;

    for(int i=s; i<N; i++){
        if(isUp(sum, W[i])) continue;
        Solve(i + 1, cnt + 1, sum + W[i]);
    }
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    Solve(0, 0, 0);
    ans = sol;

    cout << ans << endl;//출력하는 부분
    return 0;
}