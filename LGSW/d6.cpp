#include <iostream>
#include <algorithm>
using namespace std;
#define MAXW (20)
int N;//도로의 개수
int W;//사건의 개수
struct POS{
	int r, c;//세로, 가로
};
POS pos[MAXW+10];//사건 좌표

void InputData() {
	cin >> N;
	cin >> W;
	for (int i=0; i<W; i++){
		cin >> pos[i].r >> pos[i].c;
	}
}
int min_length = 2e9;
int path[MAXW+10]{};
void Solve(int depth, int length, int r1, int c1, int r2, int c2){
    if(depth == W){
        min_length = min(min_length, length);
        return;
    }
    Solve(depth + 1, length + abs(pos[depth].r - r1) + abs(pos[depth].c - c1), pos[depth].r, pos[depth].c, r2, c2);
    Solve(depth + 1, length + abs(pos[depth].r - r2) + abs(pos[depth].c - c2), r1, c1, pos[depth].r, pos[depth].c);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력받는 부분

	//여기서부터 작성
    Solve(0, 0, 1, 1, N, N);

	cout << min_length << "\n";//출력하는 부분
	return 0;
}