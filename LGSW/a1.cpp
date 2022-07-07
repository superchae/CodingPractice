#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e3)
int N;//정수개수
int A[MAXN + 10];//입력 정수
int _max = 0, ans = 1e7;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}

void Solve(int num){
    string tmp = to_string(num);
    int ret;
    while(tmp.size() > 1){
        ret = 0;
        for(int i=0; i<tmp.size(); i++){
            ret += tmp[i] - '0';
        }
        tmp = to_string(ret);
    }
    if(ret > _max){
        _max = ret;
        ans = num;
    }
}

int main(){
    InputData();//입력 받는 부분

    //여기서부터 작성
    sort(A, A + N);
    for(int i=0; i<N; i++){
        Solve(A[i]);
    }
    cout << ans << endl;//출력하는 부분
    return 0;
}