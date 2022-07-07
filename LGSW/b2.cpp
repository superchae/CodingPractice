#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int id, s, e;
};

bool cmp(Node a, Node b){
    return a.e < b.e;
};

int N;
int id, s, e;
vector<Node> v;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> id >> s >> e;
        v.push_back({id, s, e});
    }
    sort(v.begin(), v.end(), cmp);
}

void Solve(){
    int end = 0;
    vector<int> numv;

    for(auto elm: v){
        if(elm.s >= end){
            numv.push_back(elm.id);
            end = elm.e;
        }
    }
    cout << numv.size() << endl;
    for(auto elm: numv){
        cout << elm << ' ';
    }
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    //여기서부터 작성
    
    Solve();

    return 0;
}