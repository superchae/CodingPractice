#include <iostream>
#include <algorithm>
using namespace std;

int N, C, M;

struct DATA{
    int s, e, num;
};
DATA arr[10000+10];

void InputData(){
    cin >> N >> C;
    cin >> M;
    int s, e, num;
    for (int i=0; i<M; i++){
        cin >> s >> e >> num;
        arr[i] = {s, e, num};
    }
}

bool cmp(DATA a, DATA b){
    return a.e < b.e;
}

int Solve(){
    int cap[2000+10]{0, };
    int sol = 0;

    sort(arr, arr + M, cmp);

    for(int i=0; i<M; i++){
        int _max = 0;
        for(int j = arr[i].s; j < arr[i].e; j++){
            _max = max(cap[j], _max);
        }
        int tmp = C - _max > arr[i].num ? arr[i].num : C - _max;   
        sol += tmp;

        for(int j = arr[i].s; j < arr[i].e; j++){
            cap[j] += tmp;
        }
    }
    return sol;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}