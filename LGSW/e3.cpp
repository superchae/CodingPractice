#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int s[100+10];
int e[100+10];
int in[10+10];
int num[10+10];
void InputData(){
    cin >> N >> M;
    for (int i=0; i<M; i++){
        cin >> s[i] >> e[i];
    }
    for (int i=1; i<=N; i++){
        cin >> in[i];
    }
}
void OutputData(){
    for (int i=1; i<=N; i++){
        cout << num[i] << " ";
    }
    cout << endl;
}

bool cmp(int a, int b){
    if(a > b) return true;
    return false;
}

bool isPossible(){

}

int DFS(int depth){
    if(depth >= N){
        return 1;
    }
    num[depth] = in[i]

}

void Solve(){
    sort(in + 1, in + N + 1, cmp);
    num[1] = in[1];
    DFS(2);
}

int main(){
    InputData();//입력받는 부분

    // 여기서부터 작성
    Solve();

    OutputData();// 출력하는 부분
    return 0;
}