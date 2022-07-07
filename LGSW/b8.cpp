#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int N;
char A[20000+10];
vector<int> arr[51];
void InputData(){
    cin >> N >> A;
}

void Solve(){
    int len = strlen(A);
    string tmp = "";
    int depth = 0;

    for(int i=0; i<len; i++){
        if(A[i] == '<'){
            if(tmp.size()) arr[depth].push_back(stoi(tmp));
            depth++;
            tmp = "";
        }
        else if(A[i] == '>'){
            if(tmp.size()) arr[depth].push_back(stoi(tmp));
            depth--;
            tmp = "";
        }
        else{
            tmp += int(A[i]);
        }
    }
}

int main (){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    Solve();
    for(auto elm: arr[N]){
        cout << elm << ' ';
    }

    return 0;
}