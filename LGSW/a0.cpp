#include <iostream>

using namespace std;
#define MAXN (100)
int K;//처음 폭탄을 가진 사람 번호
int N;//퀴즈 개수
int T[MAXN+10];//걸린 시간
char Z[MAXN+10];//정답 여부
int total = 0;
int ans;

void InputData(){
    cin >> K;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> Z[i];
    }
}
int Solve(){
    int cur = K;
    int tmp = 0;
    for(int i = 0; i<N; i++){
        cur = cur % 8;
        if(cur == 0) cur = 8; 
        total += T[i];
        // cout << cur << ' ' << total << endl;
        if(total >= 210){
            return cur;
        }
        if(Z[i] == 'T'){
            cur++;
        }
    }
    return cur;
}

int main(){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}