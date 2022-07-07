#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
#define MAXN ((int)5e5)
int N, K;
char str[MAXN + 10];

void InputData() {
	cin >> N >> K;
	cin >> str;
}

void Solve(){
    deque<char> dq;

    for(int i=0; i<N; i++){
        while(dq.size() && K && dq.front() < str[i]){
            dq.pop_front();
            K--;
        }
        dq.push_front(str[i]);
    }
    while(K--) {
        dq.pop_front();
    }
        

    while(!dq.empty()){
        cout << dq.back();
        dq.pop_back();
    }
    cout << "\n";
}

int main() {
	InputData();//입력 받는 부분

	//여기서부터 작성
    Solve();

	return 0;
}