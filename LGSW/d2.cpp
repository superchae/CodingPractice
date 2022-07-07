#include <iostream>
using namespace std;
#define MAXN (20)
int N, B;
int H[MAXN + 10];
void InputData(){
    cin >> N >> B;
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
}

int sol = 2e9;
void Solve(int s, int res, int depth, int max_depth){
    if(depth == max_depth){
        // cout << depth << ' ' << res << endl;
        if(res >= B) sol = min(sol, res - B);
        return;
    }
    for(int i = s; i<N; i++){
        Solve(i + 1, res + H[i], depth + 1, max_depth);
    }
}

int main(){
    int T, ans = -1;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분
        
        //여기서부터 작성
        sol = 2e9;
        for(int i=1; i<=N; i++){
            Solve(0, 0, 0, i);
        }
        ans = sol;

        cout << ans << endl;
    }
    return 0;
}
