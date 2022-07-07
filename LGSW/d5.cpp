#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (100)
int A;
int N;
int W[MAXN+10];
void InputData(){
    cin >> A >> N;  // 유저 물방울 크기, 물방울 개수
    for (int i=0; i<N; i++){
        cin >> W[i];
    }
}

int ans; //최대점수, 최저skill수
void Solve(int s, int depth, int sum, int skill){
    if(skill >= ans) return;
    if(depth == N){
        ans = min(ans, skill);
        return;
    }
    if(sum > W[s]) Solve(s + 1, depth + 1, sum + W[s], skill);
    else{
        if(sum > 1) Solve(s, depth, sum + sum - 1, skill + 1);  // 새로 생성
        Solve(s + 1, depth + 1, sum, skill + 1); // 없애기
    }
    

}

int main(){
    int t, T;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        sort(W, W + N);

        ans = N;
        Solve(0, 0, A, 0); // s, depth, sum, skill

        cout << "Case #" << t << ": " << ans << endl;//출력하는 부분
    }
    return 0;
}