#include <iostream>
#include <algorithm>
using namespace std;
int W;//사용할 금액
int A[6];//각 동전 개수(갖고 있는)
int sol[6];//답
int coin[6] = {500, 100, 50, 10, 5, 1};
int max_cnt = 0;
int tmp[6];


void InputData(){
	cin >> W;
	for (int i=0; i<6; i++){
		cin >> A[i];
	}
}
void OutputData(int ans){
	cout << ans << "\n";
	for (int i=0; i<6; i++){
		cout << sol[i] << " ";
	}
	cout << "\n";
}

bool isPossible(int s, int left, int cnt){
    int _sum = 0;
    int usable = 0;
    for(int i=s; i<6; i++){
        _sum += A[i] * coin[i];
        usable += A[i];
    }
    // cout << "// "<< s << ' ' << left << ' ' << _sum << endl;
    if(cnt + usable <= max_cnt) return false;
    if(left <= _sum) return true;
    return false;
}

void Solve(int s, int left, int cnt){
    if(left == 0){
        if(cnt > max_cnt){
            max_cnt = cnt;
            for(int i=0; i<6; i++){
                sol[i] = tmp[i];
            }
        }
        return;
    }
    if(s >= 6) return;
    if(isPossible(s, left, cnt) == false) return;

    if(left < coin[s]) Solve(s + 1, left, cnt);
    int quot = min(left / coin[s], A[s]);
    for(int q = 0; q <= quot; q++){ 
        tmp[s] = q;
        Solve(s + 1, left - q * coin[s], cnt + q);
    }

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;

	InputData();//입력받는 부분

	//여기서부터 작성
    Solve(0, W, 0);

	OutputData(max_cnt);//출력하는 부분
	return 0;
}