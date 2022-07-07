#include <iostream>
#include <vector>
using namespace std;

int N, P;
void InputData(){
    cin >> N >> P;
}

int Solve(){
    vector<int> v;
    v.push_back(N);
    
    int tmp = N;
    while(1){
        tmp = tmp * N % P;
        for(int i=0; i<v.size(); i++){
            if(v[i] == tmp){
                return v.size() - i;
            }
        }
        v.push_back(tmp);
    }
}

int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}