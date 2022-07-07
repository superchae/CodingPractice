#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN (102)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];

void InputData(){
    cin >> N;
    cin >> eh >> ew;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cin >> map[h][w];
        }
    }
}
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
struct QUE{
    int r, c;
};
queue<QUE> q;
int visited[MAXN][MAXN];

int Solve(){
    fill(&visited[0][0], &visited[MAXN - 1][MAXN], 1e9);
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            if(h == 1 || w == 1 || h == N || w == N) {
                visited[h][w] = map[h][w] * map[h][w];
                q.push({h, w});
            }
        }
    }
    while(!q.empty()){
        QUE cur = q.front(); q.pop();
        if(cur.r == eh && cur.c == ew) continue;
        for(int i=0; i<4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if(nr < 1 || nc < 1 || nr > N || nc > N) continue;
            
            int npower;
            // 1. 수평이동
            if(map[nr][nc] == map[cur.r][cur.c]){
                npower = 0;
            }
            // 2. 내리막길
            else if(map[nr][nc] < map[cur.r][cur.c]){
                npower = map[cur.r][cur.c] - map[nr][nc];
            }
            // 3. 오르막길
            else{
                int tmp = map[nr][nc] - map[cur.r][cur.c];
                npower = tmp * tmp;
            }
            if(visited[nr][nc] > visited[cur.r][cur.c] + npower){
                visited[nr][nc] = visited[cur.r][cur.c] + npower;
                q.push({nr, nc});
            }
        }
    }
    return visited[eh][ew];
}
int main(){
    int ans = -1;
    InputData();//입력 받는 부분

    //여기서부터 작성
    ans = Solve();
    cout << ans << endl;//출력하는 부분
    return 0;
}