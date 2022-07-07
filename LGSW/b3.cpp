#include <iostream>
#include <algorithm>
using namespace std;

int N;
struct DATA{
    int s, e;
};
DATA arr[10000+10];
int present = 0;
int absent = 0;

void InputData(void){
    cin >> N;
    int s, e;
    for (int i=0; i<N; i++){
        cin >> s >> e;
        arr[i] = {s, e};
    }
}

bool cmp(DATA a, DATA b){
    return a.s < b.s;
}

void Solve(){
    sort(arr, arr + N, cmp);

    int start, end;
    start = arr[0].s;
    end = arr[0].e;

    for(int i=1; i<N; i++){
        if(arr[i].s <= end){
            end = max(end, arr[i].e);
        }
        else{
            present = max(present, end - start);
            absent = max(absent, arr[i].s - end);
            start = arr[i].s;
            end = arr[i].e;
        }
    }
    present = max(present, end - start);
}

int main(void){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    Solve();

    cout << present << " " << absent << endl;// 출력하는 부분
    return 0;
}