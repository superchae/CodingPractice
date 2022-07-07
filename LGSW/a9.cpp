#include <iostream>
#include <algorithm>
using namespace std;

int K;
int A[6+10];
int B[6+10];
int g_max = 0, g_maxidx = -1;
int s_max = 0, s_maxidx = -1;

void InputData(){
    cin >> K;
    for (int i=0 ; i<6 ; i++){
        cin >> A[i] >> B[i];
        if (A[i] == 1 || A[i] == 2){
            if(B[i] > g_max){
                g_max = B[i];
                g_maxidx = i;
            }
        }
        else {
            if(B[i] > s_max){
                s_max = B[i];
                s_maxidx = i;
            }
        }
    }
}

int Solve(){
    int _sum = B[g_maxidx] * B[s_maxidx];
    //최대 idx와 붙어있지 않는애 찾기
    int g_minidx = (g_maxidx + 3) % 6;

    int s_minidx = (s_maxidx + 3) % 6;

    _sum -= B[g_minidx] * B[s_minidx];

    return _sum * K;
}

int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}