#include <iostream>
#include <vector>
using namespace std;
char map[5][10];
char arr[13]{0};
int used[13]{0,};
int isEmpty[13]{};
vector<vector<int>> check = {{1,3,6,8}, {1,4,7,11}, {8,9,10,11},
                                {2,3,4,5}, {2,6,9,12}, {5,7,10,12}};

void InputData(){
    int cnt = 0;
	for (int h=0; h<5; h++){
		cin >> map[h];
        for(int w=0; w<9; w++){
            if(map[h][w] != '.'){
                arr[++cnt] = map[h][w];
                if(map[h][w] != 'x'){
                    used[map[h][w] - 'A' + 1] = 1;
                }
                else{
                    isEmpty[cnt] = 1;
                }
            }
        }
	}
}

bool isPossible(void){
    for(auto elm: check){
        int _sum = 0;
        for(auto e: elm){
            _sum += arr[e] - 'A' + 1;
        }
        if(_sum != 26) return false;
    }
    return true;
}

bool flag = 0;
void Solve(int depth){
    if(depth > 12){
        if(flag==0 && isPossible()){
            int cnt = 1;
            for (int h=0; h<5; h++){
                for(int w=0; w<9; w++){
                    if(map[h][w] != '.') map[h][w] = arr[cnt++];
                }
            }
            flag = 1;
        }
        return;
    }
    if(flag) return;
    if(isEmpty[depth] == 0) Solve(depth + 1);
    else{
        for(int i=1; i<=12; i++){
            if(!used[i]){
                used[i] = 1;
                arr[depth] = i + 'A' - 1;
                Solve(depth + 1);
                used[i] = 0;
            }
        }
    }
}

void OutputData(){
	for (int h=0; h<5; h++){
		cout << map[h] << endl;
	}
}
int main(){
	InputData();//입력받는 부분

	//여기서부터 작성
    Solve(0);

	OutputData();//출력하는 부분
	return 0;
}