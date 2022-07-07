#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
int N;//영화수
struct DATA{
    int s, e;
};
DATA A[MAXN + 10];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}
bool cmp(DATA a, DATA b){
    return a.e < b.e;
}

int Solve(){
    int cnt = 0;
    sort(A, A + N, cmp);
    
    int end = 0;
    for(int i=0; i<N; i++){
        if(A[i].e - A[i].s < 2) continue;
        if(A[i].s >= end){
            cnt++;
            end = A[i].e;            
        }
    }
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	//여기서부터 작성
    ans = Solve();


	cout << ans << "\n";//출력하는 부분
	return 0;
} 