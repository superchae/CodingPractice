#include <iostream>
#include <algorithm>
using namespace std;

int N, D, K, C;
int A[3000000+10];
int used[3000+10]{};

void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}

int Solve(){
    int cnt = 0;
    int flag = 0;
    int _max = 0;

    //used 초기화
    for(int i=0; i<K; i++){
        if(used[A[i]] == 0){
            used[A[i]]++;
            cnt++;
        }
        else{
            used[A[i]]++;
        }
    }
    if(used[C] == 0) flag = 1;
    _max = cnt + flag;
    
    //used 갱신
    int end_idx = 0;
    for(int i = 1; i < N; i++){
        flag = 0;
        if(--used[A[i - 1]] == 0) cnt--;

        end_idx = (i + K - 1) % N;
        if(used[A[end_idx]]++ == 0) cnt++;
        flag = used[C] == 0 ? 1 : 0;
        _max = max(_max, cnt + flag);
    }
    return _max;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}