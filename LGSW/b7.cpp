#include <iostream>
#include <cstring>
using namespace std;

char str[100000+10];
void InputData(){
    cin >> str;
}

int Solve(){
    int open = 0, close = 0, depth = 0;
    int N = strlen(str);
    if(str[0] == ')' || str[N - 1] == '(') return 1;
    for(int i=0; i<N; i++){
        if(str[i] == '('){
            depth++;
            open++;
        }
        else{
            depth--;
            close++;
        } 
        if(depth == 1) open = 0;
        if(depth < 0) return close;
    }
    return open;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();


    cout << ans << endl;// 출력하는 부분
    return 0;
}