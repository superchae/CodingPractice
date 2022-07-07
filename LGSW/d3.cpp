#include <iostream>
using namespace std;

#define MAXN (10)
int N;
int cost[MAXN+10][MAXN+10];
int solpath[MAXN+10];//답 경로
int sol = 2e9;
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> cost[i][j];
        }
    }
}

int used[MAXN+10]{};
int path[MAXN+10];
void Solve(int depth, int sum){
    if(depth == N){
        if(sol > sum){
            sol = sum;
            for(int i=0; i<N; i++){
                solpath[i] = path[i];
            }
        }
        return;
    }
    for(int i=0; i<N; i++){
        if(used[i]) continue;
        if(sol <= sum + cost[depth][i]) continue;
        used[i] = 1;
        path[depth] = i + 1;
        Solve(depth + 1, sum + cost[depth][i]);
        used[i] = 0;
    }
}
void OutputData(int sol){
    cout << sol << endl;
    for (int i=0; i<N; i++){
        cout << solpath[i] << " ";
    }
    cout << endl;
}
int main(){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 
    Solve(0, 0);
    ans = sol;

    OutputData(ans);//출력하는 부분
    return 0;
}