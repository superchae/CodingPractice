#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int A, B, C, D;
bool visit[1000 + 10][1000 + 10];
struct QUE{
    int x, y, t;
};
queue<QUE> q;
void InputData() {
	cin >> A >> B >> C >> D;
}

QUE Work(QUE pre, int num){ //이전물통두개 이후물통두개
    QUE now;
    now.t = pre.t;
    if(num == 1){   //Fill x
        now.x = A;
        now.y = pre.y;
    }
    else if(num == 2){   //Fill y
        now.y = B;
        now.x = pre.x;
    }
    else if(num == 3){   //Empty x
        now.x = 0;
        now.y = pre.y;
    }
    else if(num == 4){   //Empty y
        now.y = 0;
        now.x = pre.x;
    }
    else if(num == 5){   //M(x, y)
        if(pre.x <= B - pre.y){
            now.x = 0;
            now.y = pre.y + pre.x;
        }
        else{
            now.y = B;
            now.x = pre.x - (B - pre.y);
        }
    }
    else if(num == 6){   //M(y, x)
        if(pre.y <= A - pre.x){
            now.y = 0;
            now.x = pre.x + pre.y;
        }
        else{
            now.x = A;
            now.y = pre.y - (A - pre.x);
        }
    }
    return now;
}
int Solve(){
    q.push({0, 0, 0});
    visit[0][0] = 1;
    while(!q.empty()){
        QUE pre = q.front(); q.pop();
        // cout << pre.t << ' ' << pre.x << ' ' << pre.y << endl;
        if(pre.x == C && pre.y == D){
            return pre.t;
        }
        QUE now;
        for(int i=1; i<=6; i++){
            now = Work(pre, i);
            if(now.x < 0 || now.y < 0 || now.x > A || now.y > B) continue;
            if(visit[now.x][now.y]) continue;
            visit[now.x][now.y] = 1;
            q.push({now.x, now.y, pre.t + 1});
        }
    }
    return -1;
}
int main() {
	int ans = -2;
	InputData();//입력받는 부분
	
	// 여기서부터 작성
    ans = Solve();

	cout << ans << "\n";// 출력하는 부분
	return 0;
}