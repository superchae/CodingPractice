#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (9)
int sudoku[MAXN][MAXN];
int used_r[MAXN][MAXN + 1];
int used_c[MAXN][MAXN + 1];
int used_box[MAXN][MAXN + 1];
struct POS{
    int r, c;
} zeros[90];
int zero_cnt{0};

void InputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cin >> sudoku[r][c];
        }
    }
}
void OutputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cout << sudoku[r][c] << " ";
        }
        cout << endl;
    }
}
int flag = 0;
void Recursive(int depth){
    if(flag) return;
    if(depth == zero_cnt){
        OutputData();
        flag = 1;
        return;
    }
    int r = zeros[depth].r;
    int c = zeros[depth].c;
    for(int i=1; i<=9; i++){
        if(used_r[r][i] || used_c[c][i] || used_box[r/3*3+c/3][i]) continue;
        used_r[r][i] = 1;
        used_c[c][i] = 1;
        used_box[r/3*3+c/3][i] = 1;
        sudoku[r][c] = i;
        Recursive(depth + 1);
        used_r[r][i] = 0;
        used_c[c][i] = 0;
        used_box[r/3*3+c/3][i] = 0;
        sudoku[r][c] = 0;
    }
    
}
void Solve(){
    for(int r=0; r<MAXN; r++){
        for(int c=0; c<MAXN; c++){
            if(sudoku[r][c] == 0){
                zeros[zero_cnt++] = {r, c};
            }
            else{
                used_r[r][sudoku[r][c]] = 1;
                used_c[c][sudoku[r][c]] = 1;
                used_box[r / 3 * 3 + c / 3][sudoku[r][c]] = 1;
            }
        }
    }

    Recursive(0);
}
int main(){
    InputData();//입력받는 부분

    //여기서부터 작성
    Solve();

    // OutputData();//출력하는 부분
    return 0;
}
