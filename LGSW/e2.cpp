#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAXN (100)
int N;
int K;
int R[MAXN+10];
int C[MAXN+10];
int L;
int X[MAXN+10];
char CMD[MAXN+10];
int map[MAXN+10][MAXN+10]; // 빈칸0, 뱀1, 과일2
struct QUE{
    int r, c;
};
struct SNAKE{
    int r, c, d;    //북0, 동1, 남2, 서3
};
queue<QUE> q;

// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void InputData(){
    cin >> N;
    cin >> K;
    for (int i=0; i<K; i++){    //과일
        cin >> R[i] >> C[i];
        map[R[i]][C[i]] = 2;
    }
    cin >> L;
    for (int i=0; i<L; i++){    //이동
        cin >> X[i] >> CMD[i];  //초, 방향
    }
}

int Solve(){
    q.push({1, 1});
    map[1][1] = 1;
    SNAKE head = {1, 1, 1};
    int time = 1;
    int cmd_cnt = 0;

    while(1){
        int nr = head.r + dr[head.d];
        int nc = head.c + dc[head.d];
        // cout << time << "-> "  << nr << ' ' << nc << ' ' << head.d << ' ' << map[nr][nc] << endl;
        if(nr < 1 || nr > N || nc < 1 || nc > N) break;
        if(map[nr][nc] == 1) break; //뱀 몸
        if(map[nr][nc] == 0){ //빈 칸
            QUE tail = q.front();
            map[tail.r][tail.c] = 0;
            q.pop();
        }
        // 빈칸 또는 과일
        head.r = nr;
        head.c = nc;
        q.push({nr, nc});
        map[nr][nc] = 1;

        if(X[cmd_cnt] == time++){
            if(CMD[cmd_cnt] == 'L') head.d = (head.d + 3) % 4;
            else head.d = (head.d + 1) % 4;
            cmd_cnt++;
        }
    }
    return time;
}

int main(){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 작성
    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}
