#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int s[100+10];
int e[100+10];
int in[10+10];
int num[10+10];
int arr[10+10][10+10];

struct IO{
    int in, out;
} cnt[10+10];

struct QUE{
    int num, out;
};

struct cmp{
    bool operator()(QUE a, QUE b){
        return a.out < b.out;
    }
};

priority_queue<QUE, vector<QUE>, cmp> pq;

void InputData(){
    cin >> N >> M;
    for (int i=0; i<M; i++){
        cin >> s[i] >> e[i];
        cnt[e[i]].in += 1;
        cnt[s[i]].out += 1;
        arr[s[i]][e[i]] = 1;
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
void Solve(){
    pq.push({1, cnt[1].out});
    
    while(!pq.empty()){
        QUE boss = pq.top(); pq.pop();
        cout << boss.num << endl;
        for(int i=2; i<=N; i++){
            if(arr[boss.num][i] == 0) continue;        
            cnt[boss.num].out--;
            cnt[i].in--;
            if(cnt[i].in == 0){
                pq.push({i, cnt[i].out});
            }
        }
    }
}
int main(){
    InputData();//입력받는 부분

    // 여기서부터 작성
    Solve();

    OutputData();// 출력하는 부분
    return 0;
}