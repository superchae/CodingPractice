#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXNM ((int)1e5)
int N, M;//소마리수, 잔디구간 개수
 
struct GRASS{
    long long a, b;  //잔디 시작, 잔디 끝
};
 
GRASS A[MAXNM+10];//잔디 A[], B[]
 
void InputData(){
    cin >> N >> M;
    long long x, y;
    for (int i=0 ; i<M ; i++){
        cin >> x >> y;
        A[i] = {x, y};  //시작, 끝 잔디위치
    }
}
 
bool cmp(GRASS x, GRASS y){
    return x.a < y.a;
}
 
bool isPossible(long long dist){  //간격
    int cow = N - 1;
    int grass = 0;
    long long position = A[0].a;
    for(int i = 1; i < N; i++){     //소
        position = position + dist;
        while(position > A[grass].b){
            grass++;
        }
        if(position < A[grass].a) position = A[grass].a;  //   0000100__x___p1000______
        if(grass >= M || position > A[M-1].b) return false;
    }
    return true;
}
 
long long Solve(){
    sort(A, A + M, cmp);
 
    long long s = 1, e = A[M - 1].b;
    long long m, sol = -1;
    while(s <= e){
        m = (s + e)/2;
        if(isPossible(m)){  //간격
            sol = m;
            s = m + 1;
        }
        else{
            e = m - 1;
        }
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