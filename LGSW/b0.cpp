#include <iostream>
#include <cstring>
using namespace std;

char str[100000+10];
void InputData(){
    cin >> str;
}

int Solve(){
    int N = strlen(str);
    int open = 0;
    int change = 0;

    for(int i=0; i<N; i++){
        if(str[i] == '('){
            open++;
        }
        if(str[i] == ')'){
            if(open > 0) open--;
            else{
                change++;
                open++;
            }
        }
    }
    return change + open/2;
    
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();
    cout << ans << endl;// 출력하는 부분
    return 0;
}