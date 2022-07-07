#include <iostream>
#include <queue>
using namespace std;
#define MAXN (50)
int R, C;//지도 세로, 가로 크기
char map[MAXN+10][MAXN+10];

struct QUE{
    char name;
    int r, c, t;
};
queue<QUE> q;
int sr, sc;
int visit[MAXN+10][MAXN+10]{};
int dr[4] = {0,0,-1,1};
int dc[4] = {-1,1,0,0};

void InputData(){
    cin >> R >> C;
    for (int i=0; i<R; i++){
        cin >> map[i];
        for(int j=0; j<C; j++){
            if(map[i][j] == 'S'){
                sr = i;
                sc = j;
            }
            if(map[i][j] == '*'){
                q.push({'*', i, j, 0});
            }
        }
    }
}

int Solve(){
    fill(&visit[0][0], &visit[MAXN+9][MAXN+10], 0);  //memset
    q.push({'S', sr, sc, 0});
    visit[sr][sc] = 1;
    
    while(!q.empty()){
        QUE cur = q.front(); q.pop();
        if(map[cur.r][cur.c] == 'D') return cur.t;
        for(int i=0; i<4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if(cur.name == '*'){
                if(map[nr][nc] == '.') {
                    q.push({'*', nr, nc, 0});
                    map[nr][nc] = '*';
                }
            }
            if(cur.name == 'S'){
                if(visit[nr][nc]) continue;
                if(map[nr][nc] == '.' || map[nr][nc] == 'D'){
                    q.push({'S', nr, nc, cur.t + 1});
                    visit[nr][nc] = 1;
                }
            }
        }
    }
    return -1;
}
int main(){
    int T, ans = -1;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        while(!q.empty()) q.pop();
        InputData();//입력 받는 부분
        // 여기서부터 작성
        ans = Solve();

        if (ans == -1) cout << "KAKTUS" << endl;//출력 하는 부분
        else cout << ans << endl;
    }
    return 0;
}