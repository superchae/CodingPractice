#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e3)
int N;
int used[MAXN + 10];
vector<int> v;

void InputData(){
    cin >> N;
}

int Digit(int num){
    int next = 0;
    string str = to_string(num);
    for(int i=0; i<str.size(); i++){
        int tmp = str[i] - '0';
        next += tmp * tmp;
    }
    return next;
}

bool isOverlap(int num){
    for(int i=0; i<v.size(); i++){
        if(v[i] == num) return true;
    }
    return false;
}

int Solve(){
    for(int i=N; i>=1; i--){
        v.clear();
        int tmp = Digit(i);
        while(1){
            if(tmp == 1) return i;
            if(isOverlap(tmp)) break;
            v.push_back(tmp);
            tmp = Digit(tmp);
        }
    }
    return 1;
}

int main(){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}