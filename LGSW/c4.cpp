#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN (100)
int W, H;//지도의 가로 세로 크기
char map[MAXN+10][MAXN+10];//지도 정보('1':저글링, '0':빈곳)
int sw, sh;//시작위치 가로 세로 좌표
void InputData(){
    cin >> W >> H;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
    cin >> sw >> sh;    //가로 세로
}

struct QUE{
    int r, c, t;
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void Solve(){
    queue<QUE> q;
    int sol_time = 0;
    int sol_cnt = 0;

    q.push({sh, sw, 3});
    map[sh][sw] = '0';
    while(!q.empty()){
        QUE cur = q.front(); q.pop();
        sol_time = max(sol_time, cur.t);
        for(int i=0; i<4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if(nr < 1 || nc < 1 || nr > H || nc > W || map[nr][nc] == '0')
                continue;
            q.push({nr, nc, cur.t + 1});
            map[nr][nc] = '0';
        }
    }

    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if(map[i][j] == '1') sol_cnt++;
        }
    }
    
    cout << sol_time << "\n" << sol_cnt << "\n";
}
int main(){
    InputData();//입력 받는 부분

    //여기서부터 작성
    Solve();

    return 0;
}
