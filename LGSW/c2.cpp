#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
int N;//개수
int F[MAXN + 10];
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> F[i];
    }
}
 
long long Solve(){
    sort(F, F + N);

    int ps = 0, pe = 0;
    long long sol = 0;
    
    while(pe < N - 1){
        pe++;
        while(ps < pe && (double) F[ps] < (double) F[pe] * 0.9){
            ps++;
        }
        // cout << F[pe] << ' ' << pe - ps << endl;
        sol += pe - ps;
    }
    return sol;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long ans = -1;
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    ans = Solve();
 
    cout << ans << "\n";// 출력하는 부분
    return 0;
}