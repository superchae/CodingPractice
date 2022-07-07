#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN (100)
int L;//정비를 받지 않고 갈수있는 최대거리
int N;//정비소 개수
int dist[MAXN+10];//정비소사이거리
int times[MAXN+10];//정비시간
int visit[MAXN+10];
int pre[MAXN+10];

void InputData(){
    cin >> L;
    cin >> N;
    for (int i=1; i<=N+1; i++){
        cin >> dist[i];
    }
    for (int i=1; i<=N; i++){
        cin >> times[i];
    }
}
void PRE(int n, int cnt){
    if(pre[n] == 0) {
        cout << cnt << endl;
        return;
    }
    PRE(pre[n], cnt + 1);
    cout << pre[n] << ' ';
}
void Solve(){
    fill(&visit[0], &visit[MAXN+10], 2e9);  // 시작점으로부터 최소 정비시간
    queue<int> q;
    q.push(0);
    visit[0] = 0;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        int move = 0;
        for(int i = cur + 1; i <= N + 1; i++){
            if(move + dist[i] > L) break;
            move += dist[i];
            if(visit[i] <= visit[cur] + times[i]) continue;
            q.push(i);
            visit[i] = visit[cur] + times[i];
            pre[i] = cur;
            // cout << cur << ' ' << i << ' ' << visit[i] << ' ' << move << endl;
        }
    }
    cout << visit[N + 1] << endl;
    if(visit[N + 1] > 0){
        PRE(N + 1, 0);
        cout << endl;
    }
}

int main(){
    InputData();//입력 받는 부분

    //여기서부터 작성
    Solve();

    return 0;
}