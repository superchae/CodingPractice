#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_SIZE (30)

int L, R, C;
char map[MAX_SIZE+10][MAX_SIZE+10][MAX_SIZE+10];

int dl[6] = {-1, 1, 0, 0, 0, 0};
int dr[6] = {0, 0, -1, 1, 0, 0};
int dc[6] = {0, 0, 0, 0, -1, 1};
struct QUE{
    int l, r, c, time;
};

QUE startPoint, endPoint;
bool visit[MAX_SIZE+10][MAX_SIZE+10][MAX_SIZE+10];

bool InputData(){
    cin >> L >> R >> C;
    if ((L == 0) && (R == 0) && (C == 0)) return false;
    for (int l=0; l<L;l++){
        for (int r=0; r<R; r++){
            cin >> map[l][r];
            for(int c=0; c<C; c++){
                if(map[l][r][c] == 'S') {
                    startPoint = {l, r, c, 0};
                }
                else if(map[l][r][c] == 'E'){
                    endPoint = {l, r, c, 0};
                }
            }
        }
    }
    return true;
}

int Solve(){
    fill(&visit[0][0][0], &visit[MAX_SIZE+9][MAX_SIZE+9][MAX_SIZE+10], false);
    queue<QUE> q;
    q.push({startPoint.l, startPoint.r, startPoint.c, 0});
    visit[startPoint.l][startPoint.r][startPoint.c] = true;

    while(!q.empty()){
        QUE cur = q.front(); q.pop();
        if(cur.l == endPoint.l && cur.r == endPoint.r && cur.c == endPoint.c){
            return cur.time;
        }
        for(int i=0; i<6; i++){
            int nl = cur.l + dl[i];
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if(nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(map[nl][nr][nc] == '#' || visit[nl][nr][nc]) continue;
            q.push({nl, nr, nc, cur.time + 1});
            visit[nl][nr][nc] = true;
        }
    }
    return -1;
}
int main(){
    int ans = -1;
    while(InputData()){

        //여기서부터 작성
        ans = Solve();

        if (ans == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    }
    return 0;
}