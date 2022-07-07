#include <iostream>
#include <queue>
using namespace std;

int N;
int A[100+10];
int B[100+10];
int map[100+10][100+10]{};
int visit[100+10][100+10]{};

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i]; // 열번호, 높이
        for(int a = A[i]; a < A[i] + 10; a++){
            for(int b = B[i]; b < B[i] + 10; b++){
                map[a][b] = 1;
            }
        }
    }
}

struct QUE{
    int c, r;
};
int dc[4] = {0, 0, -1, 1};
int dr[4] = {-1, 1, 0, 0};

int Solve(int x, int y){
    queue<QUE> q;
    int sol = 0;

    q.push({x, y});
    visit[x][y] = 1;
    
    while(!q.empty()){
        QUE cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nc = cur.c + dc[i];
            int nr = cur.r + dr[i];
            if(nc < 0 || nr < 0 || nc > 100 || nr > 100 || visit[nc][nr]) continue;
            sol += map[nc][nr];
            if(map[nc][nr] == 0){
                visit[nc][nr] = 1;  
                q.push({nc, nr});
            }
        }
    }
    return sol;
}

int main(){
    int ans = 0;

    InputData();// 입력받는 부분
    int num;
    // 여기서부터 작성
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(visit[i][j] == 0 && map[i][j] == 0) {
                ans += Solve(i, j);
            }
        }
    }

    cout << ans << endl;// 출력하는 부분
    return 0;
}