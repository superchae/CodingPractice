#include <iostream>

using namespace std;
int N;//색종이 수
int X[100+10];
int Y[100+10];
int map[100+10][100+10]{0};

void InputData() {
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];

        for(int j=Y[i]; j<Y[i]+10; j++){
            for(int k=X[i]; k<X[i]+10; k++){
                map[j][k] = 1;
            }
        }
    }
}

int sol = 100;
void Solve(int sr, int sc, int er, int ec){
    int tmp = 0;
    for(int i=sr; i <=er; i++){
        for(int j=sc; j<=ec; j++){
            if(map[i][j] == 0) return;
            tmp++;
        }
    }
    sol = max(sol, tmp);
    // cout << sr << ' ' << sc << ' ' << er << ' ' << ec << ' ' << sol << endl; 
    
}



int main() {
    InputData();//입력받는 부분

    //여기서부터 작성
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            for(int k = i + 1; k < 100; k++){
                for(int l = j + 1; l < 100; l++){
                    if(map[i][j] == 1) Solve(i, j, k, l); 
                }
            }
        }
    }

    cout << sol << endl;//출력하는 부분
    return 0;
}
