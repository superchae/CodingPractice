#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int X[100+10];
int Y[100+10];

struct DATA{
    int s, e;
};

DATA arr[100+10];

void InputData(){
    cin >> N;
    int x, y;
    for (int i=0; i<N; i++){
        cin >> x >> y;
        arr[i] = {x, y};
    }
}

bool cmp(DATA a, DATA b){
    return a.e < b.e;
}

int Solve(){
    sort(arr, arr + N, cmp);
    int _end = arr[0].e;
    int cnt = 1;

    for(int i=1; i<N; i++){
        if(arr[i].s > _end){
            cnt++;
            _end = arr[i].e;
        }
    }
    return cnt;
}


int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}