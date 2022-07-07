#include <iostream>
using namespace std;

int A[5+10][5+10];
int B[25+10];
void InputData(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> A[i][j];
        }
    }
    for (int i=0; i<25; i++){
        cin >> B[i];
    }
}

int Bingo(){
    int bingo = 0;
    int cnt;
    //가로
    for(int i=0; i<5; i++){
        cnt = 0;
        for(int j=0; j<5; j++){
            if(A[i][j] == 0) cnt++;
        }
        if(cnt == 5) bingo++;
    }

    //세로
    for(int j=0; j<5; j++){
        cnt=0;
        for(int i=0; i<5; i++){
            if(A[i][j] == 0) cnt++;
        }
        if(cnt == 5) bingo++;
    }

    //대각선1
    cnt = 0;
    for(int i=0; i<5; i++){
        if(A[i][i] == 0) cnt++;
    }
    if(cnt == 5) bingo++;

    //대각선2
    cnt = 0;
    for(int i=0; i<5; i++){
        if(A[4-i][i] == 0) cnt++;
    }
    if(cnt == 5) bingo++;
    
    return bingo;
}

int Solve(){
    for(int i=0; i<25; i++){
        for(int a=0; a<5; a++){
            for(int b=0; b<5; b++){
                if(A[a][b] == B[i]){
                    A[a][b] = 0;
                    break;
                }
            }
        }
        if(Bingo() >= 3) 
            return i + 1;
    }
    return 25;
}

int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}