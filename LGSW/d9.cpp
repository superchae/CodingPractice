#include <iostream>
#include <algorithm>
using namespace std;
#define MAXH (5)
#define MAXW (9)
char map[MAXH+2][MAXW+2];
int solremain, solmove;

int pin_cnt;
int die[8];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void InputData(){
    for (int h=1; h<=MAXH; h++){
        cin >> &map[h][1];
    }
}

void Recursive(int n){
    int zero_cnt = 0;
    for (int h=1; h<=MAXH; h++){
        for(int w=1; w<=MAXW; w++){
            if(map[h][w] == 'o'){
                zero_cnt++;
            }
        }
    }
    if(solremain >= zero_cnt){
        solremain = zero_cnt;
        solmove = n;
    }

    for (int h=1; h<=MAXH; h++){
        for(int w=1; w<=MAXW; w++){
            if(map[h][w] == 'o'){
                int r = h;
                int c = w;
                for(int j=0; j<4; j++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    int nrr = nr + dr[j];
                    int ncc = nc + dc[j];
                    
                    if(nr < 1 || nc < 1 || nr > MAXH || nc > MAXW) continue;
                    if(nrr < 1 || ncc < 1 || nrr > MAXH || ncc > MAXW) continue;
                    if(map[nr][nc] == 'o' && map[nrr][ncc] == '.'){
                        map[r][c] = '.';
                        map[nr][nc] = '.';
                        map[nrr][ncc] = 'o';
                        Recursive(n + 1);
                        map[r][c] = 'o';
                        map[nr][nc] = 'o';
                        map[nrr][ncc] = '.';
                    }
                }
            }
        }
    }
}

void Solve(){
    solremain = 2e9;
    solmove = 2e9;
    pin_cnt = 0;
    
    Recursive(0);
}

int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        Solve();

        cout << solremain << " " << solmove << endl;//출력하는 부분
    }
    return 0;
}