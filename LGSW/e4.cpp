#include <iostream>
#include <algorithm>
using namespace std;
//북1 남2 서3 동4
int w, h, n;
int dir[100+10];
int len[100+10];

void InputData(){
    cin >> w >> h;
    cin >> n;
    for (int i=0; i<=n; i++){
        cin >> dir[i] >> len[i];
    }
}

int Solve(){
    int res = 0;
    for(int i=0; i<n; i++){
        if(dir[n] == 1){ //북
            if(dir[i] == 1){
                res += abs(len[i] - len[n]);
            }
            else if(dir[i] == 2){
                res += h + min(len[i] + len[n], w + w - len[i] - len[n]);
            }
            else if(dir[i] == 3){
                res += len[n] + len[i];
            }
            else if(dir[i] == 4){
                res += w - len[n] + len[i];
            }
        }
        else if(dir[n] == 2){ //남
            if(dir[i] == 1){
                res += h + min(len[i] + len[n], w + w - len[i] - len[n]);
            }
            else if(dir[i] == 2){
                res += abs(len[i] - len[n]);
            }
            else if(dir[i] == 3){   //서
                res += len[n] + h - len[i];
            }
            else if(dir[i] == 4){   //동
                res += w - len[n] + h - len[i];
            }
        }
        else if(dir[n] == 3){   //서
            if(dir[i] == 1){
                res += len[n] + len[i];
            }
            else if(dir[i] == 2){ //남
                res += h - len[n] + len[i];
            }
            else if(dir[i] == 3){
                res += abs(len[i] - len[n]);
            }
            else if(dir[i] == 4){
                res += w + min(len[i] + len[n], h + h - len[i] - len[n]);
            }
        }
        else if(dir[n] == 4){
            if(dir[i] == 1){
                res += len[n] + w - len[i];
            }
            else if(dir[i] == 2){
                res += h - len[n] + w - len[i];
            }
            else if(dir[i] == 3){
                res += w + min(len[i] + len[n], h + h - len[i] - len[n]);
            }
            else if(dir[i] == 4){
                res += abs(len[i] - len[n]);
            }
        }
    }
    return res;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}