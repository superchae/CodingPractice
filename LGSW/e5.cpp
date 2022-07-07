#include <iostream>
#include <algorithm>
using namespace std;

int N;
int sm[100000+10];
int sd[100000+10];
int em[100000+10];
int ed[100000+10];
int month[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month_sum[15];
struct DATE{
    int s, e;
} flower[100000+10];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> sm[i] >> sd[i] >> em[i] >> ed[i];
    }
}
bool cmp(DATE a, DATE b){
    if(a.s < b.s) return true;
    return false;
}
int Solve(){
    //날짜로 나열
    for(int i=1; i<=12; i++){
        month_sum[i] = month_sum[i-1] + month[i];
    }
    for(int i=0; i<N; i++){
        flower[i].s = month_sum[sm[i] - 1] + sd[i];
        flower[i].e = month_sum[em[i] - 1] + ed[i];
        // cout << flower[i].s << ' ' << flower[i].e << endl;
    }

    sort(flower, flower + N, cmp);
    int gs = month_sum[3 - 1] + 1;
    int ge = month_sum[11 - 1] + 30;

    int sol = 0;
    int i = 0;
    int _max;
    for(int i=0; i<N; ){
        _max = 0;
        while(i < N && flower[i].s <= gs){
            if(flower[i].e > _max) _max = flower[i].e;
            i++;
        }
        if(_max <= gs) return 0;
        sol++;
        if(_max > ge) return sol;
        gs = _max;
    }
    return 0;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}
