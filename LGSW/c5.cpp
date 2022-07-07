#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN (15)
int R, C;//게임판 행(세로), 열(가로) 크기
char map[MAXN+5][MAXN+5];//게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)
int _rr, _rc, _br, _bc, _hr, _hc;

void InputData(){
	cin >> R >> C;
	for (int i=0; i<R; i++){
		cin >> map[i];
        for(int j=0; j<C; j++){
            if(map[i][j] == 'R'){
                _rr = i;
                _rc = j;
            }
            else if(map[i][j] == 'B'){
                _br = i;
                _bc = j;
            }
            else if(map[i][j] == 'H'){
                _hr = i;
                _hc = j;
            }
        }
	}
}


int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

struct QUE{
    int rr, rc, br, bc, t;
};
char visit[MAXN+5][MAXN+5][MAXN+5][MAXN+5];

int Solve(){
    fill(&visit[0][0][0][0], &visit[MAXN+4][MAXN+4][MAXN+4][MAXN+5], '0');
    queue<QUE> q;
    q.push({_rr, _rc, _br, _bc, 0});
    visit[_rr][_rc][_br][_bc] = '1';

    while(!q.empty()){
        QUE cur = q.front(); q.pop();
        
        //rule 2, 7
        if(cur.t > 10) break;

        //rule 5
        if(cur.rr == cur.br && cur.rc == cur.bc) continue;

        //rule 6
        if(cur.br == _hr && cur.bc == _hc) continue;

        //rule 8, 9
        if(cur.rr == _hr && cur.rc == _hc) return cur.t;

        for(int i = 0; i < 4; i++){
            int nrr = cur.rr + dr[i];
            int nrc = cur.rc + dc[i];
            int nbr = cur.br + dr[i];
            int nbc = cur.bc + dc[i];

            //rule 4
            if(map[nrr][nrc] == '#'){
                nrr = cur.rr;
                nrc = cur.rc;
            }
            
            if(map[nbr][nbc] == '#'){
                nbr = cur.br;
                nbc = cur.bc;
            }

            if(visit[nrr][nrc][nbr][nbc] == '1') continue;
            q.push({nrr, nrc, nbr, nbc, cur.t + 1});
            visit[nrr][nrc][nbr][nbc] = '1';
        }
    }
    return -1;
}   

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, ans=-10;
	cin >> T;
	for (int i=0; i<T; i++){
		InputData();//입력

		//여기서부터 작성
        ans = Solve();
		cout << ans << "\n";//출력
	}
	return 0;
}