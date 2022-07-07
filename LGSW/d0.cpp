#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int P;
char farm;
int sol;
int map[60][60];
int visit[60];
queue<int> q;

void InputData(){
    fill(&map[0][0], &map[59][60], 2e9);
    fill(&visit[0], &visit[60], 2e9);
    cin >> P;
    char a, b;
    int l;
    for (int i=0; i<P; i++){
        cin >> a >> b >> l;
        if(a >= 'a' && a <= 'z') a = a - 'a' + 26;
        if(b >= 'a' && b <= 'z') b = b - 'a' + 26;
        if(a >= 'A' && a <= 'Z') a = a - 'A';
        if(b >= 'A' && b <= 'Z') b = b - 'A'; 
        map[b][a] = map[a][b] = min(map[a][b], l);
    }
}

void Solve(){
    //'Z' (25)
    q.push(25);
    visit[25] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i=0; i<60; i++){
            if(map[cur][i] == 2e9) continue;
            if(visit[i] > visit[cur] + map[cur][i]){
                visit[i] = visit[cur] + map[cur][i];
                q.push(i);
            }
        }
    }
    farm = 'Z';
    sol = 2e9;

    for(int i=0; i<25; i++){
        if(sol > visit[i]){
            farm = i + 'A';
            sol = visit[i];
        }
    }
}

int main(){
    InputData();// 입력받는 부분
    // 여기서부터 작성
    Solve();

    cout << farm << " " << sol << endl;// 출력하는 부분
    return 0;
}