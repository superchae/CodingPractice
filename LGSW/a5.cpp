#include <iostream>
#include <string>
using namespace std;
int N;//빌딩의 층수
int digit[10] = {0,1,2,3,0,4,5,6,7,8};
void InputData(){
    cin >> N;
}

int Solve(){
    string str = to_string(N);
    int sol = 0;
    int len = str.size();
    int num, square = 1;
    for(int i=len - 1; i>=0; i--){
        num = str[i] - '0';
        sol += digit[num] * square;
        square *= 9;
    }
    return sol;
}

int main(){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}