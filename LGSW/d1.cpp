#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int map[110][110];
int visit[110];
int pre[110]{};
queue<int> q;
vector<int> path;

void InputData(){
    cin >> N >> M;
    int a, b, l;
    for (int i = 0; i<M; i++){
        cin >> a >> b >> l;
        map[a][b] = l;
        map[b][a] = l;
    }
}

int BFS(){
    q.push(1);
    visit[1] = 0;
    pre[1] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == N) continue;
        for(int i=1; i<=N; i++){
            if(map[cur][i] == 2e9) continue;
            if(visit[i] > visit[cur] + map[cur][i]){
                visit[i] = visit[cur] + map[cur][i];
                q.push(i);
                pre[i] = cur;
            }
        }
    }
    return visit[N];
}


void PRE(int n){
    path.push_back(n);
    if(n == 1){
        return;
    }
    PRE(pre[n]);
}

int Solve(){
    int org_dist, tmp_dist;
    int diff_max = 0;

    org_dist = BFS();
    PRE(N);
    
    for(int i=0; i < path.size() - 1; i++){
        fill(&visit[0], &visit[110], 2e9);
        fill(&pre[0], &pre[110], 0);
        map[path[i+1]][path[i]] = map[path[i]][path[i+1]] = map[path[i]][path[i+1]] * 2;

        tmp_dist = BFS();
        if(tmp_dist > org_dist){
            diff_max = max(diff_max, tmp_dist - org_dist);
        }

        map[path[i+1]][path[i]] = map[path[i]][path[i+1]] = map[path[i]][path[i+1]] / 2;
    }
    return diff_max;
}

int main(){
    int ans = -1;
    
    fill(&map[0][0], &map[109][110], 2e9);
    fill(&visit[0], &visit[109], 2e9);
    
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}