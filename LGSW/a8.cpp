#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S[10010];
int used[10010]{};

void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> S[i];
    }
}

void Solve(){
    int flag = 0;
    for(int i=1; i<=N;i++){
        vector<int> v;
        if(used[i] == 1) continue;
        v.push_back(i);
        used[i] = 1;

        for(int j=i+1; j<=N; j++){
            if(S[i] == S[j] && used[j] == 0){
                used[j] = 1;
                v.push_back(j);
            }
        }
        if(v.size() > 1) {
            cout << S[i] << ' ';
            flag = 1;
        
            for(auto elm: v) cout << elm << ' ';
            cout << endl;
        }
    }
    if(flag == 0) cout << "unique" << endl;
}
int main(){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    Solve();
    return 0;
}