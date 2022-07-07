#include <iostream>
#include <queue>
using namespace std;

int S, E;//출발 정류장 번호, 도착 정류장 번호

void InputData(){
    cin >> S >> E;
}
bool isPossible(int src, int dst){
    int diff = 0;
    for(int i=0; i<4; i++){
        diff += (src % 10) != (dst % 10) ? 1 : 0;
        src /= 10;
        dst /= 10;
    }
    if(diff == 1) return true;
    return false;
}

bool isPrime(int num){
    for(int i = 2; i*i<=num; i++){
        if(num % i == 0) return false;
    }
    return true;
}
struct QUE{
    int val, time;
};
int visit[10000]{};

int Solve(){
    int n = S;
    queue<QUE> q;
    q.push({S, 0});
    visit[S] = 1;
    
    while(!q.empty()){
        QUE cur = q.front(); q.pop();
        if(cur.val == E) return cur.time;
        for(int i=1000; i<9999; i++){
            if(visit[i] || !isPossible(cur.val, i)) continue;
            if(isPrime(i)){
                q.push({i, cur.time + 1});
                visit[i] = 1;
            }
        }
    }
    return 0;
}

int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}
